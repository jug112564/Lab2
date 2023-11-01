use std::env;
use std::io;

fn main() {
    let args: Vec<String> = env::args().collect();

    if args.len() < 3 {
        eprintln!("Usage: matrix matrix_width matrix_height");
        std::process::exit(1);
    }

    let m1_width: usize = args[1].parse().expect("Failed to parse matrix width");
    let m1_height: usize = args[2].parse().expect("Failed to parse matrix height");

    let mut matrix1 = vec![vec![0; m1_width]; m1_height];
    let mut matrix2 = vec![vec![0; m1_width]; m1_height];
    let mut result = vec![vec![0; m1_width]; m1_height];

    println!("Input matrix1 data:");
    for i in 0..m1_height {
        for j in 0..m1_width {
            let mut input = String::new();
            io::stdin().read_line(&mut input).expect("Failed to read input");
            let num: i32 = input.trim().parse().expect("Failed to parse input");
            matrix1[i][j] = num;
        }
    }

    println!("Input matrix2 data:");
    for i in 0..m1_height {
        for j in 0..m1_width {
            let mut input = String::new();
            io::stdin().read_line(&mut input).expect("Failed to read input");
            let num: i32 = input.trim().parse().expect("Failed to parse input");
            matrix2[i][j] = num;
        }
    }

    for i in 0..m1_height {
        for j in 0..m1_width {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    println!("<result>");
    for i in 0..m1_height {
        for j in 0..m1_width {
            print!("{} ", result[i][j]);
        }
        println!();
    }
}