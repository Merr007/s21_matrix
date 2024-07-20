#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int flag = SUCCESS;
  if (!is_correct_matrix(A) || !is_correct_matrix(B) ||
      (A->columns != B->columns) || (A->rows != B->rows)) {
    flag = FAILURE;
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-07) flag = FAILURE;
      }
    }
  }
  return flag;
}