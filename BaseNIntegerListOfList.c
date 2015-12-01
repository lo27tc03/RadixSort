#include "BaseNIntegerListOfList.h"
#include <math.h>
#include <string.h>


BaseNIntegerListOfList createBucketList (int base)
{
	BaseNIntegerListOfList l;
	l.base = base;
	l.error = FALSE;

	int i;
	for(i = 0; i <= 16; ++i)
		l.list[i] = createIntegerList(base);

	return l;
}


BaseNIntegerListOfList buildBucketList(BaseNIntegerList list, int pos)
{
		BaseNIntegerListOfList bucketlist = createBucketList(list.base);
		if(list.size == 0)
		{
			bucketlist.error = TRUE;
			return bucketlist;
		}
		int bucket;
		int i = 0;
		while(!isEmpty(list))
		{

			char* temp = list.head->value;

			list = removeHead(list);
			char chartemp = (char)temp[strlen(temp) - pos];
			printf("%c (debug)\n", chartemp);
			bucket = strtol(&chartemp, 0, 36);
			if (bucket > 17)
			{
					bucketlist.error = TRUE;
					return bucketlist;
			}

			bucketlist.list[bucket] = insertTail(bucketlist.list[bucket], temp);
		}

		return bucketlist;
}



BaseNIntegerList buildIntegerList(BaseNIntegerListOfList bucketList)
{
	BaseNIntegerList output;
	int i;

	for(i = 0; i <= 16; ++i)
	{
		while(!isEmpty(bucketList.list[i]))
		{
			output = insertTail(output, bucketList.list[i].head->value);
			bucketList.list[i] = removeHead(bucketList.list[i]);
		}
	}

	return output;
}

BaseNIntegerListOfList addIntegerIntoBucket(BaseNIntegerListOfList listOfList, char* integer, int bucket)
{

}

void deleteBucketList(BaseNIntegerListOfList listOfList)
{

}
/*************************************************************************************
*
*clears and deletes the specified BaseNIntegerListOfList
*(free the previously allocated memory)
*
*************************************************************************************/

BaseNIntegerListOfList radixsort(BaseNIntegerListOfList listOfList)
{}
/************************************************************************************
*
*sorts the specified BaseNIntegerList using the proposed radix sort approach.
*See Figures 3-7 for a detailed description of the expected behavior of this function.
*
*
************************************************************************************/
