#ifndef MATLIB
#define MATLIB

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Matrix Matrix;

struct Matrix {
  size_t row;
  size_t col;
  size_t isSquare;
  double *data;
};

void CreateMatrix(Matrix *A, size_t row, size_t col);
void ArrToMat(Matrix *a, size_t row, size_t col, double *arr, size_t arr_size);
void DeleteMatrix(Matrix *A);
void PrintMatrix(Matrix *A);
void IdentityMatrix(Matrix *A, size_t row, size_t col);
void Ones(Matrix *A, size_t row, size_t col);
void MatrixMultiplication(Matrix *A, Matrix *B, Matrix *C);
void MatrixRowSwap(Matrix *A, size_t row1, size_t row2);
void Join2Matrices(Matrix *A, Matrix *B, Matrix *C);
void Transpose(Matrix *A, Matrix *B);
size_t *GetDimension(Matrix *A);
void GaussianElim(Matrix *AugmentMatrix);
void GaussJordanElim(Matrix *AugMat);

#endif
