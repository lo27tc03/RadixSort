//ALGOBaseNIntegerListOfList.c


Function : createBucketList(base : Integer) : BaseNIntegerListOfList
BEGIN
	BaseNIntegerListOfList l 
	base(l)<--base
	error(l)<--UNDEFINED

	Integer i 
	for i from 0 to 16 increasing one by one do 
		list(l)[i]<--createBucketList(base)
	done

	createBucketList<-- l 
END
/*******************************************************************************************/

Function : buildBucketList (list : BaseNIntegerList , pos : Integer) : BaseNIntegerListOfList
BEGIN
	BaseNIntegerListOfList bucketList 
	bucketList<-- createBucketList(base)

	if size(list) = 0 then 
		error(bucketList) <-- TRUE
		buildBucketList <-- bucketList
	endif

	Integer bucket;
	Integer i<--0

	while not isEmpty(list) do 
		char* temp<--value(head(list))

		list<--removeHead(list)
		char chartemp
		chartemp<-- (char)temp[strlen(temp) - pos]
		printf (chartemp " (debug)")
		bucket<--strtol(&chartemp, 0, 36)

		if bucket > 17 then 
			error(bucketList)<--TRUE
			buildBucketList<-- bucketList
		endif

		list(bucketList)[bucket]<--insertTail(list(bucketList)[bucket], temp)
	done

	buildBucketList<-- bucketList
END

/*******************************************************************************************/

Function : buildIntegerList(bucketList : BaseNIntegerListOfList) : BaseNIntegerList
BEGIN
	BaseNIntegerList output
	Integer i

	for i from 1 to 16 increasing one by one do 
		while not isEmpty(list(bucketList)[i]) do 
			output<-- insertTail(output, value(head(list(bucketList))))[i]
			list(bucketList)[i]<--removeHead(list(bucketList)[i])
		done
	done

	buildIntegerList<-- output
END
/*******************************************************************************************/
Procedure : printListOfList(lol :BaseNIntegerListOfList)
BEGIN
	Integer i<--0
	ListElement *temp <-- head(list[0](lol))	//pas sur là

	for (i=0 to i=15 increasing one by one) do 
		temp<--head(list[0](lol))	//pas sur là
		printf(i)
		while (temp =/= UNDEFINED) do 
			printf(value(temp))
			temp<--next(temp)
		done
		printf("\n")
	done

	while(getchar() =/= '\n') do 
		system("clear")
	done

	printListOfList<--EXIT_SUCCESS

END
/*******************************************************************************************/

Function : addIntegerIntoBucket (listOfList : BaseNIntegerListOfList, integer : char* , bucket : Integer)
BEGIN
END

/*******************************************************************************************/


Procedure : deleteBucketList(listOfList : BaseNIntegerListOfList)
BEGIN
END
/*******************************************************************************************/

Function : radixsort(listOfList : BaseNIntegerListOfList)
BEGIN
END

