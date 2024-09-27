#include <iostream>
#include <vector>
#include <set>
#include <algorithm>


/*
	The most useful variable. It defines
	the number of queens and the size of the
	board.
*/

#define N 8


// Colors using ANSI escape codes
#define RESET	"\033[0m"		// Reset to default color
#define GREEN	"\033[32m"		// Green color for the queen
#define GRAY	"\033[90m"		// Gray color for empty cells

using Board = std::vector<std::vector<int>>;

// Function to check if it's safe to place a queen on the board
bool isSafe(const Board& board, int row, int col) {
	// Check the row to the left of the current column
	for (int i = 0; i < col; i++) {
		if (board[row][i]) {
			return false;
		}
	}

	// Check the upper diagonal on the left
	for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
		if (board[i][j]) {
			return false;
		}
	}

	// Check the lower diagonal on the left
	for (int i = row, j = col; j >= 0 && i < N; i++, j--) {
		if (board[i][j]) {
			return false;
		}
	}

	return true;
}

// Helper functions to generate symmetries
Board rotate90(const Board& board) {
	Board rotated(N, std::vector<int>(N, 0));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			rotated[j][N - i - 1] = board[i][j];
	return rotated;
}

Board reflectHorizontal(const Board& board) {
	Board reflected(N, std::vector<int>(N, 0));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			reflected[i][N - j - 1] = board[i][j];
	return reflected;
}

// Function to generate all symmetrical configurations of the board
std::set<Board> generateSymmetries(const Board& board) {
	std::set<Board> symmetries;
	Board current = board;

	for (int i = 0; i < 4; i++) {
		symmetries.insert(current);
		symmetries.insert(reflectHorizontal(current));
		current = rotate90(current);
	}

	return symmetries;
}

// Recursive function to find all solutions to the N-Queens problem
void solveNQueens(Board& board, int col, std::set<Board>& uniqueSolutions) {
	if (col >= N) {
		auto symmetries = generateSymmetries(board);
		for (const auto& symmetry : symmetries) {
			if (uniqueSolutions.count(symmetry)) {
				return; // If the symmetry already exists, skip this solution
			}
		}
		uniqueSolutions.insert(board); // If no symmetry is found, add the original board
		return;
	}

	for (int i = 0; i < N; i++) {
		if (isSafe(board, i, col)) {
			board[i][col] = 1;
			solveNQueens(board, col + 1, uniqueSolutions);
			board[i][col] = 0;
		}
	}
}

// Function to print the board
void printBoard(const Board& board) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j]) {
				std::cout << GREEN << " Q " << RESET;
			} else {
				std::cout << GRAY << " * " << RESET;
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int main() {
	// Create an empty chessboard
	Board board(N, std::vector<int>(N, 0));

	// Set to store unique solutions
	std::set<Board> uniqueSolutions;

	// Solve the problem starting from the first column
	solveNQueens(board, 0, uniqueSolutions);

	// Output all unique solutions found
	std::cout << "Number of unique solutions: " << uniqueSolutions.size() << std::endl;
	for (const auto& solution : uniqueSolutions) {
		printBoard(solution);
	}

	return 0;
}