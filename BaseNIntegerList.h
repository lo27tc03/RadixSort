#ifndef BASENINTEGERLIST_H
#define BASENINTEGERLIST_H

#include <stdlib.h>
#include <stdio.h>

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

BaseNIntegerList createIntegerList (int);
/**************************************************************************************
*
*Creates a new empty BaseNIntegerList for storing integers in the specified base
*Parameters : integer of the base
*
*************************************************************************************/

BOOL isEmpty (BaseNIntegerList);
/*************************************************************************************
*Test if the list is empty
*Return 1 if empty, 0 else
*Parameters : BaseNintegerList to test
**************************************************************************************/

BaseNIntegerList insertHead (BaseNIntegerList, char*);
/*************************************************************************************
*
*Adds the specified integer (char*, represented in the considered base) at the beginning of the specified list
*Parameters : BaseNintegerList , integer to add
*
**************************************************************************************/

BaseNIntegerList insertTail (BaseNIntegerList, char*);
/*************************************************************************************
*
*Adds the specified integer (char*) at the end of the specified list
*Parameters : BaseNintegerList , integer to add
*
**************************************************************************************/

BaseNIntegerList removeHead(BaseNIntegerList);
/**************************************************************************************
*
*Removes the first element of the specified list
*Parameters : BaseNIntegerList
*
*************************************************************************************/

BaseNIntegerList removeTail(BaseNIntegerList);
/**************************************************************************************
*
*Removes the last element of the specified list
*Parameters : BaseNIntegerList
*
*************************************************************************************/


void deleteIntegerList(BaseNIntegerList l);
/**************************************************************************************
*
*Clears and deletes the specified BaseNIntegerList
*(free the previously allocated memory)
*Parameters : l BaseNIntegerList
*
*************************************************************************************/

char* sumIntegerList(BaseNIntegerList l);
/**************************************************************************************
*
*Sums all the integers defined in the
*specified list using the Binary addition (base 2)
*and returns the corresponding results as
*an integer (char*) defined in the base of the list
*Parameters : l BaseNIntegerList
*
*************************************************************************************/

char* convertBaseToBinary(char* s, int n);
/**************************************************************************************
*
*Converts the specified integer represented with the specified base
*into a corresponding binary integer.
*Parameters : s char to convert , n specified base
*
*************************************************************************************/

char* convertBinaryToBase(char* s, int n);
/**************************************************************************************
*
*Converts an integer represented using a binary base into a corresponding
*integer represented with the specified base
*Parameters : s char to convert , n specified base
*
*************************************************************************************/
char* convDecToBase(int dec, int base);

void get_And_Verify_Int(int *test, int lower_bound, int upper_bound);
/**************************************************************************************
*
*Get an integer and verify if it is inbetween the two bounds
*Parameters: test , upper_bound , lower_bound
*
*************************************************************************************/

BaseNIntegerList fill(int base);
/**************************************************************************************
*
*Fill a linked list following the base and return it
*Parameters: base
*
*************************************************************************************/


int maxIntegerLength(BaseNIntegerList);

BaseNIntegerList radixSort(BaseNIntegerList list);
/************************************************************************************
*
*sorts the specified BaseNIntegerList using the proposed radix sort approach.
*See Figures 3-7 for a detailed description of the expected behavior of this function.
*
*
************************************************************************************/

BaseNIntegerList loadDemo();

#endif
