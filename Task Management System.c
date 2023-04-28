#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include "functions.c"

int main()
{
    int option; 
    while (option != 5) {
        currenttime();
        printf("Personal task management\n");
        printf("------------------------\n");
        printf("1) Add new task\n2) View all tasks\n3) Update tasks\n4) Delete tasks\n5) Exit Program\n");
        printf("Enter Option: ");
        scanf("%d", &option);

        if (option == 1)
            createTask();
        else if (option == 2)
            sortTask();
        else if (option == 3)
            updateTask();
        else if (option == 4)
            deleteTask();
        else if (option == 5) {
            printf("See you next time!");
            break; }
        else {
            printf("\n\nThis option is not currently available. Please choose the option that is available at the moment\n\n");
        }
    }
    return 0;
}
