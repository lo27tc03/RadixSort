//#ifndef
//#define



#include <stdlib.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0
typedef int BOOL;

typedef struct BaseNIntegerList1
{
	struct BaseNIntegerList1 *head;
	struct BaseNIntegerList1 *tail;
	int base;
	int size;
}BaseNIntegerList;

typedef struct ListElement1
{
	struct ListElement1 *previous;
	struct ListElement1 *next;
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

	newel->value = s;				// je suis pas sur pour ça     ++    vérification de la base ou pas ? --> autre fonction
	
	if (isEmpty(l)==0)
	{
		newel->next = NULL;
		l.tail = newel;
	}else{
		newel->next = l.head;
		(l.head)->previous = newel;
		//(*l).head->previous = newel;
		l.head = newel;
	}
	l.size = l.size + 1;
	newel->previous = NULL;

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

	newel.value =  s; 			//IDEM que insertHead

	if (isEmpty(l)==0)
	{
		newel.previous = NULL;
		l.head = newel;
	}else{
		newel.previous = l.tail;
		(l.tail)->next = newel;
		l.tail = newel
	}
	l.size = l.size + 1;
	newel.next = NULL;

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
	if (l.size==0)
	{
		return l;
	}else{
		if (l.size==1)
		{
			free(l.head);
			l.head = NULL;
			l.tail = NULL;
			l.size = 0;
		}else{
			BaseNIntegerList* p;			// pas sur niveau allocation si juste pointeur ou structure donc impact aussi le free
			p->head = l.head;
			l.head = (l.head)->next;
			(l.head)->previous = NULL;
			l.size = l.size - 1;
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
	{
		return l;
	}else{
		if (l.size==1)
		{
			free(l.head);
			l.head = NULL;
			l.tail = NULL;
			l.size = 0;
		}else{
			BaseNIntegerList* p;			// pas sur niveau allocation si juste pointeur ou structure donc impact aussi le free
			p->tail = l.tail;
			l.tail = (l.tail)->previous;
			(l.tail)->next = NULL;
			l.size = l.size - 1;
			free(p);
			p = NULL;
		}
	}

	return l;
}




void deleteIntegerList(BaseNIntegerList l);
/**************************************************************************************
*
*clears and deletes the specified BaseNIntegerList 
*(free the previously allocated memory)
*
*************************************************************************************/

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