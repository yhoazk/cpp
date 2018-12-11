#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> grid;

#define GRID_COLS (7)
#define GRID_ROWS (3) /* only 3 rows */

int main(int argc, char const *argv[]) {
  /* Set the size of the grid, first columns */
  grid.resize(GRID_COLS);

  for (size_t i = 0; i < GRID_COLS; i++) {
    grid[i].resize(GRID_ROWS);
  }

  for (size_t i = 0; i < GRID_COLS; i++) {
    for (size_t j = 0; j < GRID_ROWS; j++) {
      grid[i][j] = '#';
    }
  }

  for (size_t k = 0; k < GRID_COLS; k++) {
    for (size_t l = 0; l < GRID_ROWS; l++) {
      std::cout << grid[k][l];
    }
    std::cout << std::endl;
  }
  return 0;
}
