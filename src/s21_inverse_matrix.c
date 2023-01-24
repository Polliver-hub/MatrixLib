#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int res = OK;
  if (!s21_check(A)) {
    res = INCORRECT_MATRIX;
  } else {
    double d = 0;
    matrix_t adj = {0};
    matrix_t transposed = {0};
    if (!s21_check_squareness(A))
      res = CALCULATION_ERROR;
    else if (s21_determinant(A, &d) || fabs(d) < 1e-6)
      res = CALCULATION_ERROR;
    else if (s21_calc_complements(A, &adj))
      res = CALCULATION_ERROR;
    else if (s21_transpose(&adj, &transposed) ||
             s21_create_matrix(A->rows, A->columns, result))
      res = CALCULATION_ERROR;
    else
      for (int i = 0; i < A->rows; ++i)
        for (int j = 0; j < A->columns; ++j)
          result->matrix[i][j] = transposed.matrix[i][j] / d;
    s21_remove_matrix(&transposed);
    s21_remove_matrix(&adj);
  }
  return res;
}
