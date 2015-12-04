//#include "BaseNIntegerList.h"
//#include "BaseNIntegerListOfList.h"

int main(int argc, char** argv)
{
    int i;

    printf("    |———————————————— Welcome In Our Radix Sort Programm ————————————————|\n\n\n\n");
    printf("Implemented by G.Duvauchelle and S.Prost      UTBM Students in L027\n\n\n\n");


  BaseNIntegerList l = createIntegerList(10);
    l = insertHead(l, "4747");
    l = insertHead(l, "2222");
    l = insertHead(l, "5353");



    BaseNIntegerListOfList lol = createBucketList(10);
    lol = buildBucketList(l, 1);
    l = buildIntegerList(lol);
    lol = buildBucketList(l, 2);
    l = buildIntegerList(lol);
    lol = buildBucketList(l, 3);
    l = buildIntegerList(lol);
    lol = buildBucketList(l, 4);
    l = buildIntegerList(lol);

    printf("%s, %s, %s \n", l.head->value, l.head->next->value, l.tail->value);


    return EXIT_SUCCESS;


}
