#include "../matrix_test.h"

START_TEST(success_mult_simple_matrix) {
  matrix_t A, B, result;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[0][2] = 3;
  B.matrix[1][0] = 4;
  B.matrix[1][1] = 5;
  B.matrix[1][2] = 6;
  B.matrix[2][0] = 7;
  B.matrix[2][1] = 8;
  B.matrix[2][2] = 9;

  int code = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(code, 0);

  ck_assert_double_eq(result.matrix[0][0], 30);
  ck_assert_double_eq(result.matrix[0][1], 36);
  ck_assert_double_eq(result.matrix[0][2], 42);
  ck_assert_double_eq(result.matrix[1][0], 66);
  ck_assert_double_eq(result.matrix[1][1], 81);
  ck_assert_double_eq(result.matrix[1][2], 96);
  ck_assert_double_eq(result.matrix[2][0], 102);
  ck_assert_double_eq(result.matrix[2][1], 126);
  ck_assert_double_eq(result.matrix[2][2], 150);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_null_ptr) {
  matrix_t A, B;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);

  int code = s21_mult_matrix(NULL, NULL, NULL);
  ck_assert_int_eq(code, 1);

  code = s21_mult_matrix(&A, NULL, NULL);
  ck_assert_int_eq(code, 1);

  code = s21_mult_matrix(&A, &B, NULL);
  ck_assert_int_eq(code, 1);

  code = s21_mult_matrix(&A, NULL, &B);
  ck_assert_int_eq(code, 1);

  code = s21_mult_matrix(NULL, &A, &B);
  ck_assert_int_eq(code, 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_null_matrix) {
  matrix_t A, B;
  s21_create_matrix(1, 1, &B);
  A.matrix = NULL;

  // NULL NULL
  int code = s21_mult_matrix(&A, &A, &B);
  ck_assert_int_eq(code, 1);

  // NULL
  code = s21_mult_matrix(&A, &B, &B);
  ck_assert_int_eq(code, 1);

  // NULL
  code = s21_mult_matrix(&B, &A, &B);
  ck_assert_int_eq(code, 1);

  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_incorect_size) {
  matrix_t A, B, result;
  s21_create_matrix(1, 3, &A);
  s21_create_matrix(1, 4, &B);

  int code = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(code, 2);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *create_s21_mult_matrix(void) {
  Suite *suite = suite_create("s21_mult_matrix");

  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, success_mult_simple_matrix);
  tcase_add_test(tc_core, test_null_ptr);
  tcase_add_test(tc_core, test_null_matrix);
  tcase_add_test(tc_core, test_incorect_size);
  suite_add_tcase(suite, tc_core);

  return suite;
}
