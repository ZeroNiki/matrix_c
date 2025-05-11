#ifndef MATRIX_TEST_H
#define MATRIX_TEST_H

#include <check.h>

#include "./s21_matrix.h"

Suite *create_s21_create_matrix(void);
Suite *create_s21_remove_matrix(void);
Suite *create_s21_eq_matrix(void);
Suite *create_s21_sum_matrix(void);
Suite *create_s21_sub_matrix(void);
Suite *create_s21_mult_number(void);
Suite *create_s21_mult_matrix(void);

#endif
