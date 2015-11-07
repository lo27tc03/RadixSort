#include <BaseNIntegerListOfList.h>


BaseNIntegerListOfList createBucketList (int base);
/************************************************************************************
*
*creates a BaseNIntegerListOfList for storing list of integers in base N
*(N being the specified integer, first parameter)
*
*************************************************************************************/


BaseNIntegerListOfList buildBucketList(BaseNintegerList list, int pos);
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


BaseNintegerList buildIntegerList(BaseNIntegerListOfList listOfList);
/*************************************************************************************
*
*builds a new BaseNIntegerList from the specified BaseNIntegerListOfList
*(respecting the ascending order on the buckets)
*
*************************************************************************************/

BaseNIntegerListOfList addIntegerIntoBucket(BaseNIntegerListOfList listOfList, char* integer, int bucket);
/*************************************************************************************
*
*adds a new integer (char*) at the end of the specified list in bucket N
*(N being the third parameter, between 0 and F[or 16])
*
*************************************************************************************/

void deleteBucketList(BaseNIntegerListOfList listOfList);
/*************************************************************************************
*
*clears and deletes the specified BaseNIntegerListOfList
*(free the previously allocated memory)
*
*************************************************************************************/

BaseNIntegerListOfList radixsort(BaseNIntegerListOfList listOfList);
/************************************************************************************
*
*sorts the specified BaseNIntegerList using the proposed radix sort approach.
*See Figures 3-7 for a detailed description of the expected behavior of this function.
*
*
************************************************************************************/
