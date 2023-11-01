use std::collections::BTreeMap;
use std::io;

struct Student {
    middle: i32,
    final_score: i32,
}

fn main() {
    let args: Vec<String> = std::env::args().collect();

    if args.len() < 2 {
        eprintln!("Usage: student count");
        std::process::exit(1);
    }

    let treesize: i32 = args[1].parse().expect("Failed to parse count");
    let mut student_map: BTreeMap<String, Student> = BTreeMap::new();

    while student_map.len() != treesize as usize {
        let mut input = String::new();
        io::stdin().read_line(&mut input).expect("Failed to read input");
        let input_parts: Vec<&str> = input.trim().split_whitespace().collect();

        if input_parts.len() < 3 {
            eprintln!("Invalid input format. Expected: name middle final_score");
            continue;
        }

        let name = input_parts[0].to_string();
        let middle: i32 = input_parts[1].parse().expect("Failed to parse middle score");
        let final_score: i32 = input_parts[2].parse().expect("Failed to parse final_score score");

        let student = Student {
            middle,
            final_score,
        };

        if student_map.contains_key(&name) {
            println!("\"{}\" 님이 이미 존재합니다.", name);
        } else {
            student_map.insert(name.clone(), student);
            println!("\"{}\" 님이 트리에 추가되었습니다.", name);
        }
    }

    for (name, student) in &student_map {
        println!("이름 = {}, 중간점수 = {}, 기말점수 = {}", name, student.middle, student.final_score);
    }
}
