use std::io;

fn main() {
    let mut board = vec![vec![0; 19]; 19];

    for i in 0..19 {
        let mut input = String::new();
        io::stdin().read_line(&mut input).expect("Failed to read line");
        
        let mut row = Vec::new(); 
        for part in input.split_whitespace() {
            let num: i32 = part.parse().expect("Failed to parse num");
            row.push(num); 
        }
        
        board[i] = row;
    }

    let directions = [(0, 1), (1, 0), (1, 1), (-1, 1)];

    for i in 0..19 {
        for j in 0..19 {
            if board[i][j] != 0 {
                let color = board[i][j];

                for &(dx, dy) in &directions {
                    let mut count = 1;

                    for k in 1..5 {
                        let nx = i as isize + dx * k;
                        let ny = j as isize + dy * k;

                        // 범위 벗어나는지 체크
                        if nx < 0 || nx > 18 || ny < 0 || ny > 18 {
                            break;
                        }

                        if board[nx as usize][ny as usize] == color {
                            count += 1;
                        } else {
                            break;
                        }
                    }

                    if count == 5 {
                        // 6목 체크
                        let next_x = i as isize + dx * 5; // 5개 뒤
                        let next_y = j as isize + dy * 5;
                        let prev_x = i as isize - dx; // 5개 앞
                        let prev_y = j as isize - dy;

                        // 6목이면
                        if (next_x >= 0 && next_x <= 18 && next_y >= 0 && next_y <= 18 && board[next_x as usize][next_y as usize] == color) ||
                           (prev_x >= 0 && prev_x <= 18 && prev_y >= 0 && prev_y <= 18 && board[prev_x as usize][prev_y as usize] == color) {
                            continue; 
                        }

                        // i, j 0부터 시작하므로 +1
                        let start_x = i + 1;
                        let start_y = j + 1;

                        println!("{color}");
                        println!("{start_x} {start_y}");
                        return;
                    }
                }
            }
        }
    }

    println!("0");
}