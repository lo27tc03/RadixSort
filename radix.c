#include <BaseNIntegerList.h>
#include <BaseNIntegerListOfList.h>


int main(int argc, char** argv)
{
    int base = 10;


    printf("\t|———————————————— Welcome In Our Radix Sort Programm ————————————————|\n\n\n\n");
    printf("Implemented by G.Duvauchelle and S.Prost\tUTBM Students in L027\n\n\n\n");/*
    printf("What do you want to do ?\n\n1) Fullfill your List \n2) Select the base you want to work in \n3) Sort your list using Radix Sort \n4) Quit \n");*/


    //choice=get_And_Verify_Int(choice,1,4);  //voir BaseNIntegerList.c


    printf("Enter a base between 2 and 16");
    get_And_Verify_Int(base,2,16);

    BaseNIntegerList input = createIntegerList(base);

    input = fill(base);

    BaseNIntegerListOfList lol = createBucketList(10);
    lol = buildBucketList(input, 1);
    input = buildIntegerList(lol);
    lol = buildBucketList(input, 2);
    input = buildIntegerList(lol);
    lol = buildBucketList(input, 3);
    input = buildIntegerList(lol);
    lol = buildBucketList(input, 4);
    input = buildIntegerList(lol);

    printf("%s, %s, %s \n", input.head->value,input.head->next->value, input.tail->value);


    return EXIT_SUCCESS;


}
