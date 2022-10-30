use std::net::TcpListener;
use std::io;


fn port_is_available(host: &str, port: u16) {
    let wrk = host.to_string();
    match TcpListener::bind((host, port)) {
        Ok(_) => print!("Port {port} is available, host {wrk}"),
        Err(_) => print!("Port {port} is busy or unavailable, host {wrk}"),
    }
}

fn main() {
    let stdin = io::stdin();

    println!("Input scanning host: ");
    let mut user_input_host = String::from("");
    stdin.read_line(&mut user_input_host).unwrap();

    println!("Input scanning port: ");
    let mut user_input_port = String::from("");
    stdin.read_line(&mut user_input_port).unwrap();
    let mut user_input_port_int: u16 = user_input_port.trim().parse().unwrap();

    port_is_available(user_input_host.trim(), user_input_port_int);
}
