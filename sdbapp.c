
#include <stdio.h>
#include "sdb.h"

void SDB_action(uint8 choice);


void SDB_APP(void) {
    uint32 choice = 0;

    while (1) {
        printf("\n====================================\n");
        printf("       Student Database System      \n");
        printf("====================================\n");
        printf("1. To add entry, enter 1\n");
        printf("2. To get used size in database, enter 2\n");
        printf("3. To read student data, enter 3\n");
        printf("4. To get the list of all student IDs, enter 4\n");
        printf("5. To check if ID is existed, enter 5\n");
        printf("6. To delete student data, enter 6\n");
        printf("7. To check if database is full, enter 7\n");
        printf("8. To exit enter 0\n");
        printf("------------------------------------\n");
        printf("Enter choice: ");
        scanf("%u", &choice);

        if (choice == 0) {
            printf("\nExiting program... Goodbye!\n");
            break;
        }

        SDB_action((uint8)choice);
    }
}

void SDB_action(uint8 choice) {
    uint32 id = 0;
    uint8 count = 0;
    uint32 id_list[MAX_STUDENTS];

    switch (choice) {
        case 1:
            SDB_AddEntry();
            break;

        case 2:
            printf("\nNumber of students currently in DB: %u\n", SDB_GetUsedSize());
            break;

        case 3:
            printf("\nEnter Student ID to read: ");
            scanf("%u", &id);
            SDB_ReadEntry(id);
            break;

        case 4:
            SDB_GetList(&count, id_list);
            printf("\nTotal Students: %u\nIDs: ", count);
            for (uint8 i = 0; i < count; i++) {
                printf("%u ", id_list[i]);
            }
            printf("\n");
            break;

        case 5:
            printf("\nEnter Student ID to check: ");
            scanf("%u", &id);
            if (SDB_IsIdExist(id)) {
                printf("Result: ID %u EXISTS in database.\n", id);
            } else {
                printf("Result: ID %u DOES NOT exist.\n", id);
            }
            break;

        case 6:
            printf("\nEnter Student ID to delete: ");
            scanf("%u", &id);
            SDB_DeletEntry(id);
            break;

        case 7:
            if (SDB_IsFull()) {
                printf("\nDatabase status: FULL.\n");
            } else {
                printf("\nDatabase status: NOT FULL.\n");
            }
            break;

        default:
            printf("\nInvalid choice! Please select between 0 and 7.\n");
            break;
    }
}