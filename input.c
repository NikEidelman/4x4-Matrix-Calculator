/* All functions explained in file input.h */

#include "input.h"

/* pointer to array of command names. */
static const char* command_names[] = { "read_mat","print_mat","add_mat","sub_mat","mul_mat","mul_scalar","trans_mat", "stop", "info"};

char* get_line()
{
	char* input = (char*)calloc(LENGTH, sizeof(char));
	if (!input)
	{
		printf("\nError - No space allocated for input\n");
		return NULL;
	}
	printf("\nPlease enter a command:\ncmd >> ");
	if(fgets(input,LENGTH, stdin) == NULL)
	{
		printf("\n\t\t*Program reached EOF and stopped*\n");  /* prints the error if commands read from file and reched EOF */
		printf("\t\t********Hope you enjoyed.********\n");
		return NULL;
	}
	else
	{
		printf("\nCommand entered: %s\n", input);
		return input;
	}
	return input;
}

void skip_spaces(char** line)
{
	while (**line != '\0' && isspace(**line))
	{
		(*line)++;
	}
}

Command getCommand(char** line)
{
	int i, count;
	skip_spaces(line);
	if (**line == '\n')
	{
		printf("No command entered!\n\n");
		return INPUT_ERROR;
	}	
	for (i = 0; i < FUNC_NUM; i++) 
	{
		count = strlen(command_names[i]);
		if  (!strncmp(command_names[i], *line, count)) /* Checks the valid command name. */
		{
			(*line) += count; /* if command name is valid moves the input by numbers of chars in command name. */
			if ((**line) != '\n' && (**line) != '\0' && !isspace(**line)) /* check the valid char after the command name */
			{
				return ERROR_COMMAND;
			}
			skip_spaces(line);
			if ((**line) == ',')
			{
				printf("Error: Illegal comma.\n\n");
				return INPUT_ERROR;
			}
			if (i == STOP) /* No text should appear after command stop */
			{
				if ((**line) != '\n' && (**line) != '\0')
				{
					EXTRANEOUS_TEXT
					return INPUT_ERROR;
				}
			}
			if (i != STOP) /* Matrix name should appear after command name */
			{
				MISSING_PARAMETER(**line)
			}
			return i;
		}
	}		
	return ERROR_COMMAND;
}

MatrixName getMatrixNameFromInput(char** line,int isCommaShouldApperAtTheEnd) /* if isCommaShouldApperAtTheEnd == 1 means that comma and another Matrix or a real number should apear. */  
{
	MatrixName result;
	skip_spaces(line);
	result = getMatrixByName(*line); /* Checks valid Matrix name */
	if (result == ERROR)
	{
		MISSING_MATRIX
	}
	else if (result != ERROR)
	{
		(*line) += MAT_NAME_LENGTH; /* if Matrix name is valid moves the input by numbers of chars in Matrix name. */
		if ((**line) != '\n' && (**line) != '\0' && !isspace(**line) && (**line)!= ',') /* check the valid char after the Matrix name */
		{
			MISSING_MATRIX
		}
		skip_spaces(line);
		if (isCommaShouldApperAtTheEnd == 1) /* if isCommaShouldApperAtTheEnd == 1 means that comma and another Matrix or a real number should apear. */ 
		{
			if ((**line) == ',')
			{
				(*line) += 1;
				skip_spaces(line);
				if (**line == ',')
				{
					MULTIPLE_COMMAS(**line)
						return ERROR;
				}
				MISSING_PARAMETER(**line)
			}
			else
			{
				if ((**line) == '\n' || (**line) == '\0')
				{
					MISSING_PARAMETER(**line);
				}
				else
				{
					MISSING_COMMA(**line)
						return ERROR;
				}
			}
		}
		else { /* No parameter should appear after Matrix Name. */
			skip_spaces(line);
			if ((**line) != '\n' && (**line) != '\0')
			{
				EXTRANEOUS_TEXT
					return ERROR;
			}


		}
	}
	
	return result;
}

MatrixName getMatrixByName(char* name)
{
	if (strncmp(name, "MAT_A", MAT_NAME_LENGTH) == 0)
	{
		return MAT_A;
	}
	if (strncmp(name, "MAT_B", MAT_NAME_LENGTH) == 0)
	{
		return MAT_B;
	}
	if (strncmp(name, "MAT_C", MAT_NAME_LENGTH) == 0)
	{
		return MAT_C;
	}
	if (strncmp(name, "MAT_D", MAT_NAME_LENGTH) == 0)
	{
		return MAT_D;
	}
	if (strncmp(name, "MAT_E", MAT_NAME_LENGTH) == 0)
	{
		return MAT_E;
	}
	if (strncmp(name, "MAT_F", MAT_NAME_LENGTH) == 0)
	{
		return MAT_F;
	}
	return ERROR;
}

void printMatName(int matName)
{
	if (matName == MAT_A)
	{
		printf("\nMAT_A printed sucessful.\n\n");
	}
	else if (matName == MAT_B)
	{
		printf("\nMAT_B printed sucessful.\n\n");
	}
	else if (matName == MAT_C)
	{
		printf("\nMAT_C printed sucessful.\n\n");
	}
	else if (matName == MAT_D)
	{
		printf("\nMAT_B printed sucessful.\n\n");
	}
	else if (matName == MAT_D)
	{
		printf("\nMAT_B printed sucessful.\n\n");
	}
	else if (matName == MAT_E)
	{
		printf("\nMAT_E printed sucessful.\n\n");
	}
	else if (matName == MAT_F)
	{
		printf("\nMAT_F printed sucessful.\n\n");
	}
}

double getNumber(char** line, int* isErrorOccur)
{
	int indexStr = 0;
	int flagDot = 0; /* flagDot = 1 if one point already been in input. */ 
	char str[30] = {0};
	char* temp; /* char array that valid chars from input entered to it. */ 
	*isErrorOccur = 0; /* If function return isErrorOccur = 1, means that it is not a real number. */
	skip_spaces(line);
	if (**line == '-' || **line == '+') { /* number can be negative or positive.*/
		str[indexStr++] = (**line);
		(*line)++;
	}
	else if (!isdigit(**line) && (**line) != '.') /* return isErrorOccur = 1 if char is nor a digit or not a point. */
	{
		*isErrorOccur = 1;
		return 0;
	}

	while (isdigit(**line) || (**line) == '.') /*checks the rest of input for digits or points */
	{
		str[indexStr] = (**line);
		if (**line == '.')
		{
			temp = (*line) + 1;
			if (flagDot == 1 || ((indexStr == 0 || indexStr == 1) && !isdigit(*temp))) { /* number can be .5 = 0.5 or -.5 = -0.5) */
				*isErrorOccur = 1;
				return 0;
			}
			flagDot = 1;
		}
		indexStr++;
		(*line)++;
	}
	skip_spaces(line);
	return atof(str); /* convert str to double and return the double number to double array. */
}

double* getNumbersArray(char** line)
{
	int error, sizeOfArray = 0; /* array can get up to 16 double numbers, if return isErrorOccur = 1 from function getNumber error = 1. */
	double number = 0;
	double* result = (double*)calloc(16, sizeof(double));
	if (!result)
	{
		printf("\nNo space allocated to read mat\n");
		return NULL;
	}
	while(sizeOfArray < SIZE_MAT_ROWS_AND_COLUMNS * SIZE_MAT_ROWS_AND_COLUMNS)
	{
		result[sizeOfArray++] = 0;
	}
	sizeOfArray = 0;
	while ((**line) != '\n'  && (**line) != '\0' && sizeOfArray < SIZE_MAT_ROWS_AND_COLUMNS * SIZE_MAT_ROWS_AND_COLUMNS) /* running utill end of input or until array filled with 16 doubles. */
	{
		number = getNumber(&(*line), &error);
		if (error == 1) /* if returned isErrorOccur = 1 from function getNumber(). */
		{
			printf("Error: Argument is not a real number.\n\n");
			return NULL;
		}
		else 
		{
			if ((**line) == ',')
			{
				(*line)++;
				skip_spaces(line);
				if ((**line) == '\n' || (**line) == '\0')
				{
					EXTRANEOUS_TEXT
					return NULL;
				}
				else if ((**line) == ',')
				{
					MULTIPLE_COMMAS(**line)
					return NULL;
				}
			}
			else if ((**line) != '\n' && (**line) != '\0') /* check if input is valid. */
			{
				if (isdigit(**line) || (**line) == '.' || (**line) == '-' || (**line) == '+') /* checks if there is comma between two double numbers in input. */ 
				{
					MISSING_COMMA(**line)
					return NULL;
				}
				else
				{
					printf("Error: Argument is not a real number.\n\n");
					return NULL;
				}
				
			}
		}
		result[sizeOfArray++] = number;
	}
	return (result);
}

double getScalar(char** line)
{
	double scalar;
	int error; /* if return isErrorOccur = 1 from function getNumber() error = 1. */

	scalar = getNumber(&(*line), &error); 
	if (error == 1)
	{
		printf("Error: Argument is not a scalar.\n\n"); /* if returned isErrorOccur = 1 from function getNumber(). */
		return LONG_MAX;
	}
	else
	{
		if ((**line) == ',') /* checks the input. Comma and Matrix name should appear after scalar. */
		{
			(*line)++;
			skip_spaces(line);
			if ((**line) == '\n' || (**line) == '\0') /* checks if there is Matrix name after scalar an comma */
			{
				printf("Error: Missing argument.\n\n");
				return LONG_MAX; 
			}
			else if ((**line) == ',')
			{
				MULTIPLE_COMMAS(**line)
					return LONG_MAX;
			}
		}
		else if ((**line) != '\n' && (**line) != '\0')
		{
			MISSING_COMMA(**line)
				return LONG_MAX;
		}
	}
	return scalar;
}

