#ifndef BOARD
#define BOARD

#define BOARD_SIZE 4

enum Direction {
  UP, DOWN, LEFT, RIGHT
};

class Board {

public:
  int gridState[BOARD_SIZE][BOARD_SIZE];

  // Constructor
  Board() {
    for(int i = 0; i < BOARD_SIZE; i++) {
      for(int j = 0; j < BOARD_SIZE; j++) {
        gridState[i][j] = 0;
      }
    }
  };

  // Sets the tile at location (x, y) to value v.
  void setTile(int x, int y, int v);

  // Initiates a slide move with the specified direction
  void slideBoard(Direction d);

  // Initiates a tile slide with the specified direction
  void slideTile(int x, int y, Direction d);

  // Prints out contents of board
  void printBoard();
};

#endif