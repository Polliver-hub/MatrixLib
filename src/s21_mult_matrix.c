#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = OK;
  if (!s21_check(A) || !s21_check(B))
    res = INCORRECT_MATRIX;
  else if (A->columns != B->rows ||
           s21_create_matrix(A->rows, B->columns, result) != OK)
    res = CALCULATION_ERROR;
  else
    for (int i = 0; i < A->rows; ++i) {
      for (int j = 0; j < B->columns; ++j) {
        for (int k = 0; k < A->columns; ++k)
          result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
      }
    }
  return res;
}