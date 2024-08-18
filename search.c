#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

student *search(int target_id) {
    FILE *file = fopen("data.csv", "r");
    if (!file) {
        printf("File could not be opened\n");
        return NULL;
    }

    char line[1024];
    char *token;

    while (fgets(line, sizeof(line), file)) {
        student *info = (student *)malloc(sizeof(student));
        if (info == NULL) {
            printf("Memory allocation failed\n");
            fclose(file);
            return NULL;
        }

        token = strtok(line, ",");
        if (token == NULL) {
            free(info);
            continue;
        }

        info->id = atoi(token);
        if (info->id != target_id) {
            free(info);
            continue;
        }

        token = strtok(NULL, ",");
        if (token != NULL) {
            strncpy(info->name, token, NAME_MAX_LEN - 1);
            info->name[NAME_MAX_LEN - 1] = '\0';
        }

        token = strtok(NULL, ",");
        if (token != NULL) {
            info->year = atoi(token);
        }

        token = strtok(NULL, ",");
        if (token != NULL) {
            strncpy(info->branch, token, BRANCH_MAX_LEN - 1);
            info->branch[BRANCH_MAX_LEN - 1] = '\0';
        }

        token = strtok(NULL, ",");
        if (token != NULL) {
            info->cgpa = atof(token);
        }

        fclose(file);
        return info; 
    }

    fclose(file);
    return NULL; 
}

