#include <BaseNIntegerList.h>
#include <BaseNIntegerListOfList.h>
#include <string.h>


int main(int argc, char** argv)
{
    int base = 10;
    ListElement *temp;


    system("clear");
    printf("    |———————————————— Welcome In Our Radix Sort Programm ————————————————|\n\n\n\n");
    printf("Implemented by G.Duvauchelle and S.Prost      UTBM Students in L027\n\n\n\n");
    printf("What do you want to do ?\n\n1) Input your own list\n2) Try the list in the demo.txt file \n3) Quit \n\n");

    int choice = 0;
    get_And_Verify_Int(&choice,1,3);  //voir BaseNIntegerList.c
    BaseNIntegerList input;
    BaseNIntegerList sortedList;

    switch (choice)
    {
        case 1:
            system("clear");
            printf("Enter a base between 2 and 16\n");
            get_And_Verify_Int(&base,2,16);
            input = createIntegerList(base);
            sortedList = createIntegerList(base);
            input = fill(base);
            break;

        case 2:
            input = loadDemo();
            sortedList = createIntegerList(base);

            break;

        case 3:
            return 0;
            break;

    }



    temp = input.head;
    printf("The unsorted list is : \n");
    while(temp != NULL)
    {
        printf("%s\n", temp->value);
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
