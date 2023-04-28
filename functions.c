#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>

struct task {
    char taskName[200];
    int dueDate;
    int dueMonth;
    int dueYear;
    char taskCategory[20];
    char taskStatus [15];
};

void currenttime() {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char s[64];
    assert(strftime(s, sizeof(s), "%c", tm));
    printf("------------------------\n");
    printf("Time:\n %s\n", s);
    printf("------------------------\n");
}

void sortTask()
{
    struct task task;
    char sort[100][5][50];
    char temp [5][50];
    int a = 0;
    int b = 0;
    int c = b + 1;
    int d = 0;
    int e = 0;
    int f = 0;
    int g = 0;
    int h = 0;
    FILE * fp;
    fp = fopen("task.txt", "r");
    while(fscanf(fp,"%[^|]|%d/%d/%d|%[^|]|%[^\n]\n", task.taskName, &task.dueDate, &task.dueMonth, &task.dueYear, task.taskCategory, task.taskStatus) != EOF)
    {
        strcpy(sort[a][0], task.taskName);
        strcpy(sort[a][1], task.taskCategory);
        strcpy(sort[a][2], task.taskStatus);
        sprintf(sort[a][3], "%d/%d/%d",task.dueDate, task.dueMonth, task.dueYear);
        a++;
    }
    while (b < a)
    {
        
        while (c < a)
        {
         
            if(strcmp(sort[b][3], sort[c][3]) > 0);
            {
                while (f < 5)
                {
                    strcpy(temp[f], sort[b][f]);
                    f++;
                }
                while (g < 5)
                {
                    strcpy(sort[b][g], sort[c][g]);
                    g++;
                }
                while (h < 5)
                {
                    strcpy(sort[c][h], temp[h]);
                    h++;
                }
            }
            c++;
        }
        b++;
    }

    printf("\t\t\t\t---TASKS---\n");
    printf("-----------------------------------------------------------------------\n");
    while (d < a)
    {
        printf("Task Name: %s\n", sort[d][0]);
        printf("Category: %s\n", sort[d][1]);
        printf("Status: %s\n", sort[d][2]);
        sscanf(sort[d][3],"%d/%d/%d", &task.dueDate, &task.dueMonth, &task.dueYear);
        printf("Due: %d/%d/%d\n\n", task.dueDate, task.dueMonth, task.dueYear);
        d++;
    }
    fclose(fp);
}   

void deleteTask(){
    struct task task;
    struct task delete;
    int choice;
    int found = 0;
    FILE *fp, *pf;
    fp = fopen("task.txt", "r");
    pf = fopen("temp.txt", "w");

    printf("Enter task name: ");
    fflush(stdin);
    gets(delete.taskName);

    while(fscanf(fp,"%[^|]|%d/%d/%d|%[^|]|%[^\n]\n", task.taskName, &task.dueDate, &task.dueMonth, &task.dueYear, task.taskCategory, task.taskStatus) != EOF)
    {
        if(strcmp(delete.taskName, task.taskName) == 0)
        {   found = 1;
            printf("\n---TASK DELETED---\n");
            continue;
            
        }
        else
            fprintf(pf, "%s|%d/%d/%d|%s|%s\n", task.taskName, task.dueDate, task.dueMonth, task.dueYear, task.taskCategory, task.taskStatus);
    }
    fclose(fp);
    fclose(pf);
    remove("task.txt");
    rename("temp.txt","task.txt");

    if(found == 0)
    {
        printf("\nTask not found\n");
    }

}

void updateTask(){
    struct task task;
    struct task update;
    int category;
    int choice;
    int found = 0;
    FILE *fp, *pf;
    fp = fopen("task.txt", "r");
    pf = fopen("temp.txt", "w");

    printf("Enter task name: ");
    fflush(stdin);
    gets(update.taskName);

    while(fscanf(fp,"%[^|]|%d/%d/%d|%[^|]|%[^\n]\n", task.taskName, &task.dueDate, &task.dueMonth, &task.dueYear, task.taskCategory, task.taskStatus) != EOF)
    {
        if(strcmp(update.taskName, task.taskName) == 0)
        {found = 1;
            while(choice != 7)
            {
                printf("Select which record to be updated: ");
                printf("\n1.Task Name:\n2.Due date:\n3.Due month\n4.Due year\n5.Category\n6.Status\n7.Quit\n");
                printf("Enter choice: ");
                scanf("%d", &choice);

                if (choice == 1)
                {
                    printf("Enter new task name: ");
                    fflush(stdin);
                    gets(task.taskName);
                    printf("\n---TASK NAME UPDATED---\n");
                }
                else if (choice == 2)
                {
                    printf("Enter new due date: ");
                    fflush(stdin);
                    scanf("%d", &task.dueDate);
                    printf("\n---TASK  DUE DATE UPDATED---\n");
                }
                else if(choice == 3)
                {
                    printf("Enter new due month: ");
                    fflush(stdin);
                    scanf("%d", &task.dueMonth);
                    printf("\n---TASK DUE MONTH UPDATED---\n");
                }
                else if(choice == 4)
                {
                    printf("Enter new due year: ");
                    fflush(stdin);
                    scanf("%d", &task.dueYear);
                    printf("\n---TASK DUE YEAR UPDATED---\n");
                }
                else if(choice == 5 )
                {
                    while (category != 0 || category <= 3)
                    {
                        printf("1.Easy\n2.Normal\n3.Hard\n");
                        printf("Choose a category:");
                        scanf("%d", &category);
                        if (category == 1)
                        {
                            strcpy(task.taskCategory, "Easy");
                            break;
                        }
                        else if (category == 2)
                        {
                            strcpy(task.taskCategory, "Normal");
                            break;
                        }
                        else if (category == 3)
                        {
                            strcpy(task.taskCategory, "Hard");
                            break;
                        }
                        else if (category == 0 || category > 3)
                        {
                            printf("\nCategory Not Available\n");
                        }
                    }
                    printf("\n---TASK CATEGORY UPDATED---\n");
                }
                else if(choice == 6)
                {
                    strcpy(task.taskStatus, "DONE");
                    printf("\n---TASK STATUS UPDATED---\n");
                }
                else if(choice == 7)    
                    fprintf(pf, "%s|%d/%d/%d|%s|%s\n", task.taskName, task.dueDate, task.dueMonth, task.dueYear, task.taskCategory, task.taskStatus);

                else
                {
                    printf("\n\n---OPTION IS NOT AVAILABLE---\n");
                }
            }

        }
        else
        {
            fprintf(pf, "%s|%d/%d/%d|%s|%s\n", task.taskName, task.dueDate, task.dueMonth, task.dueYear, task.taskCategory, task.taskStatus);
        } 
    }
    fclose(fp);
    fclose(pf);
    remove("task.txt");
    rename("temp.txt","task.txt");

    if(found == 0)
    {
        printf("\nTask not found\n");
    }

}

void createTask()
{
struct task task[20];
    FILE *fp;
    
    int category;
    int count;
    int i = 0;

    printf("How many task to be added: ");
    scanf("%d", &count);

    while(i<count){
        fp = fopen("task.txt", "a+");

        printf("Name of task: ");
        fflush(stdin);
        gets(task[i].taskName);

        printf("Enter due date [DD]: ");
        fflush(stdin);
        scanf("%d", &task[i].dueDate);

        printf("Enter due month [MM]: ");
        fflush(stdin);
        scanf("%d", &task[i].dueMonth);

        printf("Enter due year [YYYY]: ");
        fflush(stdin);
        scanf("%d", &task[i].dueYear);

        while (category != 0 || category <= 3)
        {
            printf("1.Easy\n2.Normal\n3.Hard\n");
            printf("Choose a category:");
            scanf("%d", &category);
            if (category == 1)
            {
                strcpy(task[i].taskCategory, "Easy");
                break;
            }
            else if (category == 2)
            {
                strcpy(task[i].taskCategory, "Normal");
                break;
            }
            else if (category == 3)
            {
                strcpy(task[i].taskCategory, "Hard");
                break;
            }
            else if (category == 0 || category > 3)
            {
                printf("\nCategory Not Available\n");
            }

        }


        strcpy(task[i].taskStatus, "NOT DONE");
        fprintf(fp,"%s|%d/%d/%d|%s|%s\n", task[i].taskName, task[i].dueDate, task[i].dueMonth, task[i].dueYear, task[i].taskCategory, task[i].taskStatus);
        i++;
        fclose(fp);
    }
    printf("\n---TASK(S) CREATED---\n");
}