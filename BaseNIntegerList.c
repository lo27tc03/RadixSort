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
	newel->value = calloc(64, 1);

	strcpy(newel->value, s);
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
	newel->value = calloc(64, 1);

	strcpy(newel->value, s);
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
			free(l.tail->value);
			free(l.head);
			l.head = NULL;
			l.tail = NULL;
			l.size--;
		}
		else
		{
			ListElement *p;
			p = l.head;
			l.head = l.head->next;
			l.head->previous = NULL;
			l.size--;
			free(p->value);
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
			free(l.tail->value);
			free(l.tail);
			l.head = NULL;
			l.tail = NULL;
			l.size--;
		}
		else
		{
			ListElement *p;
			p = l.tail;
			l.tail = l.tail->previous;
			l.tail->next = NULL;
			l.size --;
			free(p->value);
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
	char *sum = calloc(64, 1); //the best way we found to return a string, we have to free just after we called the function
	char bintemp[64] = {0};
	char sumtemp[64] = {0};
	int binary1;
	int binary2;
	int c = 0; //carry
	int i = 0, j = 0;


	sum[0] = '0';


	ListElement* temp = l.head;


	while(temp != NULL) //convert all values in the list to binary
	{
		temp->value = convertBaseToBinary(temp->value, l.base);
		temp = temp->next;
	}

	temp = l.head;

	while(temp != NULL)
	{
		i = 0;
		c = 0;
		strcpy(bintemp, temp->value);
		strcpy(sumtemp, sum);
		while (i  < strlen(bintemp) || i < strlen(sumtemp) )
	    {
			if(i<strlen(bintemp)) //if there is more step than bits in the value we do the calculation with 0
				binary1 = bintemp[strlen(bintemp)-i-1] - '0';
			else
				binary1 = 0;

			if(i<strlen(sumtemp)) //same for the sum
				binary2 = sumtemp[i] - '0';
			else
				binary2 = 0;


	        sumtemp[i++] = ((binary1 + binary2 + c) % 2) + '0'; //compute the value
	        c =(binary1 + binary2 + c) / 2; //compute the carry


			if (i == 64) //because convertBinaryToBase cannot convert numbers greater than 64bits (long int)
			{
				printf("\nthe sum exceeds 2^64-1, cannot continue\n");
				return sum;
			}


	    }


	    if (c != 0) 
		{
	        sumtemp[i++] = 49;
		}


		strcpy(sum, sumtemp);

		for(j=0;j<64;j++)
			sumtemp[j] = 0;

		temp = temp->next;

	}

	strcpy(sumtemp, sum);

	for(j=0;j<strlen(sumtemp);j++) //reverses the binary number
	{
		sum[j] = sumtemp[strlen(sumtemp) - j - 1];
	}

	convertBinaryToBase(sum, 10);

	return sum;

}

/**************************************************************************************
*
*Converts the specified integer represented with the specified base
*into a corresponding binary integer.
*Parameters : s char to convert , n specified base
*
*************************************************************************************/
char* convertBaseToBinary(char* input, int base)
{

	char binary[64];
	long int integer = strtol(input, NULL, base);

	int rem, i=0;

	while (integer!=0)
	{
		rem=integer%2;
		integer/=2;
		binary[i] = rem;
		i++;
	}
	printf("\n");
	binary[i] = '\0';

	int j;

	input[i] = '\0';
	i--;

	for(j = 0; i >= 0; i--)
		input[i] = binary[j++] + '0';

	return input;
}

/**************************************************************************************
*
*Converts an integer represented using a binary base into a corresponding
*integer represented with the specified base
*Parameters : s char to convert , n specified base
*
*************************************************************************************/

char* convertBinaryToBase(char* s, int base)
{
	long int output = 0;
	char temp[64];
	long int coef = 1;
	int i = 0;

	size_t length = strlen(s);
	strcpy(temp, s);

	for(i = 0; i < length; i++)
		temp[i] = s[length - i -1];


	for(i = 0; i < length; ++i)
	{
		output += coef * (temp[i] - '0');
		coef = coef * 2;
	}

	sprintf(s, "%ld", output);


	if(base != 10) //no need to convert to decimal if it already is
	{
	char *a = convDecToBase(strtol(s, NULL, 10), base);
	strcpy(s, a);
	free(a);
	}

	return s;
}

/**************************************************************************************
*
*Converts an integer represented using decimal base into a corresponding
*integer represented with the specified base
*Parameters : int dec the integer to convert , int base the base wanted
*
*************************************************************************************/
char* convDecToBase(int dec, int base)
{
	if(dec == 0)
		return 0;

	char NUMS[] = "0123456789ABCDEF";
	char *res = calloc(64, sizeof(char));
	int i = 0;

	do{
		res[i] = NUMS[dec%base];
        dec /= base;
		i++;
	}while(dec != 0);

	return res;
}

/**************************************************************************************
*
*Get an integer and verify if it is inbetween the two bounds
*Parameters: test , upper_bound , lower_bound
*
*************************************************************************************/
void get_And_Verify_Int(int *test, int lower_bound, int upper_bound)
{

	scanf("%d",test);

    while(*test>upper_bound || *test<lower_bound)
    {
		while( getchar() != '\n' ); //avoid infinite loop
        printf("Your choice is not valid, please try again.\n");
		fflush(stdin);
        scanf("%d",test);
    }

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
		{
			while(getchar() != '\n');
			printf("Sorry, your value is not valid.\nPlease try again\n");
		}
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
*returns the number of digit of the integers with the most digit
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



/************************************************************************************
*
*sorts the specified BaseNIntegerList using the proposed radix sort approach.
*See Figures 3-7 for a detailed description of the expected behavior of this function.
*details precises if we print steps or not
*
************************************************************************************/
BaseNIntegerList radixSort(BaseNIntegerList list, BOOL details)
{
    BaseNIntegerListOfList lol = createBucketList(list.base); // lol as in list of list
    int length = maxIntegerLength(list);
    int i;


    for(i = 1; i <= length; ++i)
    {
        lol = buildBucketList(list, i);
		if(details)
			printListOfList(lol);
        list = buildIntegerList(lol);
    }
    return list;
}




/**************************************************************************************
*
*puts the numbers in demo.txt in a list and returns it
*no parameters
*
*************************************************************************************/
BaseNIntegerList loadDemo()
{
    FILE *demo = NULL;
    char value[64];
	char *pos = NULL;
	int base;


    demo = fopen("demo.txt", "r");
    if(demo == NULL)
    {
        printf("couldnt open demo file\n");
        exit(1);
    }
    printf("\n\nRemember: you can manually change demo.txt with your text editor\n\n");

	fscanf(demo, "base : %d", &base);
    BaseNIntegerList input = createIntegerList(base);

	fgets(value, 64, demo);

    while(fgets(value, 64, demo) != NULL)
    {
		pos = strchr(value, '\n');
		*pos = '\0';
        input = insertTail(input, value);
    }

    fclose(demo);

	return input;

}


/**************************************************************************************
*
*prints the list in parameters
*
*************************************************************************************/
void printList(BaseNIntegerList list)
{
	ListElement *temp;
    temp = list.head;
    while(temp != NULL)
    {
        printf("%s\n", temp->value);
        temp = temp->next;
    }
    printf("\n\n");
}

/**************************************************************************************
*
*converts the list in parameters to binary
*prints it
*converts back to its original base
*
*************************************************************************************/
void tryConvert(BaseNIntegerList list)
{
	ListElement *temp = list.head;
	int i = 0;

	for(;i<list.size;++i)
	{
		convertBaseToBinary(temp->value, list.base);
		temp = temp->next;
	}

	printList(list);
	printf("\n\n");

	temp = list.head;
	while(temp!=NULL)
	{
		convertBinaryToBase(temp->value, list.base);
		temp = temp->next;
	}
	printList(list);
	printf("\n\n");
}



//#endif
