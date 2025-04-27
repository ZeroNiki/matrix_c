#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (rows <= 0 || columns <= 0) {
    return FAILURE;
  }

  result->rows = rows;
  result->cols = columns;

  result->matrix = (double **)calloc(rows, sizeof(int *));
  if (result->matrix == NULL) {
    return FAILURE;
  }

  for (int i = 0; i < rows; i++) {
    result->matrix[i] = (double *)calloc(columns, sizeof(int));
    if (result->matrix[i] == NULL) {
      s21_remove_matrix(result);
      return ERROR;
    }
  }

  return SUCCESS;
}
