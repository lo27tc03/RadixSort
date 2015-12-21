#include <BaseNIntegerList.h>
#include <BaseNIntegerListOfList.h>
#include <string.h>

BaseNIntegerList createIntegerList (int base)
{

	BaseNIntegerList l;
	l.head = NULL;
	l.tail = NULL;
	l.base = base;
	l.size = 0;

	return l;
}

BOOL isEmpty (BaseNIntegerList l)
{
	if(l.size == 0)
		return TRUE;
	else
		return FALSE;
}

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

void deleteIntegerList(BaseNIntegerList l)
{
	while(l.size != 0)
		removeHead(l);
}

char* sumIntegerList(BaseNIntegerList l)
{
	return NULL;
}
/**************************************************************************************
*
*sums all the integers defined in the
*specified list using the Binary addition (base 2)
*and returns the corresponding results as
*an integer (char*) defined in the base of the list
*
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
* converts the specified integer s
* represented with the specified base (Integer, second parameter)
* into a corresponding binary integer (base 2).
*
*
*************************************************************************************/

char* convertBinaryToBase(char* s, int n)
{
	return s;
}
/**************************************************************************************
*
*converts an integer represented using a binary base (base 2)
*into a corresponding integer represented
*with the specified base (Integer, second parameter)
*
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
*Get an integer and verify if it is inbetween the two bounds
*Parameters: test , upper_bound , lower_bound
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
/**************************************************************************************
*
*Fill a linked list following the base and return it
*Parameters: base
*
*************************************************************************************/

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
