#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int flag = OK;
  int single_matrix = 0;

  if (A->rows <= 0 || A->columns <= 0)
    flag = INCORRECT_MATRIX;

  else if (A->rows != A->columns)
    flag = COMPUTATIONAL_ERROR;

  else if (A->rows == 1 && A->columns == 1) {
    if (A->matrix[0][0] != 0) {
      s21_create_matrix(1, 1, result);
      result->matrix[0][0] = 1 / A->matrix[0][0];
      single_matrix = 1;
    } else
      flag = COMPUTATIONAL_ERROR;
  }

  if (flag == OK && !single_matrix) {
    double det = 0;
    s21_determinant(A, &det);
    if (det != 0) {
      matrix_t compl_matrix, transposed;
      s21_calc_complements(A, &compl_matrix);
      s21_transpose(&compl_matrix, &transposed);
      s21_mult_number(&transposed, 1 / det, result);
      s21_remove_matrix(&compl_matrix);
      s21_remove_matrix(&transposed);
    } else
      flag = COMPUTATIONAL_ERROR;
  }
  return flag;
}