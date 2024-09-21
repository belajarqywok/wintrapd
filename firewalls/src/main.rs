mod fw_struct;
use fw_struct::FirewallConfig;

use std::thread;
use std::fs::File;
use std::io::BufReader;
use serde_json::Result as JsonResult;
use clap::{Arg, Command as ClapCommand};
use std::process::Command as StdCommand;


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
        .version("1.0")
        .author("qywok <alfariqyraihan@gmail.com>")
        .about("manages windows firewall rules")
        .arg(Arg::new("rules")
            .short('r')
            .long("rules")
            .value_name("FILE")
            .required(true)
            .help("path to the firewall rules json file"))
        .get_matches();

    let rules_file = matches.get_one::<String>("rules")
        .expect("rules file is required");

    let file = File::open(rules_file).expect("fail to open file");
    let reader = BufReader::new(file);

    let config: FirewallConfig = serde_json::from_reader(reader)
        .expect("error while reading or parsing");

    let mut handles: Vec<thread::JoinHandle<()>> = vec![];

    for rule in config.rules.iter() {
        let display_name = rule.display_name.clone();

        let command = if rule.action == "drop" {
            format!("Remove-NetFirewallRule -DisplayName \"{}\"", display_name)
        } else {
            format!(
                "New-NetFirewallRule -DisplayName \"{}\" -Direction {} -LocalPort {} -Protocol {} -Action {}",
                rule.display_name, rule.direction, rule.local_port, rule.protocol, rule.action
            )
        };

        let (success_msg, fail_msg) = if rule.action == "drop" 
            { ("RULE DROPPED", "FAILED TO DROP") }
        else { ("SUCCESS", "FAILED") };


        let handle = thread::spawn(move || {
            execute_firewall_command(display_name, command, success_msg, fail_msg);
        });

        handles.push(handle);
    }

    for handle in handles {
        handle.join().expect("thread failed");
    }

    Ok(())

}
