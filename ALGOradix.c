//ALGOradix.c

main : (argc : Integer , argv : Char**)
BEGIN
	Integer i 
	BaseNIntegerList l 
	l<--createIntegerList(10)
	l<--insertHead(l, "4747")
	l<--insertHead(l, "2222")
	l<--insertHead(l, "5353")


	BaseNIntegerListOfList lol 
	lol<--createBucketList(10)
	lol<--buildBucketList(l, 1)
	l<--buildIntegerList(lol)
	lol<--buildBucketList(l, 2)
	l<--buildIntegerList(lol)
	lol<--buildBucketList(l, 3)
	l<--buildIntegerList(lol)
	lol<--buildBucketList(l, 4)
	l<--buildIntegerList(lol)

	printf(value(head(l)) value(next(head(l))) value(tail(l)) );

	main<--EXIT_SUCCESS

END