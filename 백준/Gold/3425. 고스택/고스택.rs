use std::io;

fn main() {
    let stdin = io::stdin();
    let mut input = String::new();
    let mut all_results = Vec::new(); 

    loop {
        input.clear();
        stdin.read_line(&mut input).expect("Failed to read line");

        let line = input.trim();
        if line.is_empty()  {
            continue; 
        }
        if line == "QUIT"  {
            break; 
        }
        
        let mut command = Vec::new();
        
        // 첫 번째 명령어가 END인 경우
        if line == "END" {
            input.clear();
            stdin.read_line(&mut input).expect("Failed to read line");
            let n: u32 = input.trim().parse().expect("Failed to parse n");

            let mut values = Vec::new();
            for _ in 0..n {
                input.clear();
                stdin.read_line(&mut input).expect("Failed to read line");

                let v: i32 = input.trim().parse().expect("Failed to parse v");
                values.push(v);
            }

            let mut results = Vec::new();
            for &v in &values {
                let result = execute_command(&command, v); 
                results.push(result); 
            }

            all_results.push(results);
            continue; 
        }

        command.push(line.to_string());

        loop {
            input.clear();
            stdin.read_line(&mut input).expect("Failed to read line");

            let line = input.trim();
            if line == "END" {
                break; 
            }
            
            command.push(line.to_string()); 
        }

        input.clear();
        stdin.read_line(&mut input).expect("Failed to read line");
        let n: u32 = input.trim().parse().expect("Failed to parse n"); 

        let mut values = Vec::new();
        for _ in 0..n {
            input.clear();
            stdin.read_line(&mut input).expect("Failed to read line");

            let v: i32 = input.trim().parse().expect("Failed to parse v");
            values.push(v);
        }

        let mut results = Vec::new();
        for &v in &values {
            let result = execute_command(&command, v); 
            results.push(result); 
        }

        all_results.push(results);
    }
    for results in all_results {
        for result in results {
            println!("{}", result);
        }
        println!(" ");
    }
}

fn execute_command(command: &[String], value: i32) -> String {
    let mut stack = vec![value];

    for command in command {
        match command.as_str() {
            cmd if cmd.starts_with("NUM") => {
                let number: i32 = cmd[4..].parse().unwrap();
                stack.push(number);
            }
            "POP" => {
                if stack.is_empty() {
                    return "ERROR".to_string();
                }
                stack.pop();
            }
            "INV" => {
                if stack.is_empty() {
                    return "ERROR".to_string();
                }
                let top = stack.pop().unwrap();
                stack.push(-top);
            }
            "DUP" => {
                if stack.is_empty() {
                    return "ERROR".to_string();
                }
                let top = stack.pop().unwrap(); 
                stack.push(top); 
                stack.push(top); 
            }
            "SWP" => {
                if stack.len() < 2 {
                    return "ERROR".to_string();
                }
                let first = stack.pop().unwrap();
                let second = stack.pop().unwrap();
                stack.push(first); 
                stack.push(second);
            }
            "ADD" => {
                if stack.len() < 2 {
                    return "ERROR".to_string();
                }
                let a = stack.pop().unwrap();
                let b = stack.pop().unwrap();

                if ( a > 1_000_000_000 - b) || (a < -1_000_000_000 - b) {
                    return "ERROR".to_string(); // 오버플로우 발생
                }
                
                stack.push(a + b);
            }
            "SUB" => {
                if stack.len() < 2 {
                    return "ERROR".to_string();
                }
                let a = stack.pop().unwrap();
                let b = stack.pop().unwrap();

                // if (b > 0 && a < 0 && b > 1_000_000_000 + a) || (b < 0 && a > 0 && b < -1_000_000_000 + a) {
                //     return "ERROR".to_string(); // 오버플로우 발생
                // }
                
                // stack.push(b - a);
                let result = b.checked_sub(a);
                match result {
                    Some(val) if val.abs() <= 1_000_000_000 => stack.push(val),
                    _ => return "ERROR".to_string(),
                }
            }
            "MUL" => {
                if stack.len() < 2 {
                    return "ERROR".to_string();
                }
                let a = stack.pop().unwrap();
                let b = stack.pop().unwrap();
                let result = a.checked_mul(b);
                match result {
                    Some(val) if val.abs() <= 1_000_000_000 => stack.push(val),
                    _ => return "ERROR".to_string(),
                }
                // let result = a * b;
                // if result.abs() > 1000000000 {
                //     return "ERROR".to_string();
                // }
                // stack.push(result);
            }
            "DIV" => {
                if stack.len() < 2 {
                    return "ERROR".to_string();
                }
                let a = stack.pop().unwrap(); 
                let b = stack.pop().unwrap(); 

                if a == 0 {
                    return "ERROR".to_string(); 
                }

                let abs_a = a.abs();
                let abs_b = b.abs();
                let mut result = abs_b / abs_a;
                
                if (a < 0 && b > 0) || (a > 0 && b < 0) {
                    result = -result;
                }

                stack.push(result);
            }
            "MOD" => {
                if stack.len() < 2 {
                    return "ERROR".to_string();
                }
                let a = stack.pop().unwrap(); 
                let b = stack.pop().unwrap(); 
                if a == 0 {
                    return "ERROR".to_string();
                }

                let abs_a = a.abs();
                let abs_b = b.abs();
                let mut result = abs_b % abs_a;

                if b < 0 {
                    result = -result;
                }

                stack.push(result);
            }
            _ => return "ERROR".to_string(), 
        }
    }

    if stack.len() == 1 {
        return stack[0].to_string();
    } else {
        return "ERROR".to_string();
    }
}
