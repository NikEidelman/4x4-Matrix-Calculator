/*************************************************************

Matrix Calculator 4x4.
Author: Eidelman Nikolay i.d 320951866.
revision: 23.5.2022.

**************************************************************/

/* All functions explaine in files mymat.h,input.h, other parameters explaint in files mymat.c and input.c*/

#include "input.h"

int main()
 {

	Matrix* matrixArr = createMatrixArray();

	char* input = NULL;
	int matA, matB, matC; /* Matrices that used in calculations or in other commands.*/
	double* readFrom, scalar;
	printf("\t\tHello!!! You are using 4x4 matrix calculator.\n\n\t**To start using the calculator please enter your command.**\n\t***To exit from calculator please enter the command: stop***\n\n");
	do {
		input = get_line(); /* getting input from user. */
		if (input != NULL)
		{			
			Command command = getCommand(&input);	/* getting command from input.*/
			switch (command) /* Used switch for each command. */
			{
			case READ_MAT: /* should appear Matrix and double parameters. */
			{
				matA = getMatrixNameFromInput(&input, 1); /* getting matrix that should be filled by real numbers.*/
				if ((matA != ERROR) && (matA != INPUT_ERROR))
				{
					readFrom = getNumbersArray(&input); /* getting double array.*/
					if (readFrom)
					{
						executeMatToRead(readFrom, &matrixArr[matA]);
						free(readFrom);
					}
				}
				break;
			}
			case PRINT_MAT:
			{
				matA = getMatrixNameFromInput(&input, 0); /* getting matrix that should be printed.*/
				if ((matA != ERROR) && (matA != INPUT_ERROR))
				{
					executeMatToPrint(matrixArr[matA]);
					printMatName(matA);
				}
				break;
			}
			case MUL_MAT:
			case SUB_MAT:
			case ADD_MAT: 
			{
				matA = getMatrixNameFromInput(&input,1); /*Matrix for calculation.*/
				if ((matA != ERROR) && (matA != INPUT_ERROR))
				{
					matB = getMatrixNameFromInput(&input, 1);/*Matrix for addind, substracting or multiplication.*/
					if ((matB != ERROR) && (matB != INPUT_ERROR))
					{
						matC = getMatrixNameFromInput(&input, 0); /*Matrix that result filled in to.*/
						if ((matC != ERROR) && (matC != INPUT_ERROR))
						{
							executeMatOperaion(command,matrixArr[matA], matrixArr[matB], &matrixArr[matC]);
						}
					}
				}
				break;
			}
			case MUL_SCALAR:
			{
				matA = getMatrixNameFromInput(&input, 1); /* Matrix for multiplication by scalar.*/
				if (matA != ERROR && matA != INPUT_ERROR)
				{
					scalar = getScalar(&input); /* Scalar for multiplication.*/
					if (scalar != LONG_MAX)
					{
						matB = getMatrixNameFromInput(&input, 0);/*Matrix that result filled in to.*/
						if (matB != ERROR && matB != INPUT_ERROR)
						{
							executeMatMulScalar(matrixArr[matA], scalar, &matrixArr[matB]);
						}
					}
				}
				break;
			}
			case TRANS_MAT:
			{
				matA = getMatrixNameFromInput(&input, 1); /* Matrix for transformation.*/
					if((matA != ERROR) && (matA != INPUT_ERROR))
					{
						matB = getMatrixNameFromInput(&input, 0); /*Matrix that result filled in to.*/
						if ((matB != ERROR) && (matB != INPUT_ERROR))
						{
							executeMatTransOperation(matrixArr[matA], &matrixArr[matB]);
						}
					}
					break;
			}
			case STOP: 
			{
				free(matrixArr);
				executeStop();
				break;
			}
			case ERROR_COMMAND: /* Prints Error if command is not valid.*/
			{
				printf("ERROR: Undefined command name.\n\n");
				break;
			}
			case INPUT_ERROR: /*Command do nothing. Only errors from functions is printed if input is not valid.*/ 
				break;
			}
		}
	} while (input != NULL); /* the program running until command stop is entered or EOF. */
	
	return 0;
}



