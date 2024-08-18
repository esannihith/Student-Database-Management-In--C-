#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void modify_record() {
    int target_id;
    printf("Enter ID of the record to modify: ");
    scanf("%d", &target_id);
    getchar();

    FILE *file = fopen("data.csv", "r");
    FILE *newfile = fopen("newdata.csv", "w");
    if (!file || !newfile) {
        printf("Error opening files\n");
        if (file) fclose(file);
        if (newfile) fclose(newfile);
        return;
    }

    student info;
    char line[1024];
    char *token;

    while (fgets(line, sizeof(line), file)) {
        token = strtok(line, ",");
        if (token == NULL) continue;

        info.id = atoi(token);
        token = strtok(NULL, ",");
        strncpy(info.name, token, NAME_MAX_LEN - 1);
        info.name[NAME_MAX_LEN - 1] = '\0';

        token = strtok(NULL, ",");
        info.year = atoi(token);

        token = strtok(NULL, ",");
        strncpy(info.branch, token, BRANCH_MAX_LEN - 1);
        info.branch[BRANCH_MAX_LEN - 1] = '\0';

        token = strtok(NULL, ",");
        info.cgpa = atof(token);

        if (info.id != target_id) {
            fprintf(newfile, "%d,%s,%d,%s,%.2f\n", info.id, info.name, info.year, info.branch, info.cgpa);
            continue;
        }

        printf("Record found. Enter the new values for the fields you want to modify.\n");

        char input[100];

        printf("Enter new name (current: %s, press Enter to keep unchanged): ", info.name);
        fgets(input, sizeof(input), stdin);
        if (input[0] != '\n') {
            input[strcspn(input, "\n")] = '\0';
            strncpy(info.name, input, NAME_MAX_LEN - 1);
            info.name[NAME_MAX_LEN - 1] = '\0';
        }

        printf("Enter new year (current: %d, press Enter to keep unchanged): ", info.year);
        fgets(input, sizeof(input), stdin);
        if (input[0] != '\n') {
            info.year = atoi(input);
        }

        printf("Enter new branch (current: %s, press Enter to keep unchanged): ", info.branch);
        fgets(input, sizeof(input), stdin);
        if (input[0] != '\n') {
            input[strcspn(input, "\n")] = '\0';
            strncpy(info.branch, input, BRANCH_MAX_LEN - 1);
            info.branch[BRANCH_MAX_LEN - 1] = '\0';
        }

        printf("Enter new CGPA (current: %.2f, press Enter to keep unchanged): ", info.cgpa);
        fgets(input, sizeof(input), stdin);
        if (input[0] != '\n') {
            info.cgpa = atof(input);
        }

        fprintf(newfile, "%d,%s,%d,%s,%.2f\n", info.id, info.name, info.year, info.branch, info.cgpa);
    }

    fclose(file);
    fclose(newfile);

    if (remove("data.csv") != 0) {
        printf("Error deleting original file\n");
        return;
    }
    if (rename("newdata.csv", "data.csv") != 0) {
        printf("Error renaming new file\n");
        return;
    }

    printf("Record successfully modified\n");
}

