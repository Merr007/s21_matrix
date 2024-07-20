#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int flag = OK;
  if (!is_correct_matrix(A) || !is_correct_matrix(B)) {
    flag = INCORRECT_MATRIX;
  } else if (A->columns != B->rows || is_inf_or_nan(A) || is_inf_or_nan(B)) {
    flag = COMPUTATIONAL_ERROR;
  } else {
    flag = s21_create_matrix(A->rows, B->columns, result);
    if (flag == OK) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < B->columns; j++) {
          result->matrix[i][j] = 0;
          for (int k = 0; k < B->rows; k++)
            result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
        }
      }
    }
  }
  return flag;
}