#ifndef  //typedef de la BaseNintegerList ?? 
#define



#include <stdlib.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0
typedef int BOOL;





BaseNIntegerListOfList createBucketList (int k);
/************************************************************************************
*
*Creates a BaseNIntegerListOfList for storing list of integers in base N 
*(N being the specified integer, first parameter) 
*Parameters : integer of the base
*
*************************************************************************************/


BaseNIntegerListOfList buildBucketList(BaseNintegerList l, int k);
/*************************************************************************************
*
*Builds a new BaseNIntegerListOfList according to the specified BaseNIntegerList 
*and considering the specified digit position (rightmost)
		Remark : You could use the function strtol 2 for converting a given digit (char*) 
		represented in a given base into the corresponding digit in decimal
		base, it could be useful for identifying the right bucket.
*
*
*************************************************************************************/


BaseNintegerList buildIntegerList(BaseNIntegerListOfList L);
/*************************************************************************************
*
*Builds a new BaseNIntegerList from the specified BaseNIntegerListOfList 
*(respecting the ascending order on the buckets)
*Parameters : BaseNintegerListOfList to 'convert' in BaseNIntegerList
*
*************************************************************************************/

BaseNIntegerListOfList addIntegerIntoBucket(BaseNIntegerListOfList L, char* s, int n);
/*************************************************************************************
*
*Adds a new integer (char*) at the end of the specified list in bucket N 
*(N being the third parameter, between 0 and F[or 16])
*Parameters : BaseNIntegerListOfList , Integer to add, Integer 
*
*************************************************************************************/

void deleteBucketList(BaseNIntegerListOfList L);
/*************************************************************************************
*
*Clears and deletes the specified BaseNIntegerListOfList 
*(free the previously allocated memory)
*Parameters : BaseNIntegerListOfList to delete
*
*************************************************************************************/

BaseNIntegerListOfList radixsort(BaseNIntegerListOfList L);
/************************************************************************************
*
*Sorts the specified BaseNIntegerList using the proposed radix sort approach. 
*See Figures 3-7 for a detailed description of the expected behavior of this function.
*Parameters : BaseNIntegerListOfList to sort 
*
************************************************************************************/
#endif 