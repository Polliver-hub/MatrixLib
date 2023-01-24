#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int res = OK;
  if (!s21_check(A) || !result)
    res = INCORRECT_MATRIX;
  else if (!s21_check_squareness(A))
    res = CALCULATION_ERROR;
  else
    *result = s21_det(A->matrix, A->rows);
  return res;
}
