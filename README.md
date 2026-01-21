# Student Grade Prediction System (C)

This is a menu-driven student grade management and prediction system written in C.  
The program allows users to manage student records, calculate final grades, rank students, and predict required marks for a desired final grade.

---

## Program Description

The program maintains student records using structures and arrays.  
Each student record includes name, roll number, marks obtained in exams, and the calculated final grade.

The system supports adding, updating, deleting, displaying, sorting, saving, and loading student data using a text file.

---

## Code Explanation

1. Header files stdio.h, stdlib.h, and string.h are included for input/output operations, memory handling, and string operations.

2. A Student structure is defined to store student name, roll number, marks, and final grade.

3. An array of Student structures is used to store records, with a maximum limit defined by MAX_STUDENTS.

4. calculate_final_grade()  
   Calculates the final grade using weighted marks.

5. add_student()  
   Adds a new student and computes the final grade.

6. display_students()  
   Displays all student records in a formatted table.

7. update_student()  
   Updates an existing student record using roll number.

8. delete_student()  
   Deletes a student record from the system.

9. save_to_file()  
   Saves student records to students.txt.

10. load_from_file()  
    Loads student records from students.txt at program startup.

11. sort_students()  
    Sorts students by final grade in descending order.

12. predict_marks()  
    Predicts required final exam marks to achieve a desired grade.

13. menu()  
    Displays the menu and controls program flow.

14. main()  
    Starts the program.

---

## How to Compile

Open terminal or command prompt in the folder containing the file and run:

```bash
gcc student_management.c -o student_management
