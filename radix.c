#include <BaseNIntegerList.h>
#include <BaseNIntegerListOfList.h>


int main(int argc, char** argv)
{
    /*char test[20] = "66666            ";
    //long int x = 6666444444666666666;
    //int length = snprintf(0, 0, "%lu", x);
    //printf("%d\n", length);
    printf("%s\n", convertBaseToBinary(test, 10));
    return 0;*/

<<<<<<< Updated upstream

=======
    printf("    |———————————————— Welcome In Our Radix Sort Programm ————————————————|\n\n\n\n");
    printf("Implemented by G.Duvauchelle and S.Prost      UTBM Students in L027\n\n\n\n");
    printf("What do you want to do ?\n\n1) Fill your List \n2) Select the base you want to work in \n3) Sort your list using Radix Sort \n4) Quit ");
    

    choice=get_And_Verify_Int(choice,1,4);  //voir BaseNIntegerList.c
    
    switch (choice)
    {
    case 1:
    //function fill
      break;
    case 2:
    printf("Enter a base between 2 and 16");
    get_And_Verify_Int(base,16,2);
      break;
    case 3:
    RadixSort()
      break;
    case 4:
    return EXIT_SUCCESS;
      break;
    }
>>>>>>> Stashed changes

    int base = 10;
    ListElement *temp;


    printf("\t| Welcome In Our Radix Sort Programm |\n\n\n\n");
    printf("Implemented by G.Duvauchelle and S.Prost\tUTBM Students in L027\n\n\n\n");/*
    printf("What do you want to do ?\n\n1) Fullfill your List \n2) Select the base you want to work in \n3) Sort your list using Radix Sort \n4) Quit \n");*/

    //choice=get_And_Verify_Int(choice,1,4);  //voir BaseNIntegerList.c

    /*printf("Enter a base between 2 and 16");
    get_And_Verify_Int(base,2,16);*/

    BaseNIntegerList input = createIntegerList(base);
    BaseNIntegerList sortedList = createIntegerList(base);

    input = fill(base);

    temp = input.head;
    printf("unsorted list : ");
    while(temp != NULL)
    {
        printf("%s\t", temp->value);
        temp = temp->next;
    }
    printf("\n\n");


    sortedList = radixSort(input);


    temp = sortedList.head;
    printf("sorted list : ");
    while(temp != NULL)
    {
        printf("%s\t", temp->value);
        temp = temp->next;
    }
    printf("\n\n");

    return EXIT_SUCCESS;
}
