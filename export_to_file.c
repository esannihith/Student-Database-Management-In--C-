#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void export_to_file(const char *newfile) {
    FILE *file = fopen("data.csv", "r");
    FILE *new_file = fopen(newfile, "w");
    if (!file || !new_file) {
        printf("Error opening file(s)\n");
        if (file) fclose(file);
        if (new_file) fclose(new_file);
        return;
    }

    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        if (fputs(line, new_file) == EOF) {
            printf("Error writing to file %s\n", newfile);
            fclose(file);
            fclose(new_file);
            return;
        }
    }

    if (ferror(file)) {
        printf("Error reading from data.csv\n");
    } else {
        printf("Data added to new file successfully\n");
    }

    fclose(file);
    fclose(new_file);
}

