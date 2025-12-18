#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STUDENTS 100
// Structure to hold student data
typedef struct {
    char name[50];
    int roll_no;
    float marks[3]; // Midterm, Assignments, Finals
    float final_grade;
} Student;
Student students[MAX_STUDENTS];
int student_count = 0;
// Function to calculate final grade
float calculate_final_grade(float mid, float assignment, float final_exam) {
    return (mid * 0.3) + (assignment * 0.2) + (final_exam * 0.5);
}
// Function to add a new student
void add_student() {
    if (student_count >= MAX_STUDENTS) {
        printf("Cannot add more students.\n");
        return;
    }
    printf("\nEnter Student Name: ");
    scanf(" %[^\n]", students[student_count].name);
    printf("Enter Roll Number: ");
    scanf("%d", &students[student_count].roll_no);
    printf("Enter Midterm Marks (out of 100): ");
    scanf("%f", &students[student_count].marks[0]);
    printf("Enter Assignment Marks (out of 100): ");
    scanf("%f", &students[student_count].marks[1]);
    printf("Enter Final Exam Marks (out of 100): ");
    scanf("%f", &students[student_count].marks[2]);
    // Calculate Final Grade
    students[student_count].final_grade = calculate_final_grade(
        students[student_count].marks[0],
        students[student_count].marks[1],
        students[student_count].marks[2]);
    student_count++;
    printf("Student added successfully!\n");
}
// Function to display student records
void display_students() {
	int i;
    if (student_count == 0) {
        printf("\nNo student records found.\n");
        return;
    }
    printf("\nStudent Records:\n");
    printf("----------------------------------------------------------\n");
    printf("Roll No. | Name | Final Grade\n");
    printf("----------------------------------------------------------\n");
    for (i = 0; i < student_count; i++) {
        printf("%-9d | %-20s | %.2f\n", students[i].roll_no, students[i].name, students[i].final_grade);
    }
    printf("----------------------------------------------------------\n");
}
// Function to update student details
void update_student() {
    int roll_no, found = 0,i,j;
    printf("\nEnter Roll Number to Update: ");
    scanf("%d", &roll_no);
    for (i = 0; i < student_count; i++) {
        if (students[i].roll_no == roll_no) {
            printf("Enter New Name: ");
            scanf(" %[^\n]", students[i].name);
            printf("Enter New Midterm Marks: ");
            scanf("%f", &students[i].marks[0]);
            printf("Enter New Assignment Marks: ");
            scanf("%f", &students[i].marks[1]);
            printf("Enter New Final Exam Marks: ");
            scanf("%f", &students[i].marks[2]);
            // Recalculate Final Grade
            students[i].final_grade = calculate_final_grade(
                students[i].marks[0],
                students[i].marks[1],
                students[i].marks[2]);
            printf("Student record updated successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Student with Roll Number %d not found!\n", roll_no);
    }
}
// Function to delete student record
void delete_student() {
	int roll_no, i, j, found = 0;
    printf("\nEnter Roll Number to Delete: ");
    scanf("%d", &roll_no);
    for (i = 0; i < student_count; i++) {
        if (students[i].roll_no == roll_no) {
            for (j = i; j < student_count - 1; j++) {
                students[j] = students[j + 1];
            }
            student_count--;
            printf("Student record deleted successfully!\n");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Student with Roll Number %d not found!\n", roll_no);
    }
}
// Function to save student records to file
void save_to_file() {
	int i;
    FILE *file = fopen("students.txt", "w");
    if (!file) {
        printf("Error saving file!\n");
        return;
    }
    for (i = 0; i < student_count; i++) {
        fprintf(file, "%d %s %.2f\n", students[i].roll_no, students[i].name, students[i].final_grade);
    }
    fclose(file);
    printf("Data saved successfully!\n");
}
// Function to load student records from file
void load_from_file() {
    FILE *file = fopen("students.txt", "r");
    if (!file) {
        printf("No previous records found.\n");
        return;
    }
    student_count = 0;
    while (fscanf(file, "%d %[^\n] %f", &students[student_count].roll_no, students[student_count].name, &students[student_count].final_grade) != EOF) {
        student_count++;
    }
    fclose(file);
    printf("Data loaded successfully!\n");
}
// Function to sort students by final grade (Descending Order)
void sort_students() {
	int i,j;
    for (i = 0; i < student_count - 1; i++) {
        for (j = 0; j < student_count - i - 1; j++) {
            if (students[j].final_grade < students[j + 1].final_grade) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    printf("Students ranked by highest grade!\n");
}
// Function to predict required marks for a desired grade
void predict_marks() {
    int roll_no,i;
    float desired_grade;
    printf("\nEnter Roll Number: ");
    scanf("%d", &roll_no);
    printf("Enter Desired Final Grade: ");
    scanf("%f", &desired_grade);
    for (i = 0; i < student_count; i++) {
        if (students[i].roll_no == roll_no) {
            float required_final = ((desired_grade - (students[i].marks[0] * 0.3) - (students[i].marks[1] * 0.2)) / 0.5);
            if (required_final > 100) {
                printf("Impossible to achieve %.2f, even with 100%% in final exams.\n", desired_grade);
            } else {
                printf("You need %.2f%% in the final exam to get a %.2f grade.\n", required_final, desired_grade);
            }
            return;
        }
    }
    printf("Student not found!\n");
}
// Main menu function
void menu() {
    int choice;
    load_from_file(); // Load data at startup
    while (1) {
        printf("\n===== Student Grade Prediction System =====\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Update Student Details\n");
        printf("4. Delete Student Record\n");
        printf("5. Rank Students by Grade\n");
        printf("6. Save & Exit\n");
        printf("7. Predict marks\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: add_student(); break;
            case 2: display_students(); break;
            case 3: update_student(); break;
            case 4: delete_student(); break;
            case 5: sort_students(); display_students(); break;
            case 6: save_to_file(); break;
            case 7: predict_marks(); exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
}
// Main function
int main() {
    menu();
    return 0;
}