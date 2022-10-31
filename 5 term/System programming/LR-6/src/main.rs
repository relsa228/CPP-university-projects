use std::net::TcpListener;
use std::io;
use std::ops::Range;
use std::slice::Iter;


fn string_validation(wrk_str: String) -> bool {
    if wrk_str.is_empty() || wrk_str.len() > 5 {
        return false;
    }
    let check: u32 = wrk_str.trim().parse().unwrap();
    return check <= 65535
}

fn parsing_input_ports(ports: String) -> Vec<u16> {
    let mut result_vector: Vec<u16> = Vec::new();
    let mut buffer_f: String = String::from("");
    let mut buffer_s: String = String::from("");
    let mut buffer_change: bool = false;
    for symb in ports.chars() {
        if symb.is_numeric() {
            match !buffer_change {
                true => buffer_f += symb.encode_utf8(&mut [0; 4]),
                false => buffer_s += symb.encode_utf8(&mut [0; 4])
            }
        }
        else if symb == ',' || symb == '\n' {
            let wrk = buffer_f.to_string();
            match !buffer_change && string_validation(wrk) {
                true => {
                    let push_val: u16 = buffer_f.trim().parse().unwrap();
                    result_vector.push(push_val);
                }
                false => {
                    let mut port_bound: u16 = buffer_s.trim().parse().unwrap();
                    port_bound += 1;
                    for val in buffer_f.trim().parse().unwrap()..port_bound {
                        result_vector.push(val);
                    };
                    buffer_change = false;
                    buffer_s.clear();
                }
            }
            buffer_f.clear();
        }
        else if symb == '-' {
            buffer_change = true;
        }
    };
    return result_vector;
}

fn port_is_available(host: &str, ports: Vec<u16>) {
    let wrk = host.to_string();
    for port in ports {
        match TcpListener::bind((host, port)) {
            Ok(_) => println!("Port {port} (host {wrk}) is available"),
            Err(_) => println!("Port {port} (host {wrk}) is busy or unavailable"),
        }
    }
}

fn main() {
    let stdin = io::stdin();

    println!("Input scanning host: ");
    let mut user_input_host = String::from("");
    stdin.read_line(&mut user_input_host).unwrap();

    println!("Input scanning port: ");
    let mut user_input_ports = String::from("");
    stdin.read_line(&mut user_input_ports).unwrap();

    port_is_available(user_input_host.trim(), parsing_input_ports(user_input_ports));
}
