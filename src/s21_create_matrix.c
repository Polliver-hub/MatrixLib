#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int res = OK;
  if (rows <= 0 || columns <= 0 || result == NULL) {
    res = INCORRECT_MATRIX;
  } else {
    result->matrix = calloc(rows, sizeof(double *));
    if (result->matrix == NULL) res = INCORRECT_MATRIX;
    for (int i = 0; i < rows; i++) {
      result->matrix[i] = calloc(columns, sizeof(double));
      if (result->matrix[i] == NULL) res = INCORRECT_MATRIX;
    }
    result->rows = rows;
    result->columns = columns;
  }
  return res;
}