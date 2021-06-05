// oop_assign1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>




/*Addition by G------------------- */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#pragma warning (disable : 4996)
using namespace std;

#define kBlockSize 80

/* function prototypes */
int checkRange(int value, int mini_value, int max_value);
void outputGrade(double numGrade);

void assessGrade(char* alphaGrade);
void assessGrade(double numGrade);
void assessGrade(int num[]);
void clearCR(char* buf);
/*---------------------Addition end G */

void decimalInputFunction(char* input);
void  parseUserInput(char* input);

/*---------------------Addition end G - 05-06-2021 */

int main()
{
	char userInput[kBlockSize] = "";
	int exitCode = 0;
	while (exitCode < 1)
	{
		printf("Enter Studentís Grade(s) >>>");
		fgets(userInput, kBlockSize, stdin);
		clearCR(userInput);

		char fileProcessChar[1];
		char fileName[kBlockSize];

		sscanf(userInput, "%s %s", fileProcessChar, fileName);

		if (strcmp(userInput, "X") != 0 && strcmp(fileProcessChar, "Z") != 0)
		{
			parseUserInput(userInput);
		}
		else if (strcmp(fileProcessChar, "Z") == 0)
		{
			FILE* fp = NULL;

			fp = fopen(fileName, "r"); // file open using read text option
			if (fp == NULL)
			{
				printf("Error: can't open %s for writing\n", fileName);
				exitCode = 1; // returns 1 if file open failed
			}

			char memBlock[kBlockSize];

			while (fgets(memBlock, sizeof(memBlock), fp) != NULL)
			{
				clearCR(memBlock);
				parseUserInput(memBlock);
			}

			if (fclose(fp) != 0)
			{
				printf("Error closing %s file\n", fileName);
				exitCode = 1; // returns 1 if file close failed
			}
		}
		else if (strcmp(userInput, "X") == 0)
		{
			exitCode = 1;
		}
	}

	return exitCode;
}

/* Overload function1 - Take only 1 parameter : [char *] - for letter grade/special situation. */
void assessGrade(char* alphaGrade)
{
	char letterGrade[6];
	double numGrade = 0;
	int i = 0;
	strcpy(letterGrade, alphaGrade);

	if (strcmp(letterGrade, "A+") == 0)
	{
		numGrade = 95;
	}
	else
	{
		if (strcmp(letterGrade, "A") == 0)
		{
			numGrade = 85;
		}
		else
		{
			if (strcmp(letterGrade, "B+") == 0)
			{
				numGrade = 77;
			}
			else
			{
				if (strcmp(letterGrade, "B") == 0)
				{
					numGrade = 72;
				}
				else
				{
					if (strcmp(letterGrade, "C+") == 0)
					{
						numGrade = 67;
					}
					else
					{
						if (strcmp(letterGrade, "C") == 0)
						{
							numGrade = 62;
						}
						else
						{
							if (strcmp(letterGrade, "D") == 0)
							{
								numGrade = 57;
							}
							else
							{
								if (strcmp(letterGrade, "F") == 0)
								{
									numGrade = 50;
								}
								else
								{
									if (strcmp(letterGrade, "I") == 0)
									{
										i = -1;
										printf("Student has Special Situation : I (Incomplete)\n");
									}
									else
									{
										if (strcmp(letterGrade, "Q") == 0)
										{
											i = -1;
											printf("Student has Special Situation : Q (Withdrawal After Drop/Refund Date)\n");
										}
										else
										{
											if (strcmp(letterGrade, "AU") == 0)
											{
												i = -1;
												printf("Student has Special Situation : AU (Audit Condition)\n");
											}
											else
											{
												if (strcmp(letterGrade, "DNA") == 0)
												{
													i = -1;
													printf("Student has Special Situation : DNA (Did Not Attend)\n");
												}
												else
												{
													if (strcmp(letterGrade, "I/P") == 0)
													{
														i = -1;
														printf("Student has Special Situation : I/P (In Process)\n");
													}
													else
													{
														numGrade = -1;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	if (i != -1)
	{
		assessGrade(numGrade);
	}

}


/* Overload function2 - take single parameter : [double] - for final mark.*/
void assessGrade(double numGrade)
{
	if ((numGrade >= 0.0) && (numGrade <= 100))
	{
		outputGrade(numGrade);
	}
	else
	{
		printf("**ERROR : Invalid Input\n");
	}
}


/* Overload function3 - take [ int [5] ] as array - indvidual assignment marks. */
void assessGrade(int num[])
{
	double finalGrade = 0;
	int returnVal = 1;
	int sum = 0;
	int i = 0;

	while (i < 5)
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

	finalGrade = sum / 5;

	if (returnVal != 0)
	{
		assessGrade(finalGrade);
	}
}


/* Function used to avoid code duplication- for output from overload functions*/
void outputGrade(double numGrade)
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



/*
 * Function: checkRange()
 * Parameters: int value, int mini_value, int max_value, where value is the numerical amount to check for validity.
 * Returns: It return 0 if the value is out of range and 1 if the value is within the specified range.
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

/* This function takes a string and call appropiate overload function. */
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


/* This Function is used to avoid code duplication in the parseUserInput function. */
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

/*---------------------Addition end G 05-06-2021*/


void clearCR(char* buf)
{
	char* whereCR = strchr(buf, '\n');
	if (whereCR != NULL)
	{
		*whereCR = '\0';
	}
}