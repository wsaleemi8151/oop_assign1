/*
* FILE :          assessGrade.cpp
* PROJECT :       PROG1385-21S-Sec1 Object-oriented Programming: assignment # 01
* PROGRAMMER :    Gursharan Singh and Waqar Ali Saleemi
* FIRST VERSION : 6 June, 2021
* DESCRIPTION :   The functions in this file are used to Parse the input from user or fetch from a file
*				  and print If student is passed or failed.
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "assessGrade.h"

#pragma warning (disable : 4996)


/*
 * Function:    assessGrade()
 * Parameters:  double numGrade. A floating point number for student marks.
 * Returns:     It returns void.
 * Description: This function is used to print student grade.
*/
void assessGrade(double numGrade)
{
	if ((numGrade >= 0.0) && (numGrade <= 100.00))
	{
		if (numGrade >= 54.50)
		{
			printf("Student achieved %.2f %% which is a PASS condition.\n", numGrade);
		}
		else
		{
			printf("Student achieved %.2f %% which is a FAIL condition.\n", numGrade);
		}
	}
	else
	{
		printf("**ERROR : Invalid Input\n");
	}
}


/*
 * Function:    assessGrade()
 * Parameters:  char* alphaGrade. An overloaded assessGrade() method
 *				which takes a pointer to the string.
 * Returns:     It returns void.
 * Description: This function is used to print student grade.
*/
void assessGrade(char* alphaGrade)
{
	char letterGrade[6];
	double numGrade = 0;
	int processGrade = 0;
	strcpy(letterGrade, alphaGrade);

	if (strcmp(letterGrade, "A+") == 0)
	{
		numGrade = 95;
	}
	else if (strcmp(letterGrade, "A") == 0)
	{
		numGrade = 85;
	}
	else if (strcmp(letterGrade, "B+") == 0)
	{
		numGrade = 77;
	}
	else if (strcmp(letterGrade, "B") == 0)
	{
		numGrade = 72;
	}
	else if (strcmp(letterGrade, "C+") == 0)
	{
		numGrade = 67;
	}
	else if (strcmp(letterGrade, "C") == 0)
	{
		numGrade = 62;
	}
	else if (strcmp(letterGrade, "D") == 0)
	{
		numGrade = 57;
	}
	else if (strcmp(letterGrade, "F") == 0)
	{
		numGrade = 50;
	}
	else if (strcmp(letterGrade, "I") == 0)
	{
		processGrade = -1;
		printf("Student has Special Situation : I (Incomplete)\n");
	}
	else if (strcmp(letterGrade, "Q") == 0)
	{
		processGrade = -1;
		printf("Student has Special Situation : Q (Withdrawal After Drop/Refund Date)\n");
	}
	else if (strcmp(letterGrade, "AU") == 0)
	{
		processGrade = -1;
		printf("Student has Special Situation : AU (Audit Condition)\n");
	}
	else if (strcmp(letterGrade, "DNA") == 0)
	{
		processGrade = -1;
		printf("Student has Special Situation : DNA (Did Not Attend)\n");
	}
	else if (strcmp(letterGrade, "I/P") == 0)
	{
		processGrade = -1;
		printf("Student has Special Situation : I/P (In Process)\n");
	}
	else
	{
		numGrade = -1;
	}

	if (processGrade != -1)
	{
		assessGrade(numGrade);
	}
}

/*
 * Function:    assessGrade()
 * Parameters:  int num[]. An overloaded assessGrade() method
 *				which takes an array of integers for student's marks for assignments.
 * Returns:     It returns void.
 * Description: This function is used to print student grade.
*/
void assessGrade(int num[])
{
	double finalGrade = 0;
	int returnVal = 1;
	int sum = 0;
	int i = 0;

	while (i < kNumberOfAssignments)
	{
		returnVal = checkRange(num[i], 0, 100);
		if (returnVal == 0)
		{
			printf("**ERROR : Invalid Input\n");
			break;
		}
		sum += num[i];
		i++;
	}

	finalGrade = sum / kNumberOfAssignments;

	if (returnVal != 0)
	{
		assessGrade(finalGrade);
	}
}

/*
 * Function:    parseUserInput()
 * Parameters:  char* input. A pointer to input string.
 * Returns:     It returns void.
 * Description: This function is used to parse the input provide by user or loaded from a file.
*/
void  parseUserInput(char* input)
{
	int num[6] = { 0 };
	char alpha[5];
	char test[8];

	if (sscanf(input, "%[+/A-U]", &alpha) != 1)
	{
		if (sscanf(input, "%*c%[.]", &test) != 1)
		{
			if (sscanf(input, "%*c%*c%[.]", &test) != 1)
			{
				if (sscanf(input, "%*c%*c%*c%[.]", &test) != 1)
				{
					if (sscanf(input, "%d %d %d %d %d", &num[0], &num[1], &num[2], &num[3], &num[4]) != 0)
					{
						assessGrade(num);
					}
				}
				else
				{
					decimalInputFunction(input);
				}
			}
			else
			{
				decimalInputFunction(input);
			}

		}
		else
		{
			decimalInputFunction(input);
		}
	}
	else
	{
		assessGrade(alpha);
	}

}

/*
 * Function:    decimalInputFunction()
 * Parameters:  char* input. A pointer to input string.
 * Returns:     It returns void.
 * Description: This function is used to parse the decimal input provide by user or loaded from a file.
*/
void decimalInputFunction(char* input)
{
	double decimalInput;

	if (sscanf(input, "%lf", &decimalInput) != 1)
	{
		printf("Error in sscanf-1\n\n");
	}
	else
	{
		assessGrade(decimalInput);
	}
}

/*
 * Function:    checkRange()
 * Parameters:  int value, int mini_value, int max_value, where value is the numerical amount to check for validity.
 * Returns:     It return 0 if the value is out of range and 1 if the value is within the specified range.
 * Description: This function returns different values, indicating a value to be in or out of range.
*/
int checkRange(int value, int mini_value, int max_value)
{
	/* Using if-esle statement with logical operation [And (&&)] to check if the value lies between the maximum and minimum value. */
	if ((value >= mini_value) && (value <= max_value))
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

/*
 * Function:    checkSpace()
 * Parameters:  char* input. A string pointer.
 * Returns:     It returns int.
 * Description: This function is used to if input string contains space. If yes, it returns 1, otherwise 0.
*/
int checkSpace(char* input)
{
	for (size_t i = 0; i < strlen(input); i++)
	{
		int result = isspace(input[i]);
		if (result != 0)
		{
			return 1;
		}
	}
	return 0;
}