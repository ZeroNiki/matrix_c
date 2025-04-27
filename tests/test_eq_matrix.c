#include "../matrix_test.h"

START_TEST(test_eq_matrix_same) {
  matrix_t A, B;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[1][0] = 3.0;
  A.matrix[1][1] = 4.0;

  B.matrix[0][0] = 1.0;
  B.matrix[0][1] = 2.0;
  B.matrix[1][0] = 3.0;
  B.matrix[1][1] = 4.0;

  ck_assert_int_eq(s21_eq_matrix(&A, &B), 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *create_s21_eq_matrix(void) {
  Suite *suite = suite_create("s21_eq_matrix");

  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_eq_matrix_same);
  suite_add_tcase(suite, tc_core);

  return suite;
}
