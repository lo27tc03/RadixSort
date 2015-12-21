#ifndef BASENINTEGERLISTOFLIST_H
#define BASENINTEGERLISTOFLIST_H

#include <BaseNIntegerList.h>

typedef struct{
	int base;
	BaseNIntegerList list[17];
	BOOL error;
}BaseNIntegerListOfList;



BaseNIntegerListOfList createBucketList (int);
/************************************************************************************
*
*creates a BaseNIntegerListOfList for storing list of integers in base N
*(N being the specified integer, first parameter)
*
*************************************************************************************/


BaseNIntegerListOfList buildBucketList(BaseNIntegerList, int);
/*************************************************************************************
*
*builds a new BaseNIntegerListOfList according to the specified BaseNIntegerList
*and considering the specified digit position (rightmost)
		Remark : You could use the function strtol 2 for converting a given digit (char*)
		represented in a given base into the corresponding digit in decimal
		base, it could be useful for identifying the right bucket.
*
*
*************************************************************************************/


BaseNIntegerList buildIntegerList(BaseNIntegerListOfList);
/*************************************************************************************
*
*builds a new BaseNIntegerList from the specified BaseNIntegerListOfList
*(respecting the ascending order on the buckets)
*
*************************************************************************************/

BaseNIntegerListOfList addIntegerIntoBucket(BaseNIntegerListOfList , char* , int);
/*************************************************************************************
*
*adds a new integer (char*) at the end of the specified list in bucket N
*(N being the third parameter, between 0 and F[or 16])
*
*************************************************************************************/

void deleteBucketList(BaseNIntegerListOfList);
/*************************************************************************************
*
*clears and deletes the specified BaseNIntegerListOfList
*(free the previously allocated memory)
*
*************************************************************************************/


#endif
