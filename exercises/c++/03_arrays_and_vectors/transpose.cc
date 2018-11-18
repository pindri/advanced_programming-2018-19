#include <iomanip>
#include <iostream>
#include <array>


template <typename T>
void print_matrix (T matrix, int row, int col);

template <typename T>
T transp_matrix (T matrix, int row, int col);

int main(){

  const int row = 3, col = 7;
  const int N = row * col;

  std::array<double, N> matrix;
  std::array<double, N> transp;

  for (int i{0}; i<N; i++) { //the array is filled with numbers
    matrix[i] = double(i);
  }

  print_matrix(matrix, row, col);

  transp = transp_matrix(matrix, row, col);

  std::cout << "Transposed matrix" << std::endl;
 
  print_matrix(transp, col, row);

}





template <typename T>
void print_matrix (T matrix, int row, int col){
  for (int i{0}; i<row; i++){
    for (int j{0}; j<col; j++)
      std::cout << std::setw(2) << matrix[i * col + j] << " ";
    std::cout << std::endl;
  }
}


template <typename T>
T transp_matrix (T matrix, int row, int col){
  T tr_matrix;
  for (int i{0}; i<row; i++){
    for (int j{0}; j<col; j++)
      tr_matrix[j * row + i] = matrix[i * col + j];
  }
  return tr_matrix;
}
