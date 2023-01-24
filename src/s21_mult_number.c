#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int res = OK;
  if (!s21_check(A))
    res = INCORRECT_MATRIX;
  else if (s21_create_matrix(A->rows, A->columns, result) != OK)
    res = CALCULATION_ERROR;
  else
    for (int i = 0; i < A->rows; ++i)
      for (int j = 0; j < A->columns; ++j)
        result->matrix[i][j] = A->matrix[i][j] * number;
  return res;
}