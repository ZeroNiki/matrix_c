#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (rows <= 0 || columns <= 0) {
    return ONE;
  }

  result->rows = rows;
  result->cols = columns;

  result->matrix = (double **)calloc(rows, sizeof(int *));

  for (int i = 0; i < rows; i++) {
    result->matrix[i] = (double *)calloc(columns, sizeof(int));
  }

  return ZERO;
}
