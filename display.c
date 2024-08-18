#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_record(student *info) {
    if (!info) {
        printf("Record doesn't exist\n");
        return;
    }
    
    printf("ID: %d\n", info->id);
    printf("Name: %s\n", info->name);
    printf("Year: %d\n", info->year);
    printf("Branch: %s\n", info->branch);
    printf("CGPA: %.2f\n", info->cgpa);

    return;
}

