#ifndef  //typedef de la BaseNintegerList ?? 
#define



#include <stdlib.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0
typedef int BOOL;

typedef struct BaseNIntegerList
{
	struct BaseNIntegerList *head;
	struct BaseNIntegerList *tail;
	int base;
	int size;
}BaseNIntegerList;

typedef struct ListElement
{
	struct ListElement *previous;
	struct ListElement *next;
	int value;
}ListElement;

BaseNIntegerList createIntegerList (int);
/**************************************************************************************
*
*Creates a new empty BaseNIntegerList for storing integers in the specified base 
*Parameters : integer of the base
*
*************************************************************************************/

BOOL isEmpty (BaseNIntegerList, );
/*************************************************************************************
*Test if the list is empty
*Return 0 if empty, 1 else
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
*sums all the integers defined in the 
*specified list using the Binary addition (base 2) 
*and returns the corresponding results as 
*an integer (char*) defined in the base of the list
*
*
*************************************************************************************/

char* convertBaseToBinary(char* s, int n);
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