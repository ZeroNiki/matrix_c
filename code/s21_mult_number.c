#include "../s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  if (A == NULL || result == NULL || A->matrix == NULL) {
    return ONE;
  }

  s21_create_matrix(A->rows, A->cols, result);

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->cols; j++) {
      result->matrix[i][j] = A->matrix[i][j] * number;
    }
  }

  return ZERO;
}
