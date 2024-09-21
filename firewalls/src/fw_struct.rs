use serde::{Deserialize};


#[derive(Deserialize, Debug)]
pub struct FirewallRule {
    pub display_name: String,
    pub direction:   String,
    pub local_port:   u16,
    pub protocol:    String,
    pub action:      String,
}


#[derive(Deserialize, Debug)]
pub struct FirewallConfig {
    pub rules: Vec<FirewallRule>,
}
