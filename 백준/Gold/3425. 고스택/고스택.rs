use std::io::{self, BufRead};

fn main() {
    let stdin = io::stdin();
    let mut input = Vec::new();

    // 입력을 읽어서 저장
    for line in stdin.lines() {
        let line = line.expect("입력 읽기 실패");
        if line.trim() == "QUIT" {
            break; // "QUIT" 입력 시 종료
        }
        input.push(line);
    }

    // 수집된 입력 처리
    let mut machines = Vec::new();
    let mut idx = 0;

    // 모든 머신의 프로그램 수집
    while idx < input.len() {
        let mut program = Vec::new();

        // 프로그램 수집
        while idx < input.len() {
            let line = input[idx].trim().to_string();

            // 공백 줄 무시
            if line.is_empty() {
                idx += 1;
                continue; // 다음 줄로 넘어갑니다.
            }

            if line == "END" {
                // 프로그램을 저장하고 종료
                if !program.is_empty() {
                     machines.push(program.clone()); // 프로그램이 비어있지 않으면 저장
                }
                idx += 1; // 다음 줄로 이동
                break; // 내부 루프 종료
            }
            program.push(line); // 프로그램 명령어 저장
            idx += 1; // idx 증가
        }
        
         // 입력값을 처리하기 위한 루프
        if idx < input.len() {
            let n: usize = input[idx].trim().parse().expect("숫자를 입력해야 합니다.");
            idx += 1; // 다음 줄로 이동

            let mut values = Vec::new();
            // 각 입력값을 한 번에 읽기
            for _ in 0..n {
                if idx < input.len() {
                    let value: i32 = input[idx].trim().parse().expect("정수를 입력해야 합니다.");
                    values.push(value);
                    idx += 1; // idx 증가
                }
            }

            // 프로그램 실행 및 결과 출력
            for &value in &values {
                let result = execute_program(&program, value); // 머신의 프로그램을 입력값으로 실행
                println!("{}", result); // 결과 출력
            }
            println!(" "); // 기계 사이에 공백 추가
        }

        // // 입력값을 처리하기 위한 루프
        // if idx < input.len() {
        //     let n: usize = input[idx].trim().parse().expect("숫자를 입력해야 합니다.");
        //     idx += 1; // 다음 줄로 이동

        //     let mut values = Vec::new();
        //     // 각 입력값을 한 번에 읽기
        //     for _ in 0..n {
        //         if idx < input.len() {
        //             let value: i32 = input[idx].trim().parse().expect("정수를 입력해야 합니다.");
        //             values.push(value);
        //             idx += 1; // idx 증가
        //         }
        //     }

        //      // 프로그램 실행 및 결과 수집
        //     for machine in &machines {
        //         for &value in &values {
        //             let result = execute_program(machine, value); // 이 부분은 execute_program 함수가 필요합니다.
        //             println!("{}", result); // 결과 출력
        //         }
        //         println!(" ");
        //     }
            
        // }
    }
}



// fn main() {
//     println!("start");
//     let stdin = io::stdin();
//     let mut input = Vec::new();

//     // 입력을 읽어서 저장
//     for line in stdin.lines() {
//         let line = line.expect("입력 읽기 실패");
//         // println!("{line}");
//         if line.trim() == "QUIT" {
//             break; // "QUIT" 입력 시 종료
//         }
//         input.push(line);
//     }
//     // println!("fin input");
//     let tmp = input.len();
//     // println!("{tmp}");
    
//     // 수집된 입력 처리
//     let mut machines = Vec::new();

//     let mut idx = 0;
//     while idx < input.len() {
//         let line = input[idx].trim().to_string();
//         // println!("in {idx} {line}");
//         // 공백 줄 무시
//         if line.is_empty() {
//             idx += 1;
//             continue; // 다음 줄로 넘어갑니다.
//         }
            
//         if line == "END" {
//             // 프로그램 종료 처리
//             idx += 1;
//             break;
//         }
//         idx += 1;
//         // 프로그램 명령어 수집
//         let mut program = vec![line];
//         while idx < input.len() {
//             let line = input[idx].trim().to_string();
//             if line == "END" {
//                 machines.push(program);
//                 // idx += 1;
//                 break;
//             }
//             idx += 1;
//             println!("line {line}");
//             program.push(line);
//         }

//     }
//     // println!("out {idx}");
//     let mut results = Vec::new();
//     // 각 기계에 대해 수행
//     while idx < input.len()-1 {
//         // println!("hi {idx}");
//         let n: usize = input[idx].trim().parse().expect("숫자를 입력해야 합니다.");
//         // println!("n {n}");
//         idx += 1;

//         let mut values = Vec::new();

//         // 각 입력값을 한 번에 읽기
//         for _ in 0..n {
//             if idx < input.len() {
//                 let value: i32 = input[idx].trim().parse().expect("정수를 입력해야 합니다.");
//                 println!("value {value}");
//                 values.push(value);
//                 idx += 1;
//             }
//         }

//         // 프로그램 실행 및 결과 수집
//         for &value in &values {
//             for machine in &machines {
//                 let result = execute_program(machine, value); // 이 부분은 execute_program 함수가 필요합니다.
//                 println!("result {result}");
//                 results.push(result);
//             }
//         }
//     }

//     // 모든 결과 출력
//     for result in results {
//         println!("{}", result);
//     }
// }

// 프로그램을 실행하는 함수
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
                let len = stack.len();
                stack.swap(len - 1, len - 2);
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
            "DIV" => {
                if stack.len() < 2 {
                    return "ERROR".to_string();
                }
                let a = stack.pop().unwrap();
                let b = stack.pop().unwrap();
                if a == 0 {
                    return "ERROR".to_string();
                }
                let result = (b.abs() / a.abs()) * if (b < 0) ^ (a < 0) { -1 } else { 1 };
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
                let result = b % a;
                stack.push(result);
            }
            _ => {}
        }
    }

    // 최종 결과 확인
    if stack.len() != 1 {
        return "ERROR".to_string();
    }
    
    stack[0].to_string()
}
