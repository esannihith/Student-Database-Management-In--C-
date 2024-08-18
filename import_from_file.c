#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void import_from_file(const char *newfile) {
    FILE *file = fopen("data.csv", "a");

    if (!file) {
        perror("Error opening data.csv for appending");
        return;
    }


    FILE *data_file = fopen(newfile, "r");
    if (!data_file) {
        perror("Error opening new file for reading");
        fclose(file); 
    }

    char line[1024];
    while (fgets(line, sizeof(line), data_file)) {
        fprintf(file, "%s", line);
    }

    printf("Data imported to file successfully\n");

    fclose(file);
    fclose(data_file);
}

