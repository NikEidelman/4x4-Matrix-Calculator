/* All functions exlpained in file mymat.h */

#include "mymat.h"

Matrix* createMatrixArray() {
	int i, j, k;
	Matrix* result = (Matrix*)calloc(SIZE_OF_MATS, sizeof(Matrix));
	if (!result)
	{
		printf("\nError - Matrix calloc failed\n");
		exit(-1);
	}
	for (i = 0; i < SIZE_OF_MATS; i++)
	{
		for (j = 0; j < SIZE_MAT_ROWS_AND_COLUMNS; j++)
		{
			for (k = 0; k < SIZE_MAT_ROWS_AND_COLUMNS; k++)
			{
				result[i].data[j][k] = 0;
			}
		}
	}
	return result;
}

void executeMatToRead(double* readFrom, Matrix* matToRead)
{
	int i, j, indexOfArray = 0;

	for (i = 0; i < SIZE_MAT_ROWS_AND_COLUMNS; i++)
	{
		for (j = 0; j < SIZE_MAT_ROWS_AND_COLUMNS; j++)
		{
			(*matToRead).data[i][j] = readFrom[indexOfArray++];
		}
	}
	printf("Read Matrix suceed.\n\n");
}

void executeMatToPrint(Matrix toPrint)
{
	int i, j;
	for (i = 0; i < SIZE_MAT_ROWS_AND_COLUMNS; i++)
	{
		for (j = 0; j < SIZE_MAT_ROWS_AND_COLUMNS; j++)
		{
			
	
			printf("|");
			printf("%10.3f", toPrint.data[i][j]);
		}
		printf("|\n");
	}
}

void executeMatOperaion(Command command, Matrix first, Matrix second, Matrix* result) {

	int i, j,k;	
	if (command == ADD_MAT || command == SUB_MAT) 
	{
		for (i = 0; i < SIZE_MAT_ROWS_AND_COLUMNS; i++)
		{
			for (j = 0; j < SIZE_MAT_ROWS_AND_COLUMNS; j++)
			{
				if (command == ADD_MAT) {
					(*result).data[i][j] = first.data[i][j] + second.data[i][j];
				}
				else if (command == SUB_MAT)
				{
					(*result).data[i][j] = first.data[i][j] - second.data[i][j];
				}
				
			}
		}
		if (command == ADD_MAT) {
			printf("Matrix adding suceed.\n\n");;
		}
		else if (command == SUB_MAT)
		{
			printf("Matrix substraction suceed.\n\n");
		}
	}
	else if (command == MUL_MAT)
	{
		Matrix temp = { 0 };
		
		for (i = 0; i < SIZE_MAT_ROWS_AND_COLUMNS; i++)
		{
			for (j = 0; j < SIZE_MAT_ROWS_AND_COLUMNS; j++)
			{
				for (k = 0; k < SIZE_MAT_ROWS_AND_COLUMNS; k++)
				{
					temp.data[i][j] += first.data[i][k] * second.data[k][j];
				}
			}
		}
		for (i = 0; i < SIZE_MAT_ROWS_AND_COLUMNS; i++)
		{
			for (j = 0; j < SIZE_MAT_ROWS_AND_COLUMNS; j++)
			{
				(*result).data[i][j] = temp.data[i][j];
			}
		}
		printf("Matrix multiplication suceed.\n\n");
	}

}

void executeMatMulScalar(Matrix first, double scalar, Matrix* result)
{
	int i, j;
	for (i = 0; i < SIZE_MAT_ROWS_AND_COLUMNS; i++)
	{
		for (j = 0; j < SIZE_MAT_ROWS_AND_COLUMNS; j++)
		{
			if (scalar == 0 || first.data[i][j] == 0)
			{
				(*result).data[i][j] = 0;
			}
			else
			{
				(*result).data[i][j] = scalar * first.data[i][j];
			}
		}
	}
	printf("Matrix multiplication by scalar suceed.\n\n");
}

void executeMatTransOperation(Matrix first, Matrix* result)
{
	int i, j;
	double temp;
	for (i = 0; i < SIZE_MAT_ROWS_AND_COLUMNS; i++)
	{
		for (j = i; j < SIZE_MAT_ROWS_AND_COLUMNS; j++)
		{
			temp = first.data[i][j];
			(*result).data[i][j] = first.data[j][i];
			(*result).data[j][i] = temp;
		}
	}
	printf("Matrix transformation suceed.\n\n");
}

void executeStop()
{
	printf("\t\tProgram finished by User request.\n\t\t********Hope you enjoyed.********\n");
	exit(0);
}

