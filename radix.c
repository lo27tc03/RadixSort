#include <BaseNIntegerList.h>
#include <BaseNIntegerListOfList.h>
#include <string.h>


int main(int argc, char** argv)
{
    int base = 10;
    //ListElement *temp;


    system("clear");
    printf("    |———————————————— Welcome In Our Radix Sort Programm ————————————————|\n\n\n\n");
    printf("Implemented by G.Duvauchelle and S.Prost      UTBM Students in L027\n\n\n\n");
    printf("What do you want to do ?\n\n1) Input your own list\n2) Try the list in the demo.txt file \n3) Quit \n\n");

    int choice = 0;
    get_And_Verify_Int(&choice,1,3);

    BaseNIntegerList input;
    BaseNIntegerList sortedList;

    system("clear");

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
            sortedList = createIntegerList(input.base);

            break;

        case 3:
            return 0;
            break;

    }



    printf("The unsorted list is : \n");
    printList(input);

    char *sum;

    printf("\nWhat do you want to do now?\n\n"
            "1) Sort and output the list\n"
            "2) Try conversion functions \n"
            "3) Sum the list \n"
            "4) Quit \n\n");

    get_And_Verify_Int(&choice,1,3);

    switch (choice) {
        case 1:
            sortedList = radixSort(input);
            printList(sortedList);
            break;

        case 2:
            tryConvert(input);
            break;

        case 3:
            sum = sumIntegerList(input);
            printf("%s\n", sum);
            free(sum);
    }
    

    return EXIT_SUCCESS;
}
