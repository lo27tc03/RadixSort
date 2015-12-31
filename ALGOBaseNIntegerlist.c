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
	while(size(l)=/=0) do 
		removeHead(l)
	done
END
/*******************************************************************************************/


Function : sumIntegerList(l : BaseNIntegerList) : char*
BEGIN
	char *sum <-- calloc(64,1)
	char bintemp[64]<--{0}
	char sumtemp[64]<--{0}
	Integer binary1
	Integer binary2
	Integer c<--0 //carry
	integer i<--0, j<--0

	sum[0]<--'0'
	ListElement* temp <-- head(l)

	while(temp=/=UNDEFINED) do 
		value(temp)<--convertBaseToBinary(value(temp),base(l))
		temp<--next(temp)
	done

	printList(l)

	temp<--head(l)

	while(temp=/= UNDEFINED) do 
		i<--0
		c<--0
		strcpy(bintemp,value(temp))
		strcpy(sumtemp,sum)
		while(i< strlen(bintemp) || i< strlen(sumtemp)) do 
			if(i<strlen(bintemp)) then
				binary1<-- bintemp[strlen(bintemp)-i-1] - '0'
			else 
				binary1<--0
			endif
			if (i<strlen(sumtemp))then
				binary2<--sumtemp[i]-'0'
			else
				binary2<--0
			endif

			printf("1 = "binary1 "2 =" binary2)

			sumtemp[i++]<--((binary1+ binary2 + c)mod(2))+'0'
			printf("sum" (binary1 + binary2 +c)mod(2))
			c<--(binary1 + binary2 + c) / 2

			if(i = 64) then
				printf("The sum exceeds 2^64-1, cannot continue")
				sumIntegerList<--sumIntegerList
			endif
		done

		if(c=/=0) then
			sumtemp[i++]<--49
			printf("carry" sumtemp[i-1])
		endif

		strcpy(sum, sumtemp)
		printf(sum)

		for(j=0 to j<64 increasing one by one) do 
			sumtemp[j]<--0
		done

		temp<-- next(temp)
	done

	strcpy(sumtep, sum)

	for(j=0 to j<strlen(sumtemp) increasing one by one) do 
		sum[j]<-- sumtemp[strlen(sumtemp) - j - 1]
	done

	convertBinaryToBase(sum,10)

	sumIntegerList<--sum
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


Function : convertBinaryToBase(s: char*, base : Integer) : char*
BEGIN
	Integer output<--0
	char temp[64]
	Integer coef<--1
	Integer i<--0
	size_t length<--strlen(s)
	strcpy(temp,s)

	for (i=0 to i<length increasing one by one) do 
		temp[i]<-- s[length - i - 1]
	done

	printf(temp)

	for (i=0 to i<length increasing one by one) do 
		output += coef * (temp[i]-48)
		coef <-- coef * 2
	done

	sprintf(s, "%d",output)

	char *a = convDecToBase(strtol(s,UNDEFINED,10),base)
	strcpy(s,a)
	free(a)

	convertBinaryToBase<--s

END

/*******************************************************************************************/
Function convDecToBase(dec : Integer, base : Integer): char*
BEGIN
	if (dec = 0) then
		convDecToBase<--0
	endif

	char NUMS[] <-- "0123456789ABCDEF"
	char *res = calloc(64, sizeof(char))
	int i<--0

	do (res[i]<--NUMS[dec%base]
		dec/= base
		i<--i+1)
	while(dec =/= 0)

	convDecToBase<--res
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


	for (i=1 to i<= length increasing one by one) do 
		lol<--buildBucketList(list,i)
		list<--buildIntegerList(lol)
	done

	radixSort<--list
END

/*******************************************************************************************/


Function loadDemo(void): BaseNIntegerList
BEGIN
	FILE *demo <-- UNDEFINED
	char value[64]
	char *pos<--UNDEFINED
	BaseNIntegerList input<--createIntegerList(10)

	demo<--fopen("demo.txt","r")

	if (demo = UNDEFINED) then
		printf("couldn't open demo file")
		exit(1)
	endif

	printf("Remember : you can manually change demo.txt with your text editor\n")

	while (fgets(value, 64, demo) =/= UNDEFINED) do 
		pos<--strchr(value, '\n')
		*pos<--'\0'
		input<-- insertTail(input,value)
	done

	fclose(demo)

	loadDemo<--input
END

/*******************************************************************************************/

Procedure printList(list : BaseNIntegerList)
BEGIN
	ListElement *temp
	temp<--head(list)
	while(temp=/=UNDEFINED)
		printf(value(temp))
		temp<--next(temp)
	done
END

/*******************************************************************************************/

Procedure tryConvert(list :BaseNIntegerList)
BEGIN
	ListElement *temp<--head(list)
	Integer i<--0

	for(i=0 to i<size(list) increasing one by one) do 
		convertBaseToBinary(value(temp),base(list))
		temp<--next(temp)
	done

	printList(list)

	temp<--head(list)
	while(temp=/=UNDEFINED) do 
		convertBinaryToBase(value(temp),base(list))
		temp<--next(temp)
	done
	printList(list)
END
