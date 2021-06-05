/*
* FILE :          assessGrade.h
* PROJECT :       PROG1385-21S-Sec1 Object-oriented Programming: assignment # 01
* PROGRAMMER :    Gursharan Singh and Waqar Ali Saleemi
* FIRST VERSION : 6 June, 2021
* DESCRIPTION :   A header file contains function definitions for parsing input 
*				  and print Student results.
*/

#define kBlockSize 80
#define kNumberOfAssignments 5

void assessGrade(double numGrade);
void assessGrade(char* alphaGrade);
void assessGrade(int num[]);
void parseUserInput(char* input);
int checkRange(int value, int mini_value, int max_value);
int checkSpace(char* input);
