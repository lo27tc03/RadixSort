//#include "BaseNIntegerList.h"
//#include "BaseNIntegerListOfList.h"

int main(int argc, char** argv)
{
    int i,choice,base;

    printf("    |———————————————— Welcome In Our Radix Sort Programm ————————————————|\n\n\n\n");
    printf("Implemented by G.Duvauchelle and S.Prost      UTBM Students in L027\n\n\n\n");
    printf("What do you want to do ?\n\n1) Fullfill your List \n2) Select the base you want to work in \n3) Sort your list using Radix Sort \n4) Quit ");
    

    choice=get_And_Verify_Int(choice,1,4);  //voir BaseNIntegerList.c
    
    switch (choice)
    {
    case 1:
    //function remplissage
      break;
    case 2:
    printf("Enter a base between 2 and 16");
    get_And_Verify_Int(base,16,2);
      break;
    case 3:
    RadixSort
      break;
    case 4:
    return EXIT_SUCCESS;
      break;
    }

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
