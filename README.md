# Linear Algebra Library in C

## This is a hobby project which helped me understand coding concepts like pointers and memory management in C language while learning Linear Algebra.

### Functions provided by this Library are the followings:

- **CreateMatrix** - takes Matrix struct pointer, row, column as argument and creates a matrix
- **ArrToMat** - takes Matrix struct pointer, row, column, array, size of array as argument and creates a matrix from the array
- **DeleteMatrix** - takes a Matrix struct pointer and deletes the matrix
- **PrintMatrix** - takes a Matrix struct pointer and prints the matrix
- **IdentityMatrix** - takes Matrix struct pointer, row, column as argument and creates an Identity matrix
- **Ones** - takes Matrix struct pointer, row, column as argument and creates a matrix with entries filled with 1
- **MatrixMultiplication** - takes two Matrix struct pointers as argument and multiplies those storing the values in a new matrix
- **MatrixRowSwap** - takes Matrix struct pointer, row1, row2 as argument and swaps row1 with row2
- **Join2Matrices** - takes two Matrix struct pointers as argument and creates a matrix by joining the inputs
- **Transpose** - takes two Matrix struct pointers as argument and creates a matrix storing the transposition of the first input
- **GetDimension** - takes Matrix struct pointer as argument and creates an array containing the dimensions
- **GaussianElim** - takes a Matrix struct pointer of an Augment matrix as argument and performs Gaussian Elimination on input
- **GaussJordanElim** - takes a Matrix struct pointer of an Augment matrix as argument and performs Gauss-Jordan Elimination on input

To use this library just put the **Matlib.c and Matlib.h** file in your project directory and don't forget to link math library while compiling your project

### warning: This library only deals with 2D Matrices and not complete yet
