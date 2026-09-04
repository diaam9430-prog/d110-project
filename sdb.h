#ifndef sdb_h_
#define sdb_h_
#include "std.h"

typedef struct students
{ 
uint32 Student_ID; 
uint32 Student_year; 
uint32 Course1_ID; 
uint32 Course1_grade; 
uint32 Course2_ID; 
uint32 Course2_grade; 
uint32 Course3_ID; 
uint32 Course3_grade; 
} students; 
#define MAX_STUDENTS 10
#define MIN_STUDENTS 3
static students data[MAX_STUDENTS] = {
    {1001, 2026, 101, 85, 201, 90, 50, 78},
    {1002, 2026, 102, 75, 202, 85, 55, 100},
    {1003, 2026, 103, 95, 203, 80, 60, 85}
};
static uint8 UsedSize = MIN_STUDENTS;
bool SDB_IsFull(void);
uint8 SDB_GetUsedSize(void);
bool SDB_AddEntry(void);
void SDB_DeletEntry(uint32 id);
bool SDB_ReadEntry(uint32 id);
void SDB_GetList(uint8 *count, uint32 *list);
bool SDB_IsIdExist(uint32 id);


#endif