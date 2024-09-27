# Queenium

This project implements a solution to the N-Queens problem (placing N queens on an NxN chessboard such that no two queens can attack each other) using C++. It includes functionality to generate unique solutions by detecting and filtering out symmetrical configurations of the board.

## Description

The N-Queens problem is a classic algorithmic challenge. This implementation:

- Solves the N-Queens problem using backtracking.
- Detects and eliminates symmetrical solutions by generating all rotational and reflected versions of a board configuration.
- Uses ANSI escape codes to print the board with color, making it visually distinct.

### Features

- Solves the N-Queens problem using recursion and backtracking.
- Detects symmetries (rotations and reflections) and avoids duplicate solutions.
- Color-coded output for queens and empty spaces in the terminal.
- Supports custom board size by modifying the `N` constant in the code.

## Getting Started

### Clone the repository:

```sh
git clone https://github.com/OrakomoRi/Queenium.git
```

### Run the code

1. Compile the C++ code. Make sure you have a C++ compiler (e.g., `g++`) installed.

2. Run the compiled program:
	```bash
	./queenium
	```

3. Execute the compiled program, and it will output the number of unique solutions, followed by the solutions themselves, displayed with colored queens (`Q`) and empty spaces (`*`).

### Modifying the Board Size

You can adjust the size of the chessboard by modifying the `N` constant in the code:

```cpp
// Default
#define N 8
```

Change the value of `N` to any desired board size.

`Note!` Finding a solution with size 14+ using online compilers takes ages.

## Example Output

Here is an example of the output for the 8-Queens problem:

```less
Number of unique solutions: 92

 Q  *  *  *  *  *  *  * 
 *  *  *  *  *  Q  *  * 
 *  *  *  Q  *  *  *  * 
 *  Q  *  *  *  *  *  * 
 *  *  *  *  Q  *  *  * 
 *  *  *  *  *  *  Q  * 
 *  *  Q  *  *  *  *  * 
 *  *  *  *  *  *  *  Q 

... (other solutions follow)
```

## License

Distributed under the MIT License. See `LICENSE` for more information.

## Acknowledgments

* [Eight Gueens Puzzle](https://en.wikipedia.org/wiki/Eight_queens_puzzle)
* [8 Queen Problem](https://www.geeksforgeeks.org/8-queen-problem/)
* [C++ Vector](https://en.cppreference.com/w/cpp/container/vector)