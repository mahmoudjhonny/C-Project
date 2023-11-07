#include <stdio.h>
#define MAX_STUDENTS 10
#include "SDB.h"
extern int num_student;

// This function using the switch...case to determine which function will execute based on choice number
void SDB_action(uint8 choice) {
    switch (choice) {
        case 1:
            {
                SDB_AddEntry();
                break;
            }

        case 2:
            {
                int used_size = SDB_GetUsedSize();
                printf("The Used Size is : %d\n", used_size);
                break;
            }
        case 3:
            {
                int id = -1;
                printf("Enter the id of the student you want to read: ");
                scanf("%d", &id);
                SDB_ReadEntry(id);
                break;
            }

        case 4:
            {
                studentDB list[MAX_STUDENTS];
                uint8 count = 0;
                SDB_GetList(&count, list);
                break;
            }

        case 5:
            {
                int id = -1;
                printf("Enter the id of the student you want to check: ");
                scanf("%d", &id);
                if(SDB_IsIdExist(id)) {
                    printf("This Student is exist in DataBase\n");
                } else {
                    printf("This Student isn't exist in DataBase\n");
                }
                break;
            }
        case 6:
            {
                int id = -1;
                printf("Enter the id of the student you want to delete: ");
                scanf("%d", &id);
                SDB_DeletEntry(id);
                break;
            }

        case 7:
            {
                if(SDB_IsFull()) {
                    printf("The DataBase Is Full\n");
                } else {
                    printf("The DataBase Isn't Full \n");
                }
                break;
            }
        default:
            printf("Try Again ..... \n");
    }
}

// This Function contains the rules to users to learn how use the program and contain super loop which make the program based on choice variable
void SDB_APP() {
    printf("\t\t\tWelcome In the Student Database Program Developed By C Lang\t\t\t\n\n");
    printf("To add an entry for a new student, enter 1\n");
    printf("To get the used size of the database, enter 2\n");
    printf("To read student data, enter 3\n");
    printf("To get the list of all student IDs, enter 4\n");
    printf("To check if a specific ID exists in the database, enter 5\n");
    printf("To delete student data, enter 6\n");
    printf("To check if the database is full, enter 7\n");
    printf("To exit, enter 0\n");
    int choice;
    while (1) {
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        if(choice == 0) {
            return 0;
        }
        SDB_action(choice);
    }
}
