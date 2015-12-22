#include <BaseNIntegerList.h>
#include <BaseNIntegerListOfList.h>
#include <string.h>


/**************************************************************************************
*
*Creates a new empty BaseNIntegerList for storing integers in the specified base
*Parameters : integer of the base
*
*************************************************************************************/
BaseNIntegerList createIntegerList (int base)
{

	BaseNIntegerList l;
	l.head = NULL;
	l.tail = NULL;
	l.base = base;
	l.size = 0;

	return l;
}


/*************************************************************************************
*Test if the list is empty
*Return 1 if empty, 0 else
*Parameters : BaseNintegerList to test
**************************************************************************************/
BOOL isEmpty (BaseNIntegerList l)
{
	if(l.size == 0)
		return TRUE;
	else
		return FALSE;
}


/*************************************************************************************
*
*Adds the specified integer (char*, represented in the considered base) at the beginning of the specified list
*Parameters : BaseNintegerList , integer to add
*
**************************************************************************************/
BaseNIntegerList insertHead (BaseNIntegerList l, char* s)
{
	ListElement* newel = (ListElement*)malloc(sizeof(ListElement));

	newel->value = s;
	newel->previous = NULL;

	if (isEmpty(l) == TRUE)
	{
		newel->next = NULL;
		l.tail = l.head = newel;
	}
	else
	{
		newel->next = l.head;
		l.head->previous = newel;
		l.head = newel;
	}

	l.size++;

	return l;
}



/*************************************************************************************
*
*Adds the specified integer (char*) at the end of the specified list
*Parameters : BaseNintegerList , integer to add
*
**************************************************************************************/
BaseNIntegerList insertTail (BaseNIntegerList l, char* s)
{
	ListElement* newel = (ListElement*)malloc(sizeof(ListElement));

	newel->value = s;
	newel->next = NULL;

	if (isEmpty(l) == TRUE)
	{
		newel->previous = NULL;
		l.tail = l.head = newel;
	}
	else
	{
		newel->previous = l.tail;
		l.tail->next = newel;
		l.tail = newel;
	}
	l.size++;

	return l;
}


/**************************************************************************************
*
*Removes the first element of the specified list
*Parameters : BaseNIntegerList
*
*************************************************************************************/
BaseNIntegerList removeHead(BaseNIntegerList l)
{
	if (isEmpty(l) == TRUE)
		return l;

	else
	{
		if (l.size==1)
		{
			free(l.head);
			l.head = NULL;
			l.tail = NULL;
			l.size--;
		}
		else
		{
			ListElement *p;			// pas sur niveau allocation si juste pointeur ou structure donc impact aussi le free
			p = l.head;
			l.head = l.head->next;
			l.head->previous = NULL;
			l.size--;
			free(p);
			p = NULL;
		}
	}

	return l;

}




/**************************************************************************************
*
*Removes the last element of the specified list
*Parameters : BaseNIntegerList
*
*************************************************************************************/
BaseNIntegerList removeTail(BaseNIntegerList l)
{
	if(l.size==0)
		return l;
	else{
		if (l.size==1)
		{
			free(l.tail);
			l.head = NULL;
			l.tail = NULL;
			l.size--;
		}
		else
		{
			ListElement *p;			// pas sur niveau allocation si juste pointeur ou structure donc impact aussi le free
			p = l.tail;
			l.tail = l.tail->previous;
			l.tail->next = NULL;
			l.size --;
			free(p);
			p = NULL;
		}
	}

	return l;
}


/**************************************************************************************
*
*Clears and deletes the specified BaseNIntegerList
*(free the previously allocated memory)
*Parameters : l BaseNIntegerList
*
*************************************************************************************/
void deleteIntegerList(BaseNIntegerList l)
{
	while(l.size != 0)
		removeHead(l);
}


/**************************************************************************************
*
*Sums all the integers defined in the
*specified list using the Binary addition (base 2)
*and returns the corresponding results as
*an integer (char*) defined in the base of the list
*Parameters : l BaseNIntegerList
*
*************************************************************************************/
char* sumIntegerList(BaseNIntegerList l)
{
	return NULL;
}

/**************************************************************************************
*
*Converts the specified integer represented with the specified base
*into a corresponding binary integer.
*Parameters : s char to convert , n specified base
*
*************************************************************************************/
char* convertBaseToBinary(char* s, int base)
{
	long int integer = strtol(s, NULL, base);

	int rem, i=1, binary=0;
	while (integer!=0)
	{
		rem=integer%2;
		integer/=2;
		binary+=rem*i;
		i*=10;
	}
	printf("%d\n", binary);
	snprintf(s, 19, "%d", binary);
	return s;
}
 
/**************************************************************************************
*
*Converts an integer represented using a binary base into a corresponding 
*integer represented with the specified base
*Parameters : s char to convert , n specified base
*
*************************************************************************************/
char* convertBinaryToBase(char* s, int n)
{
	return s;
}

/**************************************************************************************
*
*Get an integer and verify if it is inbetween the two bounds
*Parameters: test , upper_bound , lower_bound
*
*************************************************************************************/
int get_And_Verify_Int(int test, int lower_bound, int upper_bound)
{
	scanf("%d",&test);
    while(test>upper_bound || test<lower_bound)
    {
        printf("Your choice is not valid,\n please try again.\n");
        scanf("%d",&test);
    }

    return test;
}




/**************************************************************************************
*
*Fill a linked list following the base and return it
*Parameters: base
*
*************************************************************************************/
BaseNIntegerList fill(int base)
{
	int nb, i;

	char* value = NULL;
	size_t size;

	BaseNIntegerList input = createIntegerList(base);

	printf("How many value do you want to input ?\n");

	if(scanf("%d",&nb) != 1)
	{
		do
			printf("Sorry, your value is not valid.\nPlease try again\n");
		while(scanf("%d",&nb) != 1);
	}
	getline(&value, &size, stdin);

	char *pos = NULL;
	for (i = 0; i < nb; ++i)
	{
		printf("Enter your %d th value\n",i+1 );
		getline(&value, &size, stdin);

		pos = strchr(value, '\n');
		if (pos != NULL)
			*pos = '\0';

		input = insertTail(input,value);
		value = NULL;
	}

    printf("\n\n");
	return input;
}


int maxIntegerLength(BaseNIntegerList list)
{
	int i;
	ListElement* temp;
	temp = list.head;
	int length = 0;

	for(i = 0; i < list.size; i++)
	{
		if(strlen(temp->value) > length)
			length = strlen(temp->value);
		temp = temp->next;
	}

	return length;
}

BaseNIntegerList radixSort(BaseNIntegerList list)
{
    BaseNIntegerListOfList lol = createBucketList(list.base); // lol as list of list
    int length = maxIntegerLength(list);
    int i;

	printf("max : %d\n", length);

    for(i = 1; i <= length; ++i)
    {
        lol = buildBucketList(list, i);
        list = buildIntegerList(lol);

    }
    return list;
}

//#endif
