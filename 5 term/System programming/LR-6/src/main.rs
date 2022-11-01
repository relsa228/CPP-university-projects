mod network_module;
mod input_validation_module;

use std::io;


fn main() {
    let stdin = io::stdin();

    println!("Input scanning host: ");
    let mut user_input_host = String::from("");
    stdin.read_line(&mut user_input_host).unwrap();

    if input_validation_module::ip_check(user_input_host.trim()) {
        println!("Input scanning port: ");
        let mut user_input_ports = String::from("");
        stdin.read_line(&mut user_input_ports).unwrap();
        network_module::port_is_available(user_input_host.trim(),
        input_validation_module::parsing_input_ports(user_input_ports));
    }
    else {
        println!("Incorrect ip adress (need IPv4 or IPv6)")
    }
}
