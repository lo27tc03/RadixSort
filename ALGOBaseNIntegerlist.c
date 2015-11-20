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


