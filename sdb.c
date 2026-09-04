#include <stdio.h>
#include "sdb.h"


bool SDB_IsFull(void) {
    return (UsedSize >= MAX_STUDENTS) ? true : false;
}

uint8 SDB_GetUsedSize() 
{
    return UsedSize;
}
bool SDB_AddEntry(void) {
    if (SDB_IsFull()) {
        printf("\nDatabase is full! Cannot add more students.\n");
        return false;
    }

    students newStudent;

    printf("\nEnter Student ID: ");
    scanf("%u", &newStudent.Student_ID);

    if (SDB_IsIdExist(newStudent.Student_ID)) {
        printf("Error: ID already exists!\n");
        return false;
    }

    printf("Enter Student Year: ");
    scanf("%u", &newStudent.Student_year);

    printf("Enter Course 1 ID: ");
    scanf("%u", &newStudent.Course1_ID);
    printf("Enter Course 1 Grade: ");
    scanf("%u", &newStudent.Course1_grade);

    printf("Enter Course 2 ID: ");
    scanf("%u", &newStudent.Course2_ID);
    printf("Enter Course 2 Grade: ");
    scanf("%u", &newStudent.Course2_grade);

    printf("Enter Course 3 ID: ");
    scanf("%u", &newStudent.Course3_ID);
    printf("Enter Course 3 Grade: ");
    scanf("%u", &newStudent.Course3_grade);

    data[UsedSize] = newStudent;
    UsedSize++;
    
    return true;
}

void SDB_DeletEntry(uint32 id) {
    uint8 i = 0;
    bool found = 0;

    for (; i < UsedSize; i++) {
        if (data[i].Student_ID == id) {
            found = 1;
            break;
        }
    }
    if (found) {
        
        for (uint8 in = i; in < UsedSize - 1; in++) {
            data[in] = data[in + 1];
        }
        UsedSize--;
        printf("Student with ID %u deleted successfully.\n", id);
    } 
    else {
        printf("Error: Student ID %u not found in database.\n", id);
    }

    
}
bool SDB_ReadEntry (uint32 id) {
    for (uint8 i = 0; i < UsedSize; i++) {
        if (data[i].Student_ID == id) {
            printf("\n--- Student Details ---\n");
            printf("ID: %u\n", data[i].Student_ID);
            printf("Year: %u\n", data[i].Student_year);
            printf("Course 1 ID: %u | Grade: %u\n", data[i].Course1_ID, data[i].Course1_grade);
            printf("Course 2 ID: %u | Grade: %u\n", data[i].Course2_ID, data[i].Course2_grade);
            printf("Course 3 ID: %u | Grade: %u\n", data[i].Course3_ID, data[i].Course3_grade);
            return true;
        }
    }
    printf("Error: Student ID %u not found.\n", id);
    return false;
}
void SDB_GetList(uint8 *count, uint32 *list) {
    if (count != NULL && list != NULL) {
        *count = UsedSize;
        for (uint8 i = 0; i < UsedSize; i++) {
            list[i] =data[i].Student_ID;
        }
    }
}
bool SDB_IsIdExist(uint32 id) {
    for (uint8 i = 0; i < UsedSize; i++) {
        if (data[i].Student_ID == id) {
            return true;
        }
    }
    return false;
}

