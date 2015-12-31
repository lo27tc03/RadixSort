#ifndef BASENINTEGERLISTOFLIST_H
#define BASENINTEGERLISTOFLIST_H

#include <BaseNIntegerList.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include <time.h>

typedef struct{
	int base;
	BaseNIntegerList list[17];
	BOOL error;
}BaseNIntegerListOfList;



BaseNIntegerListOfList createBucketList (int);
/************************************************************************************
*
*Creates a BaseNIntegerListOfList for storing list of integers in base N
*Parameters : base
*
*************************************************************************************/


BaseNIntegerListOfList buildBucketList(BaseNIntegerList, int);
/*************************************************************************************
*
*Builds a new BaseNIntegerListOfList according to the specified BaseNIntegerList
*and considering the specified digit position (rightmost)
*Parameters : BaseNIntegerList , Integer of position
*
*************************************************************************************/


BaseNIntegerList buildIntegerList(BaseNIntegerListOfList);
/*************************************************************************************
*
*Builds a new BaseNIntegerList from the specified BaseNIntegerListOfList
*(respecting the ascending order on the buckets)
*Parameters : BaseNIntegerListOfList
*
*************************************************************************************/

BaseNIntegerListOfList addIntegerIntoBucket(BaseNIntegerListOfList , char* , int);
/*************************************************************************************
*
*Adds a new integer at the end of the specified list in bucket N
*Parameters : BaseNIntegerListOfList , Integer to add in the bucket, integer of the base between 2 and 16
*
*************************************************************************************/

void deleteBucketList(BaseNIntegerListOfList);
/*************************************************************************************
*
*Clears and deletes the specified BaseNIntegerListOfList
*(free the previously allocated memory)
*Parameters : BaseNIntegerListOfList
*
*************************************************************************************/

void printListOfList(BaseNIntegerListOfList lol);


#endif
