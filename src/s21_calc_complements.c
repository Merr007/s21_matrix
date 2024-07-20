#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int flag = OK;
  if (!is_correct_matrix(A)) {
    flag = INCORRECT_MATRIX;
  } else if (is_inf_or_nan(A) || A->rows != A->columns || (A->rows == 1) ||
             (A->columns == 1)) {
    flag = COMPUTATIONAL_ERROR;
  } else {
    flag = s21_create_matrix(A->columns, A->rows, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        double det = 0.0;
        matrix_t minor_matrix = {0};
        s21_create_matrix(A->rows - 1, A->columns - 1, &minor_matrix);
        get_matrix(i, j, A, &minor_matrix);
        s21_determinant(&minor_matrix, &det);
        result->matrix[i][j] = pow(-1, (i + j)) * det;
        s21_remove_matrix(&minor_matrix);
      }
    }
  }
  return flag;
}