#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

#define MAX_RECORDS 1000


int compare_by_cgpa(const void *a, const void *b) {
    float diff = ((student *)a)->cgpa - ((student *)b)->cgpa;
    return -((diff > 0) - (diff < 0));
}

void filter_by_cgpa(float min_cgpa, float max_cgpa) {
    FILE *file = fopen("data.csv", "r");
    if (!file) {
        printf("Error opening file\n");
        return;
    }

    student records[MAX_RECORDS];
    int count = 0;
    char line[1024];
    char *token;

    while (fgets(line, sizeof(line), file) && count < MAX_RECORDS) {
        token = strtok(line, ",");
        records[count].id = atoi(token);

        token = strtok(NULL, ",");
        strncpy(records[count].name, token, NAME_MAX_LEN - 1);
        records[count].name[NAME_MAX_LEN - 1] = '\0';

        token = strtok(NULL, ",");
        records[count].year = atoi(token);

        token = strtok(NULL, ",");
        strncpy(records[count].branch, token, BRANCH_MAX_LEN - 1);
        records[count].branch[BRANCH_MAX_LEN - 1] = '\0';

        token = strtok(NULL, ",");
        records[count].cgpa = atof(token);

        if (records[count].cgpa >= min_cgpa && records[count].cgpa <= max_cgpa) {
            count++;
        }
    }
    fclose(file);

	int i;
    qsort(records, count, sizeof(student), compare_by_cgpa);

    if (count > 0) {
        printf("Records with CGPA between %.2f and %.2f sorted by CGPA:\n", min_cgpa, max_cgpa);
        for ( i = 0; i < count; i++) {
            printf("ID: %d, Name: %s, Year: %d, Branch: %s, CGPA: %.2f\n",
                   records[i].id,
                   records[i].name,
                   records[i].year,
                   records[i].branch,
                   records[i].cgpa);
        }
    } else {
        printf("No records found with CGPA between %.2f and %.2f\n", min_cgpa, max_cgpa);
    }
}

