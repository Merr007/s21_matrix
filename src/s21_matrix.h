#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// eq_matrix
#define SUCCESS 1
#define FAILURE 0

// others
#define OK 0
#define INCORRECT_MATRIX 1
#define COMPUTATIONAL_ERROR 2

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

// init
int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);

// compare
int s21_eq_matrix(matrix_t *A, matrix_t *B);

// arithmetics
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);

// others
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);
int is_equal_demensions(matrix_t *A, matrix_t *B);
int is_correct_matrix(matrix_t *matrix);
double get_determinant(matrix_t *A);
void get_matrix(int row, int column, matrix_t *A, matrix_t *result);
int is_inf_or_nan(matrix_t *A);

#endif
