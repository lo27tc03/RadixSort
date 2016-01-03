#ifndef BASENINTEGERLISTOFLIST_H
#define BASENINTEGERLISTOFLIST_H

#define _GNU_SOURCE
#include <BaseNIntegerList.h>
#include <unistd.h>
#include <math.h>
#include <string.h>

typedef struct{
	int base;

	BaseNIntegerList list[17];
	BOOL error;
}BaseNIntegerListOfList;



/************************************************************************************
*
*Creates a BaseNIntegerListOfList for storing list of integers in base N
*Parameters : base
*
*************************************************************************************/
BaseNIntegerListOfList createBucketList (int);


/*************************************************************************************
*
*Builds a new BaseNIntegerListOfList according to the specified BaseNIntegerList
*and considering the specified digit position (rightmost)
*Parameters : BaseNIntegerList , Integer of position
*
*************************************************************************************/
BaseNIntegerListOfList buildBucketList(BaseNIntegerList, int);


/*************************************************************************************
*
*Builds a new BaseNIntegerList from the specified BaseNIntegerListOfList
*(respecting the ascending order on the buckets)
*Parameters : BaseNIntegerListOfList
*
*************************************************************************************/
BaseNIntegerList buildIntegerList(BaseNIntegerListOfList);


/*************************************************************************************
*
*Clears and deletes the specified BaseNIntegerListOfList
*(free the previously allocated memory)
*Parameters : BaseNIntegerListOfList
*
*************************************************************************************/
void deleteBucketList(BaseNIntegerListOfList);



/*************************************************************************************
*
*prints the listoflist specified in parameters
*
*************************************************************************************/
void printListOfList(BaseNIntegerListOfList lol);


#endif
