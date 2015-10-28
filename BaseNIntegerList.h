#ifndef  //typedef de la BaseNintegerList ?? 
#define



#include <stdlib.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0
typedef int BOOL;



BaseNIntegerList createIntegerList (int);
/**************************************************************************************
*
*creates a new empty BaseNIntegerList 
*for storing integers in the specified base 
*
*************************************************************************************/

BOOL isEmpty (BaseNIntegerList, );
/*************************************************************************************
*Test if the list is empty
*Return 0 if empty, 1 else
*
**************************************************************************************/

BaseNIntegerList insertHead (BaseNIntegerList, char*);
/*************************************************************************************
*
*adds the specified integer 
*(char*, represented in the considered base) 
*at the beginning of the specified list
*
**************************************************************************************/

BaseNIntegerList insertTail (BaseNIntegerList, char*);
/*************************************************************************************
*
* adds the specified integer (char*) 
*at the end of the specified list
*
**************************************************************************************/

BaseNIntegerList removeHead(BaseNIntegerList);
/**************************************************************************************
*
*removes the first element of the specified list
*
*
*************************************************************************************/

BaseNIntegerList removeTail(BaseNIntegerList);
/**************************************************************************************
*
*removes the last element of the specified list
*
*
*************************************************************************************/

void deleteIntegerList(BaseNIntegerList);
/**************************************************************************************
*
*clears and deletes the specified BaseNIntegerList 
*(free the previously allocated memory)
*
*************************************************************************************/

char* sumIntegerList(BaseNIntegerList);
/**************************************************************************************
*
*sums all the integers defined in the 
*specified list using the Binary addition (base 2) 
*and returns the corresponding results as 
*an integer (char*) defined in the base of the list
*
*
*************************************************************************************/

char* convertBaseToBinary(char* , int);
/**************************************************************************************
*
*converts the specified integer (char*) 
*represented with the specified base (Integer, second parameter) 
*into a corresponding binary integer (base 2).
*
*
*************************************************************************************/

char* convertBinaryToBase(char* , int);
/**************************************************************************************
*
*converts an integer represented using a binary base (base 2) 
*into a corresponding integer represented 
*with the specified base (Integer, second parameter)
*
*
*************************************************************************************/

#endif 