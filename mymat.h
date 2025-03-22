#include <stdio.h>
#include <stdlib.h> /* calloc() , atof() */
#include <string.h> /* strncmp() */
#include <ctype.h>  /* is space() */
#include <limits.h> /* LONG_MAX */

#define SIZE_MAT_ROWS_AND_COLUMNS 4 /* Rows and collumn length */
#define SIZE_OF_MATS 6 /* Number of matrixes that created */

/* Command names type - Uses to check the number of command to use. */
typedef enum Command {
	READ_MAT,
	PRINT_MAT,
	ADD_MAT,
	SUB_MAT,
	MUL_MAT,
	MUL_SCALAR,
	TRANS_MAT,
	STOP,
	ERROR_COMMAND,
	INPUT_ERROR
}Command;

/* Matrix name type - Uses to check the number of matrix to use. */
typedef enum MatrixName {
	MAT_A,
	MAT_B,
	MAT_C, 
	MAT_D,
	MAT_E,
	MAT_F,
	ERROR
}MatrixName;

/* Defined 4x4 Matrix struct. */
typedef struct Matrix {
	double data[SIZE_MAT_ROWS_AND_COLUMNS][SIZE_MAT_ROWS_AND_COLUMNS];
}Matrix;

/* Function that returns a pointer to array of 6 Matrices. Each matrix double parameter defined to be 0. */ 
Matrix* createMatrixArray();

/* Function that getting double Array and  fill that parameters in Matrix matToRead. */
void executeMatToRead(double* readFrom, Matrix* matToRead);

/* Function that print the Matrix toPrint. */
void executeMatToPrint(Matrix toPrint);

/* Function that gets two Matrices and a Comand and performs mathematic calculation defined in Command. The command are adding, substract 
or miltiplication. The result entered to Matrix result*/
void executeMatOperaion(Command comand, Matrix first, Matrix second, Matrix* result);

/* Function that getting Matrix and scalar and perform their multiplication. The result is entered to Matrix result.*/
void executeMatMulScalar(Matrix first, double scalar, Matrix* result);

/* Function that getting Matrix first and perfroms its transformation. The result entered to Matrix result. */ 
void executeMatTransOperation(Matrix first, Matrix* result);

/* Function that stops the program. */
void executeStop();

