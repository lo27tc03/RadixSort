//ALGOBaseNIntegerList.h


/*******************************************************************************************/
Function : createIntegerList(base : Integer) : BaseNIntegerList
BEGIN
	BaseNIntegerList l
	head(l)<--UNDEFINED
	tail(l)<--UNDEFINED
	base(l)<--base
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
		previous(head(l)) <-- newel
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
		next(tail(l))<--newel
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
			head(l)<--next(head(l))
			previous(head(l))<-- UNDEFINED
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
			tail(l)<--previous(tail(l))
			next(tail(l))<-- UNDEFINED
			size(l)<--size(l) - 1
			free(p)
			p<--UNDEFINED
		endif
	endif

	removeTail<--l
END
/*******************************************************************************************/
Process : deleteIntegerList (l : BaseNIntegerList) //////////A REPRENDRE C MODIFIÉ
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
/*******************************************************************************************/


Function : sumIntegerList(l : BaseNIntegerList) : char*
BEGIN
END

/*******************************************************************************************/


Function : convertBaseToBinary(s : char*, n : Integer) : Integer
BEGIN
	long Integer integer <-- strtol(s,UNDEFINED,base)

	Integer rem
	Integer i<--1
	Integer binary<--0

	while(integer =/= 0) do 
		rem<--integer%2
		integer/<--2
		binary+<--rem*i
		i*<--10
	done

	printf(binary)
	snprintf(s,19,binary)

	convertBaseToBinary<--s
END

/*******************************************************************************************/


Function : convertBinaryToBase(s: char*, n : Integer) : char*
BEGIN
END

/*******************************************************************************************/


Function get_And_Verify_Int(test : Integer ,upper_bound :  Integer ,lower_bound :  Integer ) : Integer
BEGIN
	read test
	
	while (test>upper_bound OR test<lower_bound) do
		print "Your choice is not valid, please try again."
		read test
	done

	get_And_Verify_Int <-- test
END

/*******************************************************************************************/


Function : fill(base : Integer) : BaseNIntegerList
BEGIN
	Integer nb
	Integer i
	char* value <-- UNDEFINED
	size_t size

	BaseNIntegerList input <-- createIntegerList(base)

	printf("How many value do you want to input?")

	if (scanf(nb) =/= 1) then
		do
			printf("Sorry, your value is not valid. Please try again")
		while(scanf(nb) =/= 1)
		done
	endif
	getline(value,size,stdin)

	char *pos <-- UNDEFINED

	for (i=0 to i<nb increasing one by one) do
		printf("Enter your "i+1" th value")
		getline(value,size,stdin)

		pos<--strchr(value, '\n')
		if (pos =/= UNDEFINED) then
			*pos <--'\0'
		endif
		input<--insertTail(input,value)
		value<--UNDEFINED
	done

	fill<-- input

END


/*******************************************************************************************/


Function maxIntegerLength(list : BaseNIntegerList) : Integer
BEGIN
	Integer i
	ListElement* temp
	temp<--head(list)
	Integer length<--0

	for (i=0 to i<size(list) increasing one by one) do 
		if (strlen(value(temp))>length) then
			length<--strlen(value(temp))
		endif
		temp<--next(temp)
	done

	maxIntegerLength<--lenght
END


/*******************************************************************************************/

Function radixSort(list : BaseNIntegerList) : BaseNIntegerList
BEGIN
	BaseNIntegerList lol<--createBucketList(base(list))
	Integer length <-- maxIntegerLength(list)
	Integer i

	printf("max : length")

	for (i=1 to i<= length increasing one by one) do 
		lol<--buildBucketList(list,i)
		list<--buildIntegerList(lol)
	done

	radixSort<--list
END



