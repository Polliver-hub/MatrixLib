#include "s21_matrix.h"

int s21_check(matrix_t *A) { return A && A->rows > 0 && A->columns > 0; }

int s21_check_size(matrix_t *A, matrix_t *B) {
  return A->rows == B->rows && A->columns == B->columns;
}

int s21_check_squareness(matrix_t *A) { return A->rows == A->columns; }

void s21_matrix_minus_row_col(double **m, double **tmp, int skip_row,
                              int skip_col, int size) {
  for (int i = 0, row = 0; row < size; ++row) {
    for (int j = 0, col = 0; col < size; ++col) {
      if (row != skip_row && col != skip_col) {
        tmp[i][j] = m[row][col];
        ++j;
        j == size - 1 ? j = 0, ++i : 0;
      }
    }
  }
}

double s21_det(double **m, int size) {
  double res = 0;
  int sign = 1;
  matrix_t tmp = {0};
  if (size == 1) {
    res = m[0][0];
  } else {
    if (s21_create_matrix(size, size, &tmp)) {
      res = 0;
    } else {
      for (int i = 0; i < size; ++i) {
        s21_matrix_minus_row_col(m, tmp.matrix, 0, i, size);
        res += sign * m[0][i] * s21_det(tmp.matrix, size - 1);
        sign = -sign;
      }
    }
    s21_remove_matrix(&tmp);
  }
  return res;
}

void s21_alg_dop(matrix_t *A, matrix_t *result) {
  if (A->rows == 1) {
    result->matrix[0][0] = 1;
  } else {
    matrix_t tmp = {0};
    if (s21_create_matrix(A->rows, A->rows, &tmp)) {
    } else {
      for (int i = 0, sign = 1; i < A->rows; ++i) {
        for (int j = 0; j < A->columns; ++j) {
          s21_matrix_minus_row_col(A->matrix, tmp.matrix, i, j, A->rows);
          sign = ((i + j) % 2 == 0) ? 1 : -1;
          result->matrix[i][j] = sign * s21_det(tmp.matrix, A->rows - 1);
        }
      }
    }
    s21_remove_matrix(&tmp);
  }
}