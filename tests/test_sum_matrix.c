#include "../matrix_test.h"

START_TEST(test_sum_success) {
  matrix_t A, B, result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;

  B.matrix[0][0] = 4;
  B.matrix[0][1] = 5;
  B.matrix[1][0] = 6;
  B.matrix[1][1] = 7;

  int code = s21_sum_matrix(&A, &B, &result);

  ck_assert_int_eq(code, 0);
  ck_assert_double_eq(result.matrix[0][0], 5);
  ck_assert_double_eq(result.matrix[0][1], 7);
  ck_assert_double_eq(result.matrix[1][0], 9);
  ck_assert_double_eq(result.matrix[1][1], 11);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_sum_diff_size) {
  matrix_t A, B, result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(3, 3, &B);

  int code = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(code, 2);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 3, &B);

  code = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(code, 2);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_sum_null_ptr) {
  matrix_t matrix, result;
  int code = s21_sum_matrix(NULL, NULL, &result);
  ck_assert_int_eq(code, 1);

  s21_create_matrix(3, 3, &matrix);
  code = s21_sum_matrix(&matrix, NULL, &result);
  ck_assert_int_eq(code, 1);

  code = s21_sum_matrix(NULL, &matrix, &result);
  ck_assert_int_eq(code, 1);

  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(test_sum_null_matrix) {
  matrix_t A, B, result;
  s21_create_matrix(1, 1, &B);
  B.matrix[0][0] = 1;
  A.matrix = NULL;

  int code = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(code, 1);

  code = s21_sum_matrix(&B, &A, &result);
  ck_assert_int_eq(code, 1);

  code = s21_sum_matrix(&A, &A, &result);
  ck_assert_int_eq(code, 1);

  s21_remove_matrix(&B);
}
END_TEST

Suite *create_s21_sum_matrix(void) {
  Suite *suite = suite_create("s21_sum_matrix");

  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_sum_success);
  tcase_add_test(tc_core, test_sum_diff_size);
  tcase_add_test(tc_core, test_sum_null_ptr);
  tcase_add_test(tc_core, test_sum_null_matrix);
  suite_add_tcase(suite, tc_core);

  return suite;
}
