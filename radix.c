#include <BaseNIntegerList.h>
#include <BaseNIntegerListOfList.h>
#include <string.h>


int main(int argc, char** argv)
{
    int base = 10;

    system("clear");
    printf("    |———————————————— Welcome In Our Radix Sort Programm ————————————————|\n\n\n\n");
    printf("Implemented by G.Duvauchelle and S.Prost      UTBM Students in L027\n\n\n\n");

    while(1)
    {
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
                "1) Sort and output the list directly\n"
                "2) Sort with detailed steps and output the list\n"
                "3) Try conversion functions \n"
                "4) Sum the list \n"
                "5) Quit \n\n");

        get_And_Verify_Int(&choice,1,5);

        switch (choice) {
            case 1:
                sortedList = radixSort(input, FALSE);
                printf("\n\nThe sorted list is :\n");
                printList(sortedList);
                break;

            case 2:
                sortedList = radixSort(input, TRUE);
                printf("\n\nThe sorted list is :\n");
                printList(sortedList);
                break;

            case 3:
                tryConvert(input);
                break;

            case 4:
                sum = sumIntegerList(input);
                printf("%s\n", sum);
                free(sum);
                break;
            case 5:
                return 0;
        }
    }

    return EXIT_SUCCESS;
}
