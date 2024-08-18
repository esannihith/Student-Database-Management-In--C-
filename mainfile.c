#include <stdio.h>
#include <stdlib.h>
# include <string.h>
#include "student.h"

int main() {
    int choice, id, year;
	float min_cgpa, max_cgpa;
    char branch[BRANCH_MAX_LEN];
    char filename[100];
    student *info;

    do {
        printf("\n\nSelect one of the following options:\n");
        printf("1. Add Record\n");
        printf("2. Modify Record\n");
        printf("3. Delete Record\n");
        printf("4. Search Record\n");
        printf("5. Display Record\n");
        printf("6. Display All Records\n");
        printf("7. Import Records from File\n");
        printf("8. Export Records to File\n");
        printf("9. Get Records by Branch\n");
        printf("10. Get Records by Year\n");
        printf("11. Get Records by Cgpa\n");
        printf("12. Restore backup\n");
        printf("13. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);
        printf("\n\n");
        getchar(); 

        switch (choice) {
            case 1:
                add_record();
                break;
            case 2:
                modify_record();
                break;
            case 3:
                delete_record();
                break;
            case 4:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                getchar(); 
                info = search(id);
                if (!info)
                    printf("Record doesn't exist.\n");
                else
                    printf("Record exists.\n");
                free(info);
                break;
            case 5:
                printf("Enter ID to display: ");
                scanf("%d", &id);
                getchar(); 
                info = search(id);
                if (info) {
                    get_record(info);
                    free(info);
                } else {
                    printf("Record not found.\n");
                }
                break;
            case 6:
                get_all_records();
                break;
            case 7:
                printf("Enter filename to import from: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = '\0'; 
                import_from_file(filename);
                break;
            case 8:
                printf("Enter filename to export to: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = '\0'; 
                export_to_file(filename);
                break;
            case 9:
                printf("Enter branch to filter by: ");
                fgets(branch, sizeof(branch), stdin);
                branch[strcspn(branch, "\n")] = '\0'; 
                get_by_branch(branch);
                break;
            case 10:
                printf("Enter year to filter by: ");
                scanf("%d", &year);
                getchar(); 
                get_by_year(year);
                break;
            case 11:
            	printf("Enter min_cpga,max_cgpa to filter by: ");
            	scanf("%f %f",&min_cgpa,&max_cgpa);
            	filter_by_cgpa(min_cgpa,max_cgpa);
            	getchar();
            	break;
            	
            case 12:
            	printf("Enter backup file name:");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = '\0'; 
                backup_from(filename);
                break;
            case 13:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (choice != 13);

    return 0;
}

