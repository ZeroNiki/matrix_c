#include "../matrix_test.h"

START_TEST(test_valid_matrix) {
  matrix_t mat;
  int row = 3;
  int col = 3;
  int res = s21_create_matrix(row, col, &mat);

  ck_assert_int_eq(res, 0);
  ck_assert_int_eq(mat.rows, 3);
  ck_assert_int_eq(mat.cols, 3);
  ck_assert_ptr_nonnull(mat.matrix);

  for (int i = 0; i < mat.rows; i++) {
    ck_assert_ptr_nonnull(mat.matrix[i]);
  }

  s21_remove_matrix(&mat);
  ck_assert_ptr_null(mat.matrix);
}
END_TEST

START_TEST(test_invalid_matrix) {
  matrix_t mat;

  int result = s21_create_matrix(0, 3, &mat);
  ck_assert_int_eq(result, 1);

  result = s21_create_matrix(3, 0, &mat);
  ck_assert_int_eq(result, 1);

  result = s21_create_matrix(0, 0, &mat);
  ck_assert_int_eq(result, 1);

  result = s21_create_matrix(-123, -23, &mat);
  ck_assert_int_eq(result, 1);
}
END_TEST

Suite *create_s21_create_matrix(void) {
  Suite *suite = suite_create("s21_matrix_create");

  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_valid_matrix);
  tcase_add_test(tc_core, test_invalid_matrix);
  suite_add_tcase(suite, tc_core);

  return suite;
}
