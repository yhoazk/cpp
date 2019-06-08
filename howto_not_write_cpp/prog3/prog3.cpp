#include <iostream>

const size_t M_SIZE = 3UL;
// array of references = &arr[]
// reference to array = (&arr)[]


static void matrix_multiply(
  int (&result)[M_SIZE][M_SIZE],
  int (&matrix1)[M_SIZE][M_SIZE],
  int (&matrix2)[M_SIZE][M_SIZE]
) {
  int row = 0;
  int col = 0;
  int element = 0;

  for(row =0; row < M_SIZE; row++){
    for(col =0; col < M_SIZE; col++){
      result[row][col] = 0;
      for(element = 0; element < M_SIZE; element++){
        result[row][col] +=
          matrix1[row][element] * matrix2[element][col];
      }
    }
  }
}

static void matrix_print( int matrix[M_SIZE][M_SIZE]){
  int row, col;
  for(row = 0; row < M_SIZE; ++row){
    for(col=0; col < M_SIZE; ++col){
      std::cout << matrix[row][col] << "\t";
    }
    std::cout << "\n";
  }
}

int main(void){
  int matrix_a[M_SIZE][M_SIZE] = {
    {45,82,26},
    {32,11,13},
    {89,81,25}
  };

  int matrix_b[M_SIZE][M_SIZE] = {
    {32,43,50},
    {33,40,52},
    {20,12,32}
  };

  int result[M_SIZE][M_SIZE];

  matrix_print(result);
  std::cout << "--------\n";
  matrix_multiply(result, matrix_a, matrix_b);
  matrix_print(result);
  return 0;
}
