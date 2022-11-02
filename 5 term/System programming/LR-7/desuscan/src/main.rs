mod input_validation_module;
mod network_module;

use std::env;
use crate::input_validation_module::parsing_input_ports;


fn main() {
    let args: Vec<String> = env::args().collect();
    if args.len() < 2 {
        println!("Too few args, use -h to get help");
        return;
    }
    let mut f_arg = args[1].clone();
    if f_arg == "-h" || f_arg == "-help" {
        println!("DesuScan help:3
           \n----- INPUT FORMAT: desuscan [ip (you can use 'local' to scan your local port)] -p (optional) \
           -op (optional) -----\
           \n\n-h or -help : for call help\
           \n-v or --version : for call info about version\
           \n-op or --option : value is 'udp' or 'tcp' (default: tlc), use this flag to choose port \
           scanning port type\
           \n-p or --port : for set the investigated ports (default: scan all 65535 ports)\
           \n\nBe careful and enjoy you use, desu >_<\n");
        return;
    }
    if f_arg == "-v" || f_arg == "--version" {
        println!("DesuScan version check\nvesion: 0.0.1\ncargo version: 1.64.0\ndev by relsa228 <3\n");
        return;
    }
    if f_arg == "local" {}
    else if input_validation_module::ip_check(f_arg.trim()) {
        return;
    }
    let mut option: String = String::from("");
    let mut ports: String = String::from("");
    let mut op_flag = false;
    let mut port_flag = false;
    for arg in args {
        if arg == "-op" || arg == "--option" {
            op_flag = true;
            port_flag = false;
        }
        else if arg == "-p" || arg == "--port" {
            op_flag = false;
            port_flag = true;
        }
        else if op_flag {
            if arg != "udp" && arg != "tcp" {
                println!("Invalid option, use -h to get help");
                return;
            }
            option = arg;
        }
        else if port_flag {
            ports += (arg.clone().as_str().to_owned() + " ".trim()).as_str()
        }
    }
    let mut option_arg: u8 = 1;
    if option == "udp" {
        option_arg = 0;
    }
    if ports == "" {
        ports = "0-65534,".to_string();
    }
    if f_arg == "local" {
        f_arg = "127.0.0.1".to_string();
    }
    ports += ",";
    println!("Say UwU to DesuScan");
    network_module::scan_init(f_arg.trim(),
                              parsing_input_ports(ports.trim()),
                              option_arg);
}
