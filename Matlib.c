#include "Matlib.h"

void swap(double *a, double *b) {
  double temp = *a;
  *a = *b;
  *b = temp;
}

void CreateMatrix(Matrix *a, size_t row, size_t col) {
  a->row = row, a->col = col;
  if (a->row == a->col)
    a->isSquare = 1;
  else
    a->isSquare = 0;
  a->data = (double *)malloc(a->row * a->col * sizeof(double));
  for (size_t i = 0; i < a->row * a->col; i++) {
    a->data[i] = 0.0;
  }
}

void ArrToMat(Matrix *a, size_t row, size_t col, double *arr, size_t arr_size) {
  assert(row * col == arr_size);
  // memory leak issue here
  CreateMatrix(a, row, col);
  for (size_t i = 0; i < row; i++) {
    for (size_t j = 0; j < col; j++) {
      a->data[i * col + j] = arr[i * col + j];
    }
  }
}

void DeleteMatrix(Matrix *A) { free(A->data); }

void PrintMatrix(Matrix *A) {
  for (size_t i = 0; i < A->row; i++) {
    for (size_t j = 0; j < A->col; j++) {
      printf("%lf\t", A->data[i * A->col + j]);
    }
    printf("\n");
  }
  printf("\n");
}

void IdentityMatrix(Matrix *a, size_t row, size_t col) {
  assert(row == col);
  CreateMatrix(a, row, col);
  for (size_t i = 0; i < a->row; i++) {
    for (size_t j = 0; j < a->col; j++) {
      if (i == j)
        a->data[i * a->col + j] = 1.0;
      else
        a->data[i * a->col + j] = 0.0;
    }
  }
}

void Ones(Matrix *A, size_t row, size_t col) {
  CreateMatrix(A, row, col);
  for (size_t i = 0; i < A->row * A->col; i++)
    A->data[i] = 1.0;
}

void MatrixMultiplication(Matrix *A, Matrix *B, Matrix *C) {

  assert(A->col == B->row);
  CreateMatrix(C, A->row, B->col);

  for (size_t i = 0; i < A->row; i++) {
    for (size_t j = 0; j < B->col; j++) {
      for (size_t k = 0; k < A->col; k++) {
        C->data[i * B->col + j] +=
            A->data[i * A->col + k] * B->data[k * B->col + j];
      }
    }
  }

  if (C->row == C->col)
    C->isSquare = 1;
  else
    C->isSquare = 0;
}

void Join2Matrices(Matrix *A, Matrix *B, Matrix *C) {
  assert(A->row == B->row);
  CreateMatrix(C, A->row, A->col + B->col);
  for (size_t i = 0; i < C->row; i++) {
    for (size_t j = 0; j < A->col; j++) {
      C->data[i * C->col + j] = A->data[i * A->col + j];
    }
  }
  for (size_t i = 0; i < C->row; i++) {
    for (size_t j = A->col; j < C->col; j++) {
      C->data[i * C->col + j] = B->data[i * B->col + j - A->col];
    }
  }
}

void MatrixRowSwap(Matrix *A, size_t row1, size_t row2) {
  assert(A->row > row1 && A->row > row2);
  for (size_t i = 0; i < A->col; i++) {
    /*double temp = A->data[row1*A->col + i];
    A->data[row1*A->col + i] = A->data[row2*A->col + i];
    A->data[row2*A->col + i] = temp;*/
    swap(&A->data[row1 * A->col + i], &A->data[row2 * A->col + i]);
  }
}

size_t *GetDimension(Matrix *A) {
  size_t *dims = calloc(2, sizeof(size_t));
  dims[0] = A->row;
  dims[1] = A->col;
  return dims;
}

void Transpose(Matrix *A, Matrix *B) {
  // assert(A->isSquare == 1);
  CreateMatrix(B, A->col, A->row);

  for (size_t i = 0; i < A->row; i++) {
    for (size_t j = 0; j < A->col; j++) {
      B->data[j * A->row + i] = A->data[i * A->col + j];
    }
  }
}

void GaussJordanElim(Matrix *AugMat) {
  size_t r = AugMat->row;
  size_t c = AugMat->col;
  for (size_t i = 0; i < r; i++) {
    for (size_t j = 0; j < r; j++) {
      if (i != j) {
        double fac = AugMat->data[j * c + i] / AugMat->data[i * c + i];
        for (size_t z = 0; z < c; z++) {
          AugMat->data[j * c + z] =
              AugMat->data[j * c + z] - (fac * AugMat->data[i * c + z]);
        }
      }
    }
  }
  for (size_t i = 0; i < r; i++) {
    double f = AugMat->data[i * c + i];
    for (size_t j = 0; j < c; j++) {
      AugMat->data[i * c + j] = AugMat->data[i * c + j] / f;
    }
  }
}

void GaussianElim(Matrix *AugmentMatrix) {
  size_t row = AugmentMatrix->row;
  size_t col = AugmentMatrix->col;

  for (size_t i = 0; i < row; i++) {
    for (size_t j = 0; j < row; j++) {
      if (j > i) {
        double frac =
            AugmentMatrix->data[j * col + i] / AugmentMatrix->data[i * col + i];
        for (size_t k = 0; k < col; k++) {
          AugmentMatrix->data[j * col + k] =
              AugmentMatrix->data[j * col + k] -
              (frac * AugmentMatrix->data[i * col + k]);
        }
      }
    }
  }
  double *sol = malloc(row * sizeof(double));

  for (size_t i = row - 1; i >= 0; i--) {
    for (size_t j = 0; j < col; j++) {
    }
  }
}
