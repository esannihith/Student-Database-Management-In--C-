#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add_record() {
    student info;
    printf("Enter details:\n");

    printf("Enter ID: ");
    if (scanf("%d", &info.id) != 1) {
        printf("Invalid input for ID.\n");

        while (getchar() != '\n');
        return;
    }
    getchar(); 

    printf("Enter name: ");
    if (fgets(info.name, NAME_MAX_LEN, stdin) != NULL) {
        info.name[strcspn(info.name, "\n")] = '\0'; 
    } else {
        printf("Error reading name.\n");
        return;
    }

    printf("Enter year: ");
    if (scanf("%d", &info.year) != 1) {
        printf("Invalid input for year.\n");

        while (getchar() != '\n');
        return;
    }
    getchar(); 

    printf("Enter branch: ");
    if (fgets(info.branch, BRANCH_MAX_LEN, stdin) != NULL) {
        info.branch[strcspn(info.branch, "\n")] = '\0'; 
    } else {
        printf("Error reading branch.\n");
        return;
    }

    printf("Enter CGPA: ");
    if (scanf("%f", &info.cgpa) != 1) {
        printf("Invalid input for CGPA.\n");
        while (getchar() != '\n');
        return;
    }

    if (search(info.id)) {
        printf("Record already exists\n");
        return;
    }

    FILE *file = fopen("data.csv", "a");
    if (!file) {
        printf("File could not be opened\n");
        return;
    }

    fprintf(file, "%d,%s,%d,%s,%.2f\n", info.id, info.name, info.year, info.branch, info.cgpa);
    printf("Record successfully added\n");

    fclose(file);
}

