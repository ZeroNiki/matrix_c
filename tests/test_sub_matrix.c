#include "../matrix_test.h"

START_TEST(test_sub_success) {
  matrix_t A, B, result;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  A.matrix[0][0] = 5;
  A.matrix[0][1] = 7;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 9;

  B.matrix[0][0] = 2;
  B.matrix[0][1] = 1;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 4;

  int code = s21_sub_matrix(&A, &B, &result);
  ck_assert_int_eq(code, ZERO);
  ck_assert_double_eq(result.matrix[0][0], 3);
  ck_assert_double_eq(result.matrix[0][1], 6);
  ck_assert_double_eq(result.matrix[1][0], 0);
  ck_assert_double_eq(result.matrix[1][1], 5);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

Suite *create_s21_sub_matrix(void) {
  Suite *suite = suite_create("s21_sub_matrix");

  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_sub_success);
  suite_add_tcase(suite, tc_core);
  return suite;
}
