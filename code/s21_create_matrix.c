#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (rows <= 0 || columns <= 0) {
    return ONE;
  }

  result->rows = rows;
  result->cols = columns;

  result->matrix = malloc(rows * sizeof(double *));

  for (int i = 0; i < rows; i++) {
    result->matrix[i] = calloc(columns, sizeof(double));
  }

  return ZERO;
}
