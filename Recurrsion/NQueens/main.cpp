#include <iostream>

bool Place(int row, int col);
void NQueens(int row);
void write(int n);
int n;
int board[5];

int main() {
  n = 5;
  NQueens(5);

  return 0;
}

bool Place(int row, int col) {
  for (int j = 1; j < (row - 1); ++j) {
    if ((board[j] == col) || (abs(board[j] - col) == abs(j - row))) {
      return false;
    }
  }
  return true;
}

void NQueens(int row) {
  for (int i = 1; i <= n; ++i) {
    if (Place(row, i)) {
      board[row] = i;
      if (row == n) {
        write(n);
        return;
      }
      else {
        NQueens(row + 1);
      }
    }
  }
}

void write(int n) {
  for (int row = 1; row <= n; ++row) {
    for (int col = 1; col <=n; ++col) {
      if (board[row] == col) {
        std::cout << 'Q' << " ";
      }
      else {
        std::cout << "_" << " ";
      }
    }
    std::cout << std::endl;
  }
}