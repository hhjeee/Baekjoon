use std::io;

fn main() {
    let mut input = String::new();
    io::stdin()
        .read_line(&mut input)
        .expect("Failed to read first line");
        
    let split_input: Vec<&str> = input.split_whitespace().collect();
    
    let n: i32 = split_input[0].parse().expect("Failed to parse n");
    let x: i32 = (split_input[1].parse::<f64>().expect("Failed to parse x") * 100.0).round() as i32;
    
    let mut sum_subjects: i32 = 0;
    let mut total_credits: i32 = 0;
    
    for _ in 0..(n - 1) {
        let mut input = String::new();
        io::stdin()
            .read_line(&mut input)
            .expect("Failed to read line");
        
        let input_split: Vec<&str> = input.split_whitespace().collect();
        
        let credit: i32 = input_split[0].parse().expect("Failed to parse credit");
        let grade = input_split[1];
    
        sum_subjects += credit * letter_to_grade(grade); 
        total_credits += credit;
    }
    
    let mut input2 = String::new();
    io::stdin()
        .read_line(&mut input2)
        .expect("Failed to read last line"); 
    let last_credit: i32 = input2.trim().parse().expect("Failed to get last credit");

    let grades = ["F", "D0", "D+", "C0", "C+", "B0", "B+", "A0", "A+"];
    let mut round_min_grade = "impossible"; 

    for grade in grades {
        let current_gpa = (sum_subjects + last_credit * letter_to_grade(grade))  as f64 / (total_credits + last_credit) as f64 ;
        let check_value = (current_gpa * 100.0).round() as i32 / 100; 

        if check_value > x {
            round_min_grade = grade; 
            break; 
        }
    }

    println!("{round_min_grade}");
}

fn letter_to_grade(letter: &str) -> i32 {
    match letter {
        "A+" => 450,
        "A0" => 400,
        "B+" => 350,
        "B0" => 300,
        "C+" => 250,
        "C0" => 200,
        "D+" => 150,
        "D0" => 100,
        _ => 0, // F 포함
    }
}
