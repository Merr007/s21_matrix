#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int flag = OK;
  *result = 0.0;
  if (!is_correct_matrix(A)) {
    flag = INCORRECT_MATRIX;
  } else if (A->rows != A->columns) {
    flag = COMPUTATIONAL_ERROR;
  } else {
    *result = A->rows == 1 ? A->matrix[0][0] : get_determinant(A);
  }
  return flag;
}
