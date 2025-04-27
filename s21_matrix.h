#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <stdlib.h> 

#define SUCCESS 0
#define FAILURE 1
#define ERROR 2

typedef struct {
  double **matrix;
  int rows;
  int cols;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);

#endif
