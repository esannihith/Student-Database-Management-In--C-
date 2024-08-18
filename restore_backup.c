#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void backup_from(const char *backup_filename) {

    FILE *data_file = fopen("data.csv", "w");
    if (!data_file) {
        perror("Error opening data.csv for writing");
        return;
    }

    FILE *backup_file = fopen(backup_filename, "r");
    if (!backup_file) {
        perror("Error opening backup file for reading");
        fclose(data_file); 
        return;
    }

    char line[1024];
    while (fgets(line, sizeof(line), backup_file)) {
        fprintf(data_file, "%s", line);
    }

    printf("Data restored from backup file successfully\n");
    
    fclose(data_file);
    fclose(backup_file);
}

