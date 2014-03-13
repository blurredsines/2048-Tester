#include <cstdio>
#include <iostream>
#include "Board.hpp"

using namespace std;

void Board::setTile(int x, int y, int v) {
  gridState[x][y] = v;
}

void Board::slideBoard(Direction d) {
  if(d == UP) {
    for(int i = 0; i < BOARD_SIZE; i++) {
      for(int j = 0; j < BOARD_SIZE; j++) {
        slideTile(i, j, UP);
      }
    }
  }
  else if(d == DOWN) {
    for(int i = 0; i < BOARD_SIZE; i++) {
      for(int j = BOARD_SIZE - 1; j >= 0; j--) {
        slideTile(i, j, DOWN);
      }
    }    
  }
  else if (d == LEFT) {
    for(int i = 0; i < BOARD_SIZE; i++) {
      for(int j = 0; j < BOARD_SIZE; j++) {
        slideTile(i, j, LEFT);
      }
    }
  }
  else if (d == RIGHT) {
    for(int i = BOARD_SIZE; i >= 0; i--) {
      for(int j = 1; j < BOARD_SIZE; j++) {
        slideTile(i, j, RIGHT);
      }
    }    
  }
}

void Board::slideTile(int x, int y, Direction d) {
  if(d == UP) {
    if(y == 0) {
      return;
    }
    if(gridState[x][y-1] == 0) {
      gridState[x][y-1] = gridState[x][y];
      gridState[x][y] = 0;
      slideTile(x, y-1, d);
    } else if(gridState[x][y-1] == gridState[x][y]) {
      gridState[x][y-1] += gridState[x][y-1];
      gridState[x][y] = 0;
      slideTile(x, y-1, d);
    } else {
      // No more sliding to do
      return;
    }
  }
  else if(d == DOWN) {
    if(y == BOARD_SIZE - 1) {
      return;
    }
    if(gridState[x][y+1] == 0) {
      gridState[x][y+1] = gridState[x][y];
      gridState[x][y] = 0;
      slideTile(x, y+1, d);
    } else if(gridState[x][y+1] == gridState[x][y]) {
      gridState[x][y+1] += gridState[x][y+1];
      gridState[x][y] = 0;
      slideTile(x, y+1, d);
    } else {
      // No more sliding to do
      return;
    }
  }
  else if (d == LEFT) {
    if(x == 0) {
      return;
    }
    else if(gridState[x-1][y] == 0) {
      gridState[x-1][y] = gridState[x][y];
      gridState[x][y] = 0;
      slideTile(x-1, y, d);
    } else if(gridState[x-1][y] == gridState[x][y]) {
      gridState[x-1][y] += gridState[x-1][y];
      gridState[x][y] = 0;
      slideTile(x-1, y, d);
    } else {
      // No more sliding to do
      return;
    }
  }
  else if (d == RIGHT) {
    if(x == BOARD_SIZE - 1) {
      return;
    }
    else if(gridState[x+1][y] == 0) {
      gridState[x+1][y] = gridState[x][y];
      gridState[x][y] = 0;
      slideTile(x+1, y, d);
    } else if(gridState[x+1][y] == gridState[x][y]) {
      gridState[x+1][y] += gridState[x+1][y];
      gridState[x][y] = 0;
      slideTile(x+1, y, d);
    } else {
      // No more sliding to do
      return;
    }
  }
}

void Board::printBoard(void) {
  for(int j = 0; j < BOARD_SIZE; j++) {
    for(int i = 0; i < BOARD_SIZE; i++) {
      printf("[%4d]", gridState[i][j]);
    }
    cout << endl;
  }
}

int main (void) {
  Board b;
  b.gridState[0][1] = 4;
  b.gridState[0][2] = 4;
  b.gridState[1][0] = 2;
  b.gridState[3][0] = 2;
  b.gridState[3][1] = 4;
  b.gridState[3][2] = 8;
  b.gridState[3][3] = 16;
  b.printBoard();
  b.slideBoard(DOWN);
  cout << "------------------------" << endl;
  b.printBoard();
  b.slideBoard(RIGHT);
  cout << "------------------------" << endl;
  b.printBoard();
  b.slideBoard(UP);
  cout << "------------------------" << endl;
  b.printBoard();
  b.slideBoard(LEFT);
  cout << "------------------------" << endl;
  b.printBoard();
  b.slideBoard(RIGHT);
}