#include <BaseNIntegerList.h>

typedef struct BaseNIntegerList
{
	struct BaseNIntegerList *head;
	struct BaseNIntegerList *tail;
	int base;
	int size;
}BaseNIntegerList;

typedef struct elem {
	struct elem *previous;
	struct elem *next;
	int value;
}ListElement;



/**************************************************************************************
*
*Creates a new empty BaseNIntegerList for storing integers in the specified base
*Parameters : integer of the base
*
*************************************************************************************/
BaseNIntegerList createIntegerList (int v)
{

	BaseNIntegerList l ;
	l.head = NULL;
	l.tail = NULL;
	l.base = v;
	l.size = 0;

	return l;
}

/*************************************************************************************
*Test if the list is empty
*Return 0 if empty, 1 else
*Parameters : BaseNintegerList to test
**************************************************************************************/
BOOL isEmpty (BaseNIntegerList l)
{
	return (l.size==0);
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

	newel.value = s;
	newel.previous = NULL;

	if (isEmpty(l) == TRUE)
	{
		newel.next = NULL;
		l.tail = l.head = newel;
	}
	else
	{
		newel.next = l.head;
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
	ListElement newel = (ListElement*)malloc(sizeof(ListElement));

	newel.value = s; 			//IDEM que
	newel.next = NULL;

	if (isEmpty(l) == TRUE)
	{
		newel.previous = NULL;
		l.tail = l.head = newel;
	}
	else
	{
		newel.previous = l.tail;
		l.tail->next = newel;
		l.tail = newel
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
	if (isEmpty(l) == TRUE
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
	if (l.size==0)
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
*clears and deletes the specified BaseNIntegerList
*(free the previously allocated memory)
*
*************************************************************************************/
void deleteIntegerList(BaseNIntegerList l)
{
	if (l.head == NULL)
	{
		return l;
	}else{
		if (l.head->next == NULL)
		{
			free(l);
			l = NULL;
			return EXIT_SUCCESS;
		}else{

			BaseNIntegerList* p,k;
			p = k = l;
			while(l.head->next != NULL)
			{
				k = l;
				l.head = l.head->next;
				free(k);
				k = NULL;
				k l.head;
			}
			return EXIT_SUCCESS;
			}
	}
}











char* sumIntegerList(BaseNIntegerList l);
/**************************************************************************************
*
*sums all the integers defined in the
*specified list using the Binary addition (base 2)
*and returns the corresponding results as
*an integer (char*) defined in the base of the list
*
*
*************************************************************************************/

char* convertBaseToBinary(char* s, int n);
/**************************************************************************************
*
*converts the specified integer (char*)
*represented with the specified base (Integer, second parameter)
*into a corresponding binary integer (base 2).
*
*
*************************************************************************************/

char* convertBinaryToBase(char* s, int n);
/**************************************************************************************
*
*converts an integer represented using a binary base (base 2)
*into a corresponding integer represented
*with the specified base (Integer, second parameter)
*
*
*************************************************************************************/

//#endif
