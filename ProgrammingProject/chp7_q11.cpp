#include <iostream>
#include <cassert>
#include <string>
#include <stack>
#include <map>
using std::cout;
using std::endl;
using std::string;

struct coord {
  int row;
  int col;
};

class Nqueens {
 private:
  // create a stack of map to store the coordinates of queens
  std::stack<coord> s;
  // a struct object c to record the row and col coordinate
  coord c;
  // create a chessboard
  string chessboard[8][8];
  // required by the problem
  bool success = false;


 public:
  // Set the coordinate of the first queen to the top left corner of the chessboard
  void insertFirstQueen() {
    // Set the coordinate to 0, 0
    c.row = c.col = 0;
    // Update the chessboard
    chessboard[c.row][c.col] = "Queen";
    // Push the coordinate onto the stack
    s.push(c);
  }

  // Insert the rest of the queens
  void insertOtherQueens(int row, int col) {
    // Verify if the input coords are valid
    assert(row < 8 && row > 0);
    assert(col < 8 && col > 0);
    // Set the coordinate to the input row, col
    c.row = row;
    c.col = col;
    // Update the chessboard
    chessboard[c.row][c.col] = "Queen";
    // Push the coordinate onto the stack
    s.push(c);
  }

  // Check conflict
  void checkConflict() {
    while (!success && !s.empty()) {
      if (c.row == 0 || c.col == 0) {
        s.pop();
      } else {
        s.push(c);
      }
    }
  }
};