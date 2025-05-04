#include "../s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (A->matrix == NULL || B->matrix == NULL) {
    return ONE;
  }

  if (A->rows != B->rows || A->cols != B->cols) {
    return TWO;
  }

  if (s21_create_matrix(A->rows, A->cols, result) == ONE) {
    return ONE;
  }

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->cols; j++) {
      result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
    }
  }

  return ZERO;
}
