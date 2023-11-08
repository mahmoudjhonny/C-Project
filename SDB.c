#include <stdio.h>
#define MAX_STUDENTS 10
#include "STD.h"
#include "SDB.h"

int num_student = 0;
studentDB* students[MAX_STUDENTS];

// This function to check if database is full or not
bool SDB_IsFull() {
    // here return true only when number of student in database is equal to the total size of database
    return num_student == MAX_STUDENTS;
}

// This function ue to add new student to database
bool SDB_AddEntry() {
    // First Check if database is full or not if true will return false and finish function implementation
    if(num_student == MAX_STUDENTS) {
        printf("The Student DataBase is Full Can't Add New Student");
        return false;
    }

    // Make a dynamic memory with the same size of student database to make a check if database is full or not
    studentDB* newStudent = (studentDB*)malloc(sizeof(studentDB));
    if (newStudent == NULL) {
        printf("Memory allocation failed. Unable to add a new student \n");
        return false;
    }
    // if not full will add student using its keys in array
    printf("%s", "Enter Student id : ");
    scanf("%u", &newStudent->Student_ID);
    printf("%s", "Enter Student year : ");
    scanf("%u", &newStudent->Student_year);
    printf("%s", "Enter Student's first course Id : ");
    scanf("%u", &newStudent->Course1_ID);
    printf("%s", "Enter Student's first course Grade : ");
    scanf("%u", &newStudent->Course1_grade);
    printf("%s", "Enter Student's second course Id : ");
    scanf("%u", &newStudent->Course2_ID);
    printf("%s", "Enter Student's second course Grade : ");
    scanf("%u", &newStudent->Course2_grade);
    printf("%s", "Enter Student's third course Id : ");
    scanf("%u", &newStudent->Course3_ID);
    printf("%s", "Enter Student's third course Grade : ");
    scanf("%u", &newStudent->Course3_grade);

    students[num_student] = newStudent; // add newStudent in an array of struct (student)
    // here increment the number of students by one and return true
    num_student++;
    return true;
}

// This function using to get the consuming size of database elements
uint8 SDB_GetUsedSize() {
    return num_student; // return the number of students
}

// Function to check if an ID exists in the database
bool SDB_IsIdExist(uint32 id) {
    for (int i = 0; i < num_student; i++) {
        if (students[i]->Student_ID == id) {
            return true;
        }
    }
    return false;
}

// Function to delete a student from the database by ID
void SDB_DeletEntry(uint32 id) {
    for (int i = 0; i < num_student; i++) {
        if (students[i]->Student_ID == id) {
            free(students[i]); // Free the memory of the deleted student
            num_student--; // decrement the number of student by one

            // Shift the remaining students to fill the gap
            for (int j = i; j < num_student; j++) {
                students[j] = students[j + 1];
            }

            printf("Student with ID %d has been deleted successfully\n", id);
            return;
        }
    }
    printf("Student with ID %d does not exist in the database\n", id);
}

// This function using to read the student data using its id
bool SDB_ReadEntry(uint32 id) {
    // looping on all data and check if id is exist get student by its id and print all information
    for(int i = 0; i < MAX_STUDENTS; i++) {
        if(students[i]->Student_ID == id) {
            printf("Student ID: %u\n", students[i]->Student_ID);
            printf("Student Year: %u\n", students[i]->Student_year);
            printf("Course 1 ID: %u, Grade: %u\n", students[i]->Course1_ID, students[i]->Course1_grade);
            printf("Course 2 ID: %u, Grade: %u\n", students[i]->Course2_ID, students[i]->Course2_grade);
            printf("Course 3 ID: %u, Grade: %u\n", students[i]->Course3_ID, students[i]->Course3_grade);
            return 1;
        }
    }
    printf("Student Id %u Don't Exist in DataBase\n", id);
    return false;
}

// This function return the list of id's based on count that point to number of students value
void SDB_GetList(uint8* count, uint32* list) {
    *count = num_student;
    printf("the Count of Student is %u\n", *count);
    if(num_student > 0) {
        printf("List of Student IDs:\n");
        for (int i = 0; i < *count; i++) {
            list[i] = students[i]->Student_ID;
            printf("%u\n", list[i]);
        }
    }else {
        printf("The database has been empty .... \n");
    }
}
