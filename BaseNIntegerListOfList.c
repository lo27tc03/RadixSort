/************************************************************************************
*BaseNIntegerListOfList.c
*DUVAUCHELLE.G AND PROST.S
*
*UTBM LO27 Jan 2016
*************************************************************************************/
#include <BaseNIntegerListOfList.h>


/************************************************************************************
*
*Creates a BaseNIntegerListOfList for storing list of integers in base N
*Parameters : base integer
*
*************************************************************************************/
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


/*************************************************************************************
*
*Builds a new BaseNIntegerListOfList according to the specified BaseNIntegerList
*and considering the specified digit position (rightmost)
*Parameters : BaseNIntegerList , Integer of position
*
*************************************************************************************/
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

			temp = list.head->value;

			chartemp = temp[strlen(temp) - pos];

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



/*************************************************************************************
*
*Builds a new BaseNIntegerList from the specified BaseNIntegerListOfList
*(respecting the ascending order on the buckets)
*Parameters : BaseNIntegerListOfList
*
*************************************************************************************/
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



/*************************************************************************************
*
*Clears and deletes the specified BaseNIntegerListOfList
*(free the previously allocated memory)
*
*************************************************************************************/

void deleteBucketList(BaseNIntegerListOfList listOfList)
{
	//nothing to free
}



/*************************************************************************************
*
*Prints the listoflist specified in parameters
*Parameters : BaseNIntegerListOfList
*
*************************************************************************************/
void printListOfList(BaseNIntegerListOfList lol)
{
	system("clear");
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

	printf("press enter to continue\n");
	while ( getchar() != '\n');
	system("clear");
}
