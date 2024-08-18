# Student Marks Management System

## Overview
The Student Marks Management System is a C-based application designed to manage and store student academic records. The system allows users to add, modify, delete, search, and display student records. It also provides features to filter records by specific criteria such as branch, year, and CGPA, and to export/import records to/from a file.

## Table of Contents
* [Features](/#Features)
* [File Structure](/#File-Structure)
* [How to Use](/#How-to-Use)
* [Requirements](/#Requirements)
* [Clone this repository](/#Clone-this-repository)
* [Note](/#Note)
* [License](/#License)

## Features
- **Add Record**: Add a new student record to the system.
- **Modify Record**: Modify existing student records.
- **Delete Record**: Delete a student record from the system.
- **Search Record**: Search for a student record by ID.
- **Display Record**: Display a specific student record by ID.
- **Display All Records**: Display all student records.
- **Import Records**: Import student records from a CSV file.
- **Export Records**: Export student records to a CSV file.
- **Filter by Branch**: Retrieve student records based on their branch.
- **Filter by Year**: Retrieve student records based on the year of study.
- **Filter by CGPA**: Retrieve student records based on a CGPA range.

## File Structure

The Student Marks Management System consists of the following key files:

### Header File
- **[`student.h`](/student.h)**: 
  - Contains the structure definitions for student records.
  - Includes function prototypes used across different source files.

### Source Files
- **[`add.c`](/add.c)**:
  - Implements the functionality to add a new student record.
- **[`delete.c`](/delete.c)**:
  - Contains the logic to delete a student record based on the student's ID.
- **[`display.c`](display.c)**:
  - Implements the functionality to display a specific student record by ID.
- **[`displayall.c`](/displayall.c)**:
  - Provides the functionality to display all student records stored in the system.
- **[`export_to_file.c`](/export_to_file.c)**:
  - Implements the functionality to export student records to a CSV file.
- **[`filter_by_cgpa.c`](/filter_by_cgpa.c)**:
  - Contains the logic to filter and display student records within a specified CGPA range.
- **[`filter_by_year.c`](/filter_by_year.c)**:
  - Implements the functionality to filter and display records of students from a specific year.
- **[`get_by_branch.c`](/get_by_branch.c)**:
  - Provides functionality to filter and display student records based on the branch.

### Project Configuration File
- **[`Student_marks_management.dev`](/Student_marks_management.dev)**:
  - The Dev-C++ project file, containing settings and configuration for the project.

### Data Files
- **[`data.csv`](/data.csv)**:
  - Stores the student records in a CSV format, used for importing/exporting data.

## How to Use
- **Compile the Project**: Use a C compiler to compile the project. Ensure all the source files and the header file are included.
- **Run the Executable**: Execute the compiled binary to start the program.
- **Select an Option**: Use the menu-driven interface to interact with the system, selecting options by entering the corresponding number.

## Requirements
- C Compiler (GCC, Dev-C++, etc.)
- A basic understanding of C programming and file handling.

## Clone this repository
- Open your terminal or command prompt and run the following command:
    - ```bash
      git clone https://github.com/esannihith/Student-Database-Management-In--C-

## Note
- The default file for data storing is **"data.csv"**.
- Make sure all files are in the same directory.

## License
This project is licensed under the MIT License.
