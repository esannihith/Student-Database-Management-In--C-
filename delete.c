#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void delete_record() {
    int target_id;
    printf("Enter ID of the record to delete: ");
    scanf("%d", &target_id);
    getchar(); 

    FILE *file = fopen("data.csv", "r");
    if (!file) {
        perror("Error opening data.csv for reading");
        return;
    }

    FILE *newfile = fopen("newdata.csv", "w");
    if (!newfile) {
        perror("Error opening newdata.csv for writing");
        fclose(file);
        return;
    }

    char line[1024];
    int record_deleted = 0;


    while (fgets(line, sizeof(line), file)) {

        int current_id;
        sscanf(line, "%d,", &current_id);

        if (current_id != target_id) {

            fprintf(newfile, "%s", line);
        } else {
            record_deleted = 1;
            printf("Record with ID %d deleted successfully\n", target_id);
        }
    }

    if (!record_deleted) {
        printf("Record with ID %d does not exist\n", target_id);
    }

    fclose(file);
    fclose(newfile);


    if (remove("data.csv") != 0) {
        perror("Error deleting original file");
    } else if (rename("newdata.csv", "data.csv") != 0) {
        perror("Error renaming new file");
    } else {
        printf("File updated successfully\n");
    }
}

