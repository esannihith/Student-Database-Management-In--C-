#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000

int compare_by_branch_year_cgpa(const void *a, const void *b) {
    const student *student_a = (const student *)a;
    const student *student_b = (const student *)b;

    int branch_cmp = strcmp(student_a->branch, student_b->branch);
    if (branch_cmp != 0) {
        return branch_cmp;
    }

    if (student_a->year != student_b->year) {
        return -(student_a->year - student_b->year);
    }

    if (student_a->cgpa != student_b->cgpa) {
        return -((student_a->cgpa > student_b->cgpa) - (student_a->cgpa < student_b->cgpa));
    }

    return 0;
}


void get_by_branch(const char *branch_filter) {
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

        if (strcmp(records[count].branch, branch_filter) == 0) {
            count++;
        }
    }
    fclose(file);
    qsort(records, count, sizeof(student), compare_by_branch_year_cgpa);
	
	int i;
    if (count > 0) {
        printf("Records for branch '%s' :\n", branch_filter);
        for (i = 0; i < count; i++) {
            printf("ID: %d, Name: %s, Year: %d, Branch: %s, CGPA: %.2f\n",
                   records[i].id,
                   records[i].name,
                   records[i].year,
                   records[i].branch,
                   records[i].cgpa);
        }
    } else {
        printf("No records found for branch '%s'\n", branch_filter);
    }
}

