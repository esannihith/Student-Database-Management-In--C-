#ifndef STUDENT_H
#define STUDENT_H

#define NAME_MAX_LEN 50
#define BRANCH_MAX_LEN 10

typedef struct student {
    int id;
    char name[NAME_MAX_LEN];
    int year;
    char branch[BRANCH_MAX_LEN];
    float cgpa;
} student;

typedef enum {
    SORT_BY_ID,
    SORT_BY_NAME,
    SORT_BY_YEAR,
    SORT_BY_BRANCH,
    SORT_BY_CGPA
} SortCriteria;

// Function prototypes
void add_record();   
void get_record(student *info);
void get_all_records();
void modify_record();
void delete_record();  

student *search(int id); 

void backup_from(const char *filename);
void import_from_file(const char *filename);
void export_to_file(const char *filename);
void get_by_branch(const char *branch_filter);
void get_by_year(int target_year);
void filter_by_cgpa(float min_cgpa, float max_cgpa);

#endif // STUDENT_H

