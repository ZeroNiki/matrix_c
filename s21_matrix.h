#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <stdlib.h>
#include <math.h>

// Maximum permissible
#define EPS 1e-7
// Result code (sum, sub, mult, devide)
#define OK 0
#define INCORRECT_MATRIX 1
#define CALC_ERROR 2

// Result code (eq_matrix)
#define SUCCESS 1
#define FAILURE 0

typedef struct {
  double **matrix;
  int rows;
  int cols;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);

int s21_eq_matrix(matrix_t *A, matrix_t *B);

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

#endif
