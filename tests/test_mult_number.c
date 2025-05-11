#include "../matrix_test.h"

START_TEST(success_mult_numbers) {
  matrix_t A, result;
  s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;
  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 5.0;
  A.matrix[1][2] = 6.0;
  A.matrix[2][0] = 7.0;
  A.matrix[2][1] = 8.0;
  A.matrix[2][2] = 9.0;

  int code = s21_mult_number(&A, 2, &result);

  ck_assert_int_eq(code, 0);
  ck_assert_double_eq(result.matrix[0][0], 2);
  ck_assert_double_eq(result.matrix[0][1], 4);
  ck_assert_double_eq(result.matrix[0][2], 6);

  ck_assert_double_eq(result.matrix[1][0], 8);
  ck_assert_double_eq(result.matrix[1][1], 10);
  ck_assert_double_eq(result.matrix[1][2], 12);

  ck_assert_double_eq(result.matrix[2][0], 14);
  ck_assert_double_eq(result.matrix[2][1], 16);
  ck_assert_double_eq(result.matrix[2][2], 18);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_null_ptr) {
  int code = s21_mult_number(NULL, 0, NULL);
  ck_assert_int_eq(code, 1);

  matrix_t smth;
  code = s21_mult_number(NULL, 100, &smth);
  ck_assert_int_eq(code, 1);

  code = s21_mult_number(&smth, 100, NULL);
  ck_assert_int_eq(code, 1);

  smth.matrix = NULL;
  code = s21_mult_number(&smth, 100, &smth);
  ck_assert_int_eq(code, 1);
}
END_TEST

Suite *create_s21_mult_number(void) {
  Suite *suite = suite_create("s21_mult_number");

  TCase *tcase_core = tcase_create("Core");
  tcase_add_test(tcase_core, success_mult_numbers);
  tcase_add_test(tcase_core, test_null_ptr);
  suite_add_tcase(suite, tcase_core);

  return suite;
}
