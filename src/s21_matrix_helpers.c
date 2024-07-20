#include "s21_matrix.h"

int is_equal_demensions(matrix_t *A, matrix_t *B) {
  return (A->rows == B->rows) && (A->columns == B->columns);
}

int is_correct_matrix(matrix_t *matrix) {
  return matrix && matrix->matrix && (matrix->rows > 0) &&
         (matrix->columns > 0);
}

double get_determinant(matrix_t *A) {
  double result = 0.0;
  int sign = 1;
  if (A->rows == 1) {
    result = A->matrix[0][0];
  } else {
    matrix_t temp = {0};
    if (s21_create_matrix(A->rows - 1, A->columns - 1, &temp) == OK) {
      for (int i = 0; i < A->columns; i++) {
        get_matrix(0, i, A, &temp);
        result += sign * A->matrix[0][i] * get_determinant(&temp);
        sign = -sign;
      }
    }
    s21_remove_matrix(&temp);
  }
  return result;
}

void get_matrix(int row, int column, matrix_t *A, matrix_t *result) {
  int new_row = 0, new_column = 0;
  for (int i = 0; i < A->rows; i++) {
    if (i == row) continue;
    for (int j = 0; j < A->columns; j++) {
      if (j == column) continue;
      result->matrix[new_row][new_column] = A->matrix[i][j];
      new_column++;
    }
    new_column = 0;
    new_row++;
  }
}

int is_inf_or_nan(matrix_t *A) {
  int flag = OK;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (isinf(A->matrix[i][j]) || isnan(A->matrix[i][j])) {
        flag = 1;
        break;
      }
      if (flag) break;
    }
  }
  return flag;
}