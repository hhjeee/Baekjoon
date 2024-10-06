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
            continue; // 공백 무시
        }
        if line == "QUIT"  {
            break; // "QUIT" 입력 시 종료
        }
        
        let mut program = Vec::new();
        // program.push(line.to_string());
        
        // 첫 번째 명령어 입력 처리
        if line == "END" {
            // END가 입력된 경우, 프로그램 수집을 하지 않고 n 입력을 받도록 함
            // n 입력 받기
            input.clear();
            stdin.read_line(&mut input).expect("Failed to read line");
            let n: usize = input.trim().parse().expect("Failed to parse n");

            let mut values = Vec::new();
            for _ in 0..n {
                input.clear();
                stdin.read_line(&mut input).expect("Failed to read line");

                let value: i32 = input.trim().parse().expect("Failed to parse value");
                values.push(value);
            }

            // 이후에 결과를 저장할 벡터
            let mut results = Vec::new();
            for &value in &values {
                let result = execute_program(&program, value); 
                results.push(result); // 결과 저장
            }

            // 모든 결과를 all_results에 추가
            all_results.push(results);
            continue; // 다음 입력을 기다림
        }
         program.push(line.to_string());

        // 프로그램 수집
        loop {
            input.clear();
            stdin.read_line(&mut input).expect("Failed to read line");

            let line = input.trim();
            if line.is_empty() {
                continue; // 공백 무시
            }
            if line == "END" {
                break; // 프로그램 수집 종료
            }
            
            program.push(line.to_string()); // 프로그램 명령어 저장
        }

        // n 입력 받기
        input.clear();
        stdin.read_line(&mut input).expect("Failed to read line");
        let n: usize = input.trim().parse().expect("Failed to parse n");

        let mut values = Vec::new();
        for _ in 0..n {
            input.clear();
            stdin.read_line(&mut input).expect("Failed to read line");

            let value: i32 = input.trim().parse().expect("Failed to parse value");
            values.push(value);
        }

        // 결과를 저장할 벡터
        let mut results = Vec::new();
        for &value in &values {
            let result = execute_program(&program, value); 
            results.push(result); // 결과 저장
        }

        // 모든 결과를 all_results에 추가
        all_results.push(results);
    }
    // 모든 입력이 완료된 후에 결과 출력
    for results in all_results {
        for result in results {
            println!("{}", result);
        }
        println!(" ");
    }
}

fn execute_program(program: &[String], initial_value: i32) -> String {
    let mut stack = vec![initial_value];

    for command in program {
        match command.as_str() {
            cmd if cmd.starts_with("NUM") => {
                let value: i32 = cmd[4..].parse().unwrap();
                stack.push(value);
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
                let top = *stack.last().unwrap();
                stack.push(top);
            }
            "SWP" => {
                if stack.len() < 2 {
                    return "ERROR".to_string();
                }
                let len = stack.len(); // len을 미리 저장
                stack.swap(len - 1, len - 2); // 이제 안전하게 swap 호출
            }
            "ADD" => {
                if stack.len() < 2 {
                    return "ERROR".to_string();
                }
                let a = stack.pop().unwrap();
                let b = stack.pop().unwrap();
                let result = a.checked_add(b);
                match result {
                    Some(val) if val.abs() <= 1_000_000_000 => stack.push(val),
                    _ => return "ERROR".to_string(),
                }
            }
            "SUB" => {
                if stack.len() < 2 {
                    return "ERROR".to_string();
                }
                let a = stack.pop().unwrap();
                let b = stack.pop().unwrap();
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
            }
            //  "DIV" => {
            //     if stack.len() < 2 {
            //         return "ERROR".to_string();
            //     }
            //     let a = stack.pop().unwrap();
            //     let b = stack.pop().unwrap();
            //     if a == 0 {
            //         return "ERROR".to_string(); // 나누기 0 오류 처리
            //     }

            //     let result = (b.abs() / a.abs()) * if (b < 0) ^ (a < 0) { -1 } else { 1 };
            //     stack.push(result);
            // }
            // "MOD" => {
            //     if stack.len() < 2 {
            //         return "ERROR".to_string();
            //     }
            //     let a = stack.pop().unwrap();
            //     let b = stack.pop().unwrap();
            //     if a == 0 {
            //         return "ERROR".to_string(); // 나머지 0 오류 처리
            //     }

            //     let result = b % a;
            //     stack.push(result);
            // }
              "DIV" => {
                if stack.len() < 2 {
                    return "ERROR".to_string();
                }
                let a = stack.pop().unwrap(); // 나누는 수 (제수)
                let b = stack.pop().unwrap(); // 나누어지는 수 (피제수)
                if a == 0 {
                    return "ERROR".to_string();
                }
                
                // 절댓값을 이용해 나누기
                let abs_a = a.abs();
                let abs_b = b.abs();
                let mut result = abs_b / abs_a;
                
                // 부호 결정: 제수 또는 피제수 중 하나만 음수면 결과는 음수
                if (a < 0 && b > 0) || (a > 0 && b < 0) {
                    result = -result;
                }

                if result.abs() > 1_000_000_000 {
                    return "ERROR".to_string();
                }
                stack.push(result);
            }
            "MOD" => {
                if stack.len() < 2 {
                    return "ERROR".to_string();
                }
                let a = stack.pop().unwrap(); // 나누는 수 (제수)
                let b = stack.pop().unwrap(); // 나누어지는 수 (피제수)
                if a == 0 {
                    return "ERROR".to_string();
                }

                // 절댓값을 이용해 나머지 계산
                let abs_a = a.abs();
                let abs_b = b.abs();
                let mut result = abs_b % abs_a;

                // 나머지의 부호는 피제수의 부호와 동일
                if b < 0 {
                    result = -result;
                }

                stack.push(result);
            }
            _ => return "ERROR".to_string(), // 알 수 없는 명령어일 때 오류 처리
        }
    }

  // 명령어가 없을 경우에도 스택의 첫 번째 값을 반환
    if stack.len() == 1 {
        return stack[0].to_string();
    } else {
        return "ERROR".to_string();
    }
}
