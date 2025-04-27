#include "../matrix_test.h"

START_TEST(test_remove_matrix) {
  matrix_t mat;
  int result = s21_create_matrix(3, 3, &mat);
  ck_assert_int_eq(result, 0);

  s21_remove_matrix(&mat);
  ck_assert_ptr_null(mat.matrix);
}

START_TEST(test_remove_null_matrix) {
  matrix_t *mat = NULL;
  s21_remove_matrix(mat);
}
END_TEST

START_TEST(test_remove_null_data_matrix) {
  matrix_t mat;
  mat.matrix = NULL;
  mat.rows = 5;
  s21_remove_matrix(&mat);
}
END_TEST

Suite *create_s21_remove_matrix(void) {
  Suite *suite = suite_create("s21_matrix_remove");

  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_remove_matrix);
  tcase_add_test(tc_core, test_remove_null_matrix);
  tcase_add_test(tc_core, test_remove_null_data_matrix);
  suite_add_tcase(suite, tc_core);

  return suite;
}
