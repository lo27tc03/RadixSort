#ifndef BASENINTEGERLIST_H
#define BASENINTEGERLIST_H

#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0
typedef int BOOL;

typedef struct elem {
	struct elem *previous;
	struct elem *next;
	char* value;
}ListElement;


typedef struct {
	ListElement *head;
	ListElement *tail;
	int base;
	int size;
}BaseNIntegerList;


/**************************************************************************************
*
*Creates a new empty BaseNIntegerList for storing integers in the specified base
*Parameters : integer of the base
*
*************************************************************************************/
BaseNIntegerList createIntegerList (int);



/*************************************************************************************
*Test if the list is empty
*Return 1 if empty, 0 else
*Parameters : BaseNintegerList to test
**************************************************************************************/
BOOL isEmpty (BaseNIntegerList);



/*************************************************************************************
*
*Adds the specified integer (char*, represented in the considered base) at the beginning of the specified list
*Parameters : BaseNintegerList , integer to add
*
**************************************************************************************/
BaseNIntegerList insertHead (BaseNIntegerList, char*);



/*************************************************************************************
*
*Adds the specified integer (char*) at the end of the specified list
*Parameters : BaseNintegerList , integer to add
*
**************************************************************************************/
BaseNIntegerList insertTail (BaseNIntegerList, char*);



/**************************************************************************************
*
*Removes the first element of the specified list
*Parameters : BaseNIntegerList
*
*************************************************************************************/
BaseNIntegerList removeHead(BaseNIntegerList);



/**************************************************************************************
*
*Removes the last element of the specified list
*Parameters : BaseNIntegerList
*
*************************************************************************************/
BaseNIntegerList removeTail(BaseNIntegerList);



/**************************************************************************************
*
*Clears and deletes the specified BaseNIntegerList
*(free the previously allocated memory)
*Parameters : l BaseNIntegerList
*
*************************************************************************************/
void deleteIntegerList(BaseNIntegerList l);




/**************************************************************************************
*
*Sums all the integers defined in the
*specified list using the Binary addition (base 2)
*and returns the corresponding results as
*an integer (char*) defined in the base of the list
*Parameters : l BaseNIntegerList
*
*************************************************************************************/
char* sumIntegerList(BaseNIntegerList l);



/**************************************************************************************
*
*Converts the specified integer represented with the specified base
*into a corresponding binary integer.
*Parameters : s char to convert , n specified base
*
*************************************************************************************/
char* convertBaseToBinary(char* s, int n);



/**************************************************************************************
*
*Converts an integer represented using a binary base into a corresponding
*integer represented with the specified base
*Parameters : s char to convert , n specified base
*
*************************************************************************************/
char* convertBinaryToBase(char* s, int n);




/**************************************************************************************
*
*Converts an integer represented using decimal base into a corresponding
*integer represented with the specified base
*Parameters : int dec the integer to convert , int base the base wanted
*
*************************************************************************************/
char* convDecToBase(int dec, int base);



/**************************************************************************************
*
*Get an integer and verify if it is inbetween the two bounds
*Parameters: test , upper_bound , lower_bound
*
*************************************************************************************/
void get_And_Verify_Int(int *test, int lower_bound, int upper_bound);



/**************************************************************************************
*
*Fill a linked list following the base and return it
*Parameters: base
*
*************************************************************************************/
BaseNIntegerList fill(int base);


/**************************************************************************************
*
*returns the number of digit of the integers with the most digit
*Parameters: base
*
*************************************************************************************/
int maxIntegerLength(BaseNIntegerList);



/************************************************************************************
*
*sorts the specified BaseNIntegerList using the proposed radix sort approach.
*See Figures 3-7 for a detailed description of the expected behavior of this function.
*
*
************************************************************************************/
BaseNIntegerList radixSort(BaseNIntegerList list, BOOL details);



/**************************************************************************************
*
*puts the numbers in demo.txt in a list and returns it
*no parameters
*
*************************************************************************************/
BaseNIntegerList loadDemo();



/**************************************************************************************
*
*prints the list in parameters
*
*************************************************************************************/
void printList(BaseNIntegerList list);



/**************************************************************************************
*
*converts the list in parameters to binary
*prints it
*converts back to its original base
*
*************************************************************************************/
void tryConvert(BaseNIntegerList list);

#endif
