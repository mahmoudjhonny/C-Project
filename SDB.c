#include <stdio.h>
#define MAX_STUDENTS 10
#include "STD.h"
#include "SDB.h"

int num_student = 0;
studentDB students[MAX_STUDENTS];

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
    // if not full will add student using its keys in array
    printf("%s", "Enter Student id : ");
    scanf("%u", &students[num_student].Student_ID);
    printf("%s", "Enter Student year : ");
    scanf("%u", &students[num_student].Student_year);
    printf("%s", "Enter Student's first course Id : ");
    scanf("%u", &students[num_student].Course1_ID);
    printf("%s", "Enter Student's first course Grade : ");
    scanf("%u", &students[num_student].Course1_grade);
    printf("%s", "Enter Student's second course Id : ");
    scanf("%u", &students[num_student].Course2_ID);
    printf("%s", "Enter Student's second course Grade : ");
    scanf("%u", &students[num_student].Course2_grade);
    printf("%s", "Enter Student's third course Id : ");
    scanf("%u", &students[num_student].Course3_ID);
    printf("%s", "Enter Student's third course Grade : ");
    scanf("%u", &students[num_student].Course3_grade);
    // here increment the number of students by one and return true
    num_student++;
    return true;
}

// This function using to check if id is exist in database or not
bool SDB_IsIdExist(uint32 id) {
    // looping on all database element when id i searched on it is equal with any of id's in database will return true else return false
    for(int i = 0; i < MAX_STUDENTS; i++) {
        if(students[i].Student_ID == id) {
            return true;
        }
    }
    return false;
}

// This function using to delete the student from database by its id
void SDB_DeletEntry(uint32 id) {
    int deleted_id = -1; // initialize the variable to carry the student index if found in database
    // looping on all students in database if found store the index on variable
    for(int i = 0; i < MAX_STUDENTS; i++){
        if(students[i].Student_ID == id) {
            deleted_id = i;
            break;
        }
    }
// here check if deleted_id is store the index of element means it exist in database if not found the deleted_id will be -1
if(deleted_id != -1) {
        /** looping from the index of student will deleted
        and replace the current student with the next student
        in this case will delete the target student **/
        for(int i = deleted_id; i < MAX_STUDENTS; i++){
            students[i] = students[i+1];
        }
        num_student--; // Reduce the number of student with one
        printf("Student with id : %d has deleted sucessfuly\n", deleted_id);
    } else {
        printf("%s", "This Student don't exist\n");
    }
}

// This function using to get the consuming size of database elements
uint8 SDB_GetUsedSize() {
    return num_student; // return the number of students
}

// This function using to read the student data using its id
bool SDB_ReadEntry(uint32 id) {
    // looping on all data and check if id is exist get student by its id and print all information
    for(int i = 0; i < MAX_STUDENTS; i++) {
        if(students[i].Student_ID == id) {
            printf("Student ID: %u\n", students[i].Student_ID);
            printf("Student Year: %u\n", students[i].Student_year);
            printf("Course 1 ID: %u, Grade: %u\n", students[i].Course1_ID, students[i].Course1_grade);
            printf("Course 2 ID: %u, Grade: %u\n", students[i].Course2_ID, students[i].Course2_grade);
            printf("Course 3 ID: %u, Grade: %u\n", students[i].Course3_ID, students[i].Course3_grade);
            return 1;
        }
    }
    printf("Student Id %u Don't Exist in DataBase\n", id);
    return false;
}

// This function return the list of id's based on count that point to number of students value
void SDB_GetList(uint8* count, uint32* list) {
    *count = num_student;
    if(num_student > 0) {
        printf("List of Student IDs:\n");
        for (int i = 0; i < *count; i++) {
            list[i] = students[i].Student_ID;
            printf("%u\n", list[i]);
        }
    }else {
        printf("The database has been empty .... \n");
    }
}
