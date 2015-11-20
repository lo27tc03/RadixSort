//ALGOBaseNIntegerList.h


/*******************************************************************************************/
Function : createIntegerList(v : Integer) : BaseNIntegerList
BEGIN
	BaseNIntegerList l
	head(l)<--UNDEFINED
	tail(l)<--UNDEFINED
	base(l)<--v
	size(l)<--0

	BaseNIntegerList <-- l
END

/*******************************************************************************************/
Function : isEmpty (l : BaseNIntegerList) : BOOL
BEGIN
	BaseNIntegerList <-- (size(l) = 0)
END

/*******************************************************************************************/
Function : insertHead (l : BaseNIntegerList , s : char* ) : BaseNIntegerList
BEGIN
	newel <-- create(ListElement)
	value(newel) <-- s
	previous(newel) <-- UNDEFINED

	if isEmpty(l) = TRUE then
		next(newel)<-- UNDEFINED
		tail(l)<--head(l)<--newel
	else
		next(newel)<--head(l)
		head(l)->(previous) <-- newel
		head(l)<-- newel
	endif

	size(l)<--size(l) + 1

	insertHead <-- l
END

/*******************************************************************************************/
Function : insertTail (l : BaseNIntegerList , s : char*) : BaseNIntegerList
BEGIN
	newel <-- create(ListElement)
	value(newel)<--s
	next(newel)<--UNDEFINED

	if isEmpty(l) = TRUE then
		previous(newel) <-- UNDEFINED
		tail(l) <-- head(l) <-- newel
	else
		previous(newel) <-- tail(l)
		tail(l)-->(next)<--newel
		tail(l)<--newel
	endif

	size(l)<--size(l) + 1

	insertTail <-- l
END

/*******************************************************************************************/
Function : removeHead (l : BaseNIntegerList) : BaseNIntegerList
BEGIN
	if isEmpty(l) = TRUE then
		removeHead<--l
	else
		if size(l) = 1 then
			free(head(l))
			head(l)<--UNDEFINED
			tail(l)<--UNDEFINED
			size(l)<--size(l) - 1
		else
			ListElement *p 
			p<--head(l)
			head(l)<--head(l)-->next
			head(l)-->previous <-- UNDEFINED
			free(p)
			size(l)<--size(l) - 1
			p<--UNDEFINED
		endif
	endif

	removeHead<--l
END

/*******************************************************************************************/
Function : removeTail (l: BaseNIntegerList ) : BaseNIntegerList
BEGIN
	if isEmpty(l) = TRUE then
		removeTail<--l
	else
		if size(l) = 1 then
			free(tail(l))
			head(l)<--UNDEFINED
			tail(l)<--UNDEFINED
			size(l)<--size(l) - 1
		else
			ListElement *p 
			p<--tail(l)
			tail(l)<--tail(l)-->previous
			tail(l)-->next <-- UNDEFINED
			size(l)<--size(l) - 1
			free(p)
			p<--UNDEFINED
		endif
	endif

	removeTail<--l
END
/*******************************************************************************************/
Process : deleteIntegerList (l : BaseNIntegerList)
BEGIN
	if head(l) = UNDEFINED then
		deleteIntegerList<--l
	else
		if head(l)-->next <-- UNDEFINED then
			free(l)
			l<--UNDEFINED
			deleteIntegerList<--EXIT_SUCCESS
		else
			BaseNIntegerList* p , k
			p<--k<--l
			while head(l)--> =/= UNDEFINED do 
				k<--l
				head(l)<-- head(l)-->next
				free(k)
				k<--UNDEFINED
				k<--head(l)
			done
			l<--UNDEFINED
			deleteIntegerList<--EXIT_SUCCESS
		endif
	endif
END

