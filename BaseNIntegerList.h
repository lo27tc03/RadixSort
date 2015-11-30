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
*clears and deletes the specified BaseNIntegerList
*(free the previously allocated memory)
*
*************************************************************************************/

char* sumIntegerList(BaseNIntegerList l);
/**************************************************************************************
*
*sums all the integers ••••defined in the
*specified list using t••••he Binary addition (base 2)
*and returns the corres••••ponding results as
*an integer (char*) defined in the base of the list
*
*
*************************************************************************************/

int convertBaseToBinary(char* s, int n);
/**************************************************************************************
*
*converts the specified integer (char*)
*represented with the specified base (Integer, second parameter)
*into a corresponding binary integer (base 2).
*
*
*************************************************************************************/

char* convertBinaryToBase(char* s, int n);
/**************************************************************************************
*
*converts an integer represented using a binary base (base 2)
*into a corresponding integer represented
*with the specified base (Integer, second parameter)
*
*
*************************************************************************************/

#endif
