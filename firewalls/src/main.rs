mod fw_struct;
use fw_struct::FirewallConfig;

use std::thread;
use std::fs::File;
use std::io::BufReader;
use serde_json::Result as JsonResult;
use clap::{Arg, Command as ClapCommand};
use std::process::Command as StdCommand;


/**
 *      [ Kelompok 2 ]
 *      Member:
 *          - Ferry Salim (20214350xxxx)
 *          - Amelia Azra Pakaya (20214350xxxx)
 *          - Rionggo Rahardi (20214350xxxx)
 *          - Siti Mawaddah (20214350xxxx)
 *          - Al-Fariqy Raihan Azhwar (20214350xxxx)
 */





// -- [ RIO ] --

/**
 *  Function: execute_firewall_command
 *  Keterngan: 
 *      Function execute_firewall_command ini berfungsi untuk menjalankan
 *      perintah atau command dari powershell yang di dalam nya 
 *      menjalankan command windows firewall (WF).
 */
fn execute_firewall_command(display_name: String, command: String, success_msg: &str, fail_msg: &str) -> () {
    let output = StdCommand::new("powershell")
        .arg("-Command")
        .arg(command)
        .output()
        .expect("failed to execute command");

    if output.status.success() {
        println!("[ {} ]: {}", success_msg, display_name);
    } else {
        eprintln!(
            "[ {} FAILED ]: {}. err: {}",
            fail_msg, display_name,
            String::from_utf8_lossy(&output.stderr)
        );
    }
}


fn main() -> JsonResult<()> {
    let matches = ClapCommand::new("firewall")
        .version("1.0-FVCK")
        .author("MR. QYWOK <alfariqyraihan@gmail.com>")
        .about("manages windows firewall rules")

        // Membuat command line argument / flag dengan nama "rules"
        // yg nanti nya di isi dengan file json yang berisi rules firewall
        .arg(Arg::new("rules")
            .short('r')
            .long("rules")
            .value_name("FILE")
            .required(true)
            .help("path to the firewall rules json file"))
        .get_matches();

    // variable rules_file ini fungsi -nya mem- parsing argument
    // vector atau flag value yang didapatkan dari terminal.

    // misalnya: --rules rules/tcp_inbound_allow.json
    // berarti yg diambil cma rules/tcp_inbound_allow.json -nya aja
    let rules_file = matches.get_one::<String>("rules")
        .expect("rules file is required");

    // membaca isi dari rules/tcp_inbound_allow.json
    let file = File::open(rules_file).expect("fail to open file");
    let reader = BufReader::new(file);

    // mem- parsing isi dari rules/tcp_inbound_allow.json
    let config: FirewallConfig = serde_json::from_reader(reader)
        .expect("error while reading or parsing");

    // variabel handles ini adalah vector kosong, yang nanti -nya bakalan
    // nampung thread yang lagi jalan.
    let mut handles: Vec<thread::JoinHandle<()>> = vec![];

    // melakukan automation pada firewall rules dengan melakukan for loop
    for rule in config.rules.iter() {
        let display_name = rule.display_name.clone();

        // kalo action isi nya itu "Drop", maka akan
        // menjalankan command powershell Remove-NetFirewallRule
        let command = if rule.action == "Drop" {
            format!("Remove-NetFirewallRule -DisplayName \"{}\"", rule.display_name)
        


        // -- [ Feri ] --

        // jika klo action isi nya itu "Allow", maka akan
        // menjalankan commnad powershell New-NetFirewallRule
        } else if rule.action == "Allow" {
            format!(
                "New-NetFirewallRule -DisplayName \"{}\" -Direction {} -LocalPort {} -Protocol {} -Action {}",
                rule.display_name, rule.direction, rule.local_port, rule.protocol, rule.action
            )

        // jika lain daripada itu, maka action tidak dikenali
        } else {
            format!("echo \"Action '{}' is not recognized\"", rule.action)
        };

        // pesan sukses atau gagal yg nanti akan ditampilkan di terminal
        let (success_msg, fail_msg) = if rule.action == "Drop" 
            { ("RULE DROPPED", "FAILED TO DROP") }
        else { ("SUCCESS", "FAILED") };

        // melakukan spawn thread atau membuat thread baru yg
        // menjalankan function "execute_firewall_command".
        // fungsi "execute_firewall_command" ini akan dieksekusi
        // secara paralel di dalam thread yg baru dibuat.

        // move yg terdapat thread spawn ini fungsi nya untuk
        // memindahkan ownership variabel dri luar closure ke dlm closure
        let handle = thread::spawn(move || {
            execute_firewall_command(display_name, command, success_msg, fail_msg);
        });

        // menambahkan thread baru ke dalam vector handles
        // yang sudah di jelaskan sblum -nya.
        handles.push(handle);
    }

    // mengunggu setiap handle thread selesai dieksekusi
    // dan segera menampilkan log di terminal (SUCCESS / FAILED)
    for handle in handles {
        handle.join().expect("thread failed");
    }

    // mengembalikan nilai kosong,
    // dan mengindikasikan program berjalan dngan semesti -nya.
    Ok(())

}
