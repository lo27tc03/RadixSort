#include <BaseNIntegerListOfList.h>


<<<<<<< HEAD

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
=======
BaseNIntegerListOfList createBucketList (int base);
/************************************************************************************
*
*creates a BaseNIntegerListOfList for storing list of integers in base N
*(N being the specified integer, first parameter)
>>>>>>> origin/master
*
*************************************************************************************/


<<<<<<< HEAD
BaseNIntegerListOfList buildBucketList(BaseNintegerList l, int k);
/*************************************************************************************
*
*Builds a new BaseNIntegerListOfList according to the specified BaseNIntegerList 
=======
BaseNIntegerListOfList buildBucketList(BaseNintegerList list, int pos);
/*************************************************************************************
*
*builds a new BaseNIntegerListOfList according to the specified BaseNIntegerList
>>>>>>> origin/master
*and considering the specified digit position (rightmost)
		Remark : You could use the function strtol 2 for converting a given digit (char*)
		represented in a given base into the corresponding digit in decimal
		base, it could be useful for identifying the right bucket.
*
*
*************************************************************************************/


<<<<<<< HEAD
BaseNintegerList buildIntegerList(BaseNIntegerListOfList L);
/*************************************************************************************
*
*Builds a new BaseNIntegerList from the specified BaseNIntegerListOfList 
=======
BaseNintegerList buildIntegerList(BaseNIntegerListOfList listOfList);
/*************************************************************************************
*
*builds a new BaseNIntegerList from the specified BaseNIntegerListOfList
>>>>>>> origin/master
*(respecting the ascending order on the buckets)
*Parameters : BaseNintegerListOfList to 'convert' in BaseNIntegerList
*
*************************************************************************************/

<<<<<<< HEAD
BaseNIntegerListOfList addIntegerIntoBucket(BaseNIntegerListOfList L, char* s, int n);
/*************************************************************************************
*
*Adds a new integer (char*) at the end of the specified list in bucket N 
=======
BaseNIntegerListOfList addIntegerIntoBucket(BaseNIntegerListOfList listOfList, char* integer, int bucket);
/*************************************************************************************
*
*adds a new integer (char*) at the end of the specified list in bucket N
>>>>>>> origin/master
*(N being the third parameter, between 0 and F[or 16])
*Parameters : BaseNIntegerListOfList , Integer to add, Integer 
*
*************************************************************************************/

<<<<<<< HEAD
void deleteBucketList(BaseNIntegerListOfList L);
/*************************************************************************************
*
*Clears and deletes the specified BaseNIntegerListOfList 
=======
void deleteBucketList(BaseNIntegerListOfList listOfList);
/*************************************************************************************
*
*clears and deletes the specified BaseNIntegerListOfList
>>>>>>> origin/master
*(free the previously allocated memory)
*Parameters : BaseNIntegerListOfList to delete
*
*************************************************************************************/

<<<<<<< HEAD
BaseNIntegerListOfList radixsort(BaseNIntegerListOfList L);
/************************************************************************************
*
*Sorts the specified BaseNIntegerList using the proposed radix sort approach. 
=======
BaseNIntegerListOfList radixsort(BaseNIntegerListOfList listOfList);
/************************************************************************************
*
*sorts the specified BaseNIntegerList using the proposed radix sort approach.
>>>>>>> origin/master
*See Figures 3-7 for a detailed description of the expected behavior of this function.
*Parameters : BaseNIntegerListOfList to sort 
*
************************************************************************************/
