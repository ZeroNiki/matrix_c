#include "../matrix_test.h"

START_TEST(test_eq_same_matrix) {
  matrix_t A, B;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  A.matrix[0][0] = 1.1234567;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 4.0;

  B.matrix[0][0] = 1.1234567;
  B.matrix[0][1] = 2.0;
  B.matrix[1][0] = 3.0;
  B.matrix[1][1] = 4.0;

  ck_assert_int_eq(s21_eq_matrix(&A, &B), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_diff_matrix) {
  matrix_t A, B;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 4.0;

  B.matrix[0][0] = 5.0;
  B.matrix[0][1] = 6.0;
  B.matrix[1][0] = 7.0;
  B.matrix[1][1] = 8.0;

  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_eq_diff_size) {
  matrix_t A, B;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(3, 2, &B);

  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(test_null) { ck_assert_int_eq(s21_eq_matrix(NULL, NULL), 0); }
END_TEST

START_TEST(test_null_matrix) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 4.0;

  ck_assert_int_eq(s21_eq_matrix(NULL, &A), 0);
  ck_assert_int_eq(s21_eq_matrix(&A, NULL), 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(test_eq_null_internal_matrix) {
  matrix_t A, B;
  A.matrix = NULL;
  A.rows = 2;
  A.cols = 2;

  B.matrix = NULL;
  B.rows = 2;
  B.cols = 2;

  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);
}
END_TEST

Suite *create_s21_eq_matrix(void) {
  Suite *suite = suite_create("s21_eq_matrix");

  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_eq_same_matrix);
  tcase_add_test(tc_core, test_eq_diff_matrix);
  tcase_add_test(tc_core, test_eq_diff_size);
  tcase_add_test(tc_core, test_null);
  tcase_add_test(tc_core, test_null_matrix);
  tcase_add_test(tc_core, test_eq_null_internal_matrix);
  suite_add_tcase(suite, tc_core);

  return suite;
}
