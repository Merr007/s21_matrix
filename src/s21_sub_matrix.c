#include "s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int flag = OK;
  if (!is_correct_matrix(A) || !is_correct_matrix(B)) {
    flag = INCORRECT_MATRIX;
  } else if (!is_equal_demensions(A, B)) {
    flag = COMPUTATIONAL_ERROR;
  } else {
    flag = s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  }
  return flag;
}