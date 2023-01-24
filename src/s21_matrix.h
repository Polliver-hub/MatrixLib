#ifndef SRC_S21_MATRIX_H
#define SRC_S21_MATRIX_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum { OK, INCORRECT_MATRIX, CALCULATION_ERROR } returns;

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

// Создание матриц
int s21_create_matrix(int rows, int columns, matrix_t *result);
// Очистка матриц
void s21_remove_matrix(matrix_t *A);
// Сравнение матриц
#define SUCCESS 1
#define FAILURE 0
int s21_eq_matrix(matrix_t *A, matrix_t *B);
// Сложение и вычитание
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
// Умножение
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
// Транспонирование
int s21_transpose(matrix_t *A, matrix_t *result);
// Минор матрицы и матрица алгебраических дополнений
int s21_calc_complements(matrix_t *A, matrix_t *result);
// Определитель матрицы
int s21_determinant(matrix_t *A, double *result);
// Обратная матрица
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

// Вспомогательные функции

// Проверка матрицы на существование
int s21_check(matrix_t *A);
// Проверка матриц на размерность
int s21_check_size(matrix_t *A, matrix_t *B);
// Проверка матрицы на квадратность
int s21_check_squareness(matrix_t *A);
// Функция подсчета детерминанта
double s21_det(double **m, int size);
// Функция удаления строки(skip_row) и столбца(skip_col) из исходной матрицы m,
// результат записывается в матрицу tmp
void s21_matrix_minus_row_col(double **m, double **tmp, int skip_row,
                              int skip_col, int size);
// Алгебраическое дополнение
void s21_alg_dop(matrix_t *A, matrix_t *result);

#endif  //  SRC_S21_MATRIX_H