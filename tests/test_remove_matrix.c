#include "../matrix_test.h"

START_TEST(test_remove_matrix) {
  matrix_t mat;
  int result = s21_create_matrix(3, 3, &mat);
  ck_assert_int_eq(result, 0);

  s21_remove_matrix(&mat);
  ck_assert_ptr_null(mat.matrix);
}

Suite *create_s21_remove_matrix(void) {
  Suite *suite = suite_create("s21_matrix_remove");

  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_remove_matrix);
  suite_add_tcase(suite, tc_core);

  return suite;
}
