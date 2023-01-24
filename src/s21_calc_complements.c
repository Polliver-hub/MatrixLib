#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int res = OK;
  if (!s21_check(A) || !result)
    res = INCORRECT_MATRIX;
  else if (!s21_check_squareness(A) || A->rows == 1)
    res = CALCULATION_ERROR;
  else if (s21_create_matrix(A->rows, A->columns, result) != OK)
    res = CALCULATION_ERROR;
  else
    s21_alg_dop(A, result);
  return res;
}