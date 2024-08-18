#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_all_records() {
    FILE *file = fopen("data.csv", "r");
    if (!file) {
        printf("File could not be opened\n");
        return;
    }

    char line[1024];
    while (fgets(line, sizeof(line), file)) {
		printf("%s",line);
    }

    fclose(file);
}

