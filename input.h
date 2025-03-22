#include "mymat.h"

#define FUNC_NUM 9 /* Number of commands */
#define LENGTH 100 /* The length of input from user. */
#define MAT_NAME_LENGTH 5 /* Length of Matrix name. */


/* Macro that prints error of extraneous text. */
#define EXTRANEOUS_TEXT\
	{\
		printf("Error: Extraneous text after end of command.\n\n");\
	}

/* Macro that prints error of missing parameter text. Return INPUT_ERROR(from enum Command)*/
#define MISSING_PARAMETER(ch) \
	if(ch == '\n' || ch == '\0'){\
		printf("Error: Missing argument.\n\n");\
		return INPUT_ERROR;\
	}

/* Macro that prints error of missing comma. */
#define MISSING_COMMA(ch) \
	if(ch != ','){ \
		printf("Error: Missing comma.\n\n");\
	}

/* Macro that prints error of multiple commas. */
#define MULTIPLE_COMMAS(ch) \
	if(ch == ','){ \
		printf("Error: Multiple consecutive commas.\n\n");\
	}

/* Macro that prints error of Undefined matrix. Return ERROR(from enum MatrixName) */
#define MISSING_MATRIX\
	{\
		printf("Error: Undefined matrix name.\n\n");\
		return ERROR;\
	}

/* Function that getting command from user. Return the input if there is command. Return NULL is input is empty. */
char* get_line();

/* Funtion that skip empty empty chars from begining of users input. Returns the pointer to the input without empty chars from beginning. */ 
void skip_spaces(char** line);

/* Function that looking for valid command from the user input. Return the int number of command (defined enum Commands). Return COMAND_ERROR if there is no such command.
Returns INPUT_ERROR if there errors in input of command. */
Command getCommand(char** line);

/* Function that looking for valid Matrix from the user input. Return the MatrixName number of Matrix (defined enum MatrixName)). Return ERROR if there is no such Matrix.
Returns INPUT_ERROR if there is errors in input of Matrix Name. */
MatrixName getMatrixNameFromInput(char** line, int isCommaShouldApperAtTheEnd);

/* Function that getting input and check if Matrix name valid, Return MatrixName number (defined enum MatrixName). */
MatrixName getMatrixByName(char* name);

/* Function that prints the name of Matrix that printed by function executeMatToPrint() */
void printMatName(int matName);

/* Function that getting a real number from input. Return is ErrorOccur 1 if the number is not real. Return the real numbers if input correct. */
double getNumber(char** line, int* isErrorOccur);

/* Function that getting the input and filling double array of 16 numbers from input. Return NULL if there one of the numbers is not a real number.
Return pointer do double array if input is correct. The array used in function executeMatToRead(). Function using function getNumber().*/ 
double* getNumbersArray(char** line);

/* Function that getting a real scalar from input. Return LONG_MAX if the number is not real. Return double scalar if input correct and number is real. Scalar used in function executeMatMulScalar().
Scalar can not be = LONG_MAX */
double getScalar(char** line);

