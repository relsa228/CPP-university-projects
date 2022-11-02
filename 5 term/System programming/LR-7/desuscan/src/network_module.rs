use std::net::{TcpListener, UdpSocket};


pub(crate) fn scan_init(host: &str, ports: Vec<u16>, option: u8) {
    match option {
        0 => port_scan_udp(host, ports),
        1 => port_scan_tcp(host, ports),
        _ => println!("WTF input")
    }
}

fn port_scan_tcp(host: &str, ports: Vec<u16>) {
    for port in ports {
        match TcpListener::bind((host, port)) {
            Ok(s) => {
                let ttl = s.ttl().unwrap();
                let full_addr = s.local_addr().unwrap();
                println!("Port {} is available, full adress = {}, type = TCP, \
                TTL = {}", port, full_addr, ttl)
            },
            Err(_) => println!("Port {} is busy or unavailable", port),
        }
    }
}

fn port_scan_udp(host: &str, ports: Vec<u16>) {
    for port in ports {
        match UdpSocket::bind((host, port)) {
            Ok(s) => {
                let ttl = s.ttl().unwrap();
                let full_addr = s.local_addr().unwrap();
                println!("Port {} is available, full adress = {}, type = UDP, \
                TTL = {}", port, full_addr, ttl)
            },
            Err(_) => println!("Port {} is busy or unavailable", port),
        }
    }
}