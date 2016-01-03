//ALGOBaseNIntegerListOfList.c


Function : createBucketList(base : Integer) : BaseNIntegerListOfList
BEGIN
	BaseNIntegerListOfList l 
	base(l)<--base
	error(l)<--FALSE

	Integer i 
	for i from 0 to 16 increasing one by one do 
		list(l)[i]<--createIntegerList(base)
	done

	createBucketList<-- l 
END
/*******************************************************************************************/

Function : buildBucketList (list : BaseNIntegerList , pos : Integer) : BaseNIntegerListOfList
BEGIN
	BaseNIntegerListOfList bucketList
	bucketList<-- createBucketList(base(list))
	char* temp
	char chartemp

	if (size(list) = 0) then 
		error(bucketList) <-- TRUE
		buildBucketList <-- bucketList
	endif

	Integer bucket;

	while not isEmpty(list) do 
		temp<--value(head(list))

		chartemp<-- temp[strlen(temp) - pos]
		bucket<--strtol(&chartemp, 0, 36)

		if bucket > 17 then 
			error(bucketList)<--TRUE
			buildBucketList<-- bucketList
		endif

		list(bucketList)[bucket]<--insertTail(list(bucketList)[bucket], temp)
		list<--removeHead(list)
	done

	buildBucketList<-- bucketList
END

/*******************************************************************************************/

Function : buildIntegerList(bucketList : BaseNIntegerListOfList) : BaseNIntegerList
BEGIN
	BaseNIntegerList output<-- createIntegerList(base(bucketList))
	Integer i

	for (i from 1 to i<=16 increasing one by one) do 
		while (size(list[i](bucketList)) =/= 0)do 
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

	for (i=0 to i<16 increasing one by one) do 
		temp<--head(list[0](lol))	//pas sur là
		printf(i)
		while (temp =/= UNDEFINED) do 
			printf(value(temp))
			temp<--next(temp)
		done
		printf("\n")
	done

	system("clear")
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

