/*
* FILE : assign1.cpp
* PROJECT : PROG1385-21S-Sec1 Object-oriented Programming: assignment # 01
* PROGRAMMER : Gursharan Singh and Waqar Ali Saleemi
* FIRST VERSION : 2021-05-05
* DESCRIPTION :
* The functions in this file are used to get input from the user 
*			or a file user provided in the input instruction
*			and print if the Student is passed or failed.
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "assessGrade.h"

using namespace std;
#pragma warning (disable : 4996)

/* function prototypes */
void clearCR(char* buf);

int main()
{
	char userInput[kBlockSize] = "";
	int exitCode = 0;
	while (exitCode < 1)
	{
		printf("\nEnter Student\'s Grade(s) >>> ");
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

/*
 * Function: clearCR()
 * Parameters: char* buf. A string pointer for which \n replaced with \0.
 * Returns: It returns void.
 * Description: This function is used to replace newline char \n to endline char \0.
*/
void clearCR(char* buf)
{
	char* whereCR = strchr(buf, '\n');
	if (whereCR != NULL)
	{
		*whereCR = '\0';
	}
}