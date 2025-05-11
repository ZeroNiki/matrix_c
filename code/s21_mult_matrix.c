#include "../s21_matrix.h"

/* Умножение матриц —
 * это когда каждая ячейка новой матрицы получается как сумма произведений
 * строк одной матрицы на столбцы другой. */

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (!A || !B || !result || !A->matrix || !B->matrix) {
    return ONE;
  }

  if (A->cols != B->rows) {
    return TWO;
  }

  s21_create_matrix(A->rows, B->cols, result);

  // C[i][j] = A[i][0] * B[0][j] + A[i][1] * B[i][j] + A[i][2] * B[2][j]
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < B->cols; j++) {
      for (int k = 0; k < A->cols; k++) {
        result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
      }
    }
  }

  return ZERO;
}
