#include <BaseNIntegerListOfList.h>
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
		char* temp;
		char chartemp;
		if(list.size == 0)
		{
			bucketlist.error = TRUE;
			return bucketlist;
		}
		int bucket;
		while(isEmpty(list) == FALSE)
		{

			//printf("%s\n", list.head->value);
			temp = list.head->value;




			chartemp = temp[strlen(temp) - pos];

			//printf("%c (debug)\n", chartemp);
			bucket = strtol(&chartemp, 0, 36);

			if (bucket > 17)
			{
					bucketlist.error = TRUE;
					return bucketlist;
			}

			bucketlist.list[bucket] = insertTail(bucketlist.list[bucket], temp);
			list = removeHead(list);
		}

		return bucketlist;
}



BaseNIntegerList buildIntegerList(BaseNIntegerListOfList bucketList)
{
	BaseNIntegerList output = createIntegerList(bucketList.base);
	int i;

	for(i = 0; i <= 16; ++i)
	{
		while(bucketList.list[i].size != 0)
		{
			output = insertTail(output, bucketList.list[i].head->value);
			bucketList.list[i] = removeHead(bucketList.list[i]);
		}
	}

	return output;
}

BaseNIntegerListOfList addIntegerIntoBucket(BaseNIntegerListOfList listOfList, char* integer, int bucket)
{
	return listOfList;
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

void printListOfList(BaseNIntegerListOfList lol)
{
	int i = 0;
	ListElement *temp = lol.list[0].head;

	for(i=0;i<16;++i)
	{
		temp = lol.list[i].head;
		printf("%d : ", i);
		while(temp != NULL)
		{
			printf("%s\t", temp->value);
			temp = temp->next;
		}
		printf("\n");
	}
	while ( getchar() != '\n');
	system("clear");
}
