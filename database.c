#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STUDENTS 100

struct student {
    char name[50];
    int age;
    char gender[10];
    int id_number;
    float grade_math;
    float grade_science;
    float grade_english;
};



struct student *records;
int *num_records=0;



int check_student_detail(struct student detail){
    if (strlen(detail.name) > 50){
        return 0;
    }
    if (strcmp(detail.gender, "male") != 0 && strcmp(detail.gender, "female") != 0){
        return 0;
    }
    return 1;
}

void add_student() {
    struct student new_student;
    printf("Enter the student's name: ");
    scanf("%s", new_student.name);
    printf("Enter the student's age: ");
    scanf("%d", &new_student.age);
    printf("Enter the student's gender: male or female ");
    scanf("%s", new_student.gender);
    printf("Enter the student's ID number: ");
    scanf("%d", &new_student.id_number);
    printf("Enter the student's math grade: ");
    scanf("%f", &new_student.grade_math);
    printf("Enter the student's science grade: ");
    scanf("%f", &new_student.grade_science);
    printf("Enter the student's English grade: ");
    scanf("%f", &new_student.grade_english);
  
    if (check_student_detail(new_student) == 1){
        records[*num_records] = new_student;
    }else{
        printf("invalid detail of student ");
    }
    (*num_records)++;
}

void search_student(int id_number) {
    int i;
    for (i = 0; i < *num_records; i++) {
        if (records[i].id_number == id_number) {
            printf("Name: %s\n", records[i].name);
            printf("Age: %d\n", records[i].age);
            printf("Gender: %s\n", records[i].gender);
            printf("ID Number: %d\n", records[i].id_number);
            printf("Math Grade: %.2f\n", records[i].grade_math);
            printf("Science Grade: %.2f\n", records[i].grade_science);
            printf("English Grade: %.2f\n", records[i].grade_english);
            return; 
        }
    }
    printf("No student with ID number %d found\n", id_number);
}

void delete_student(int id_number) {
    int i;
    for (i = 0; i < *num_records; i++) {
        if (records[i].id_number == id_number) {
            int j;
            for (j = i; j < *num_records - 1; j++) {
                records[j] = records[j + 1];
            }
            (*num_records)--;
            printf("Student with ID number %d deleted\n", id_number);
            return; 
        }
    }
    printf("No student with ID number %d found\n", id_number);
}

void display_all_students() {
    int i;
    for (i = 0; i < *num_records; i++) {
        printf("Name: %s\n", records[i].name);
        printf("Age: %d\n", records[i].age);
        printf("Gender: %s\n", records[i].gender);
        printf("ID Number: %d\n", records[i].id_number);
        printf("Math Grade: %.2f\n", records[i].grade_math);
        printf("Science Grade: %.2f\n", records[i].grade_science);
        printf("English Grade: %.2f\n", records[i].grade_english);
        printf("\n"); 
    }
}


int main() {
    records = malloc(MAX_STUDENTS * sizeof(struct student));
    num_records = malloc(sizeof(int));
    int id_number;
    int choice = 0;

    printf("Welcome to the student record database!\n");

    while (choice != 5) {
        printf("Please choose an option:\n");
        printf("1. Add a student\n");
        printf("2. Search for a student\n");
        printf("3. Delete a student\n");
        printf("4. Display all students\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                printf("Enter the student's ID number: ");
                scanf("%d", &id_number);
                search_student(id_number);
                break;
            case 3:
                printf("Enter the student's ID number: ");
                scanf("%d", &id_number);
                delete_student(id_number);
                break;
            case 4:
                display_all_students();
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }
    free(records);

    return 0;
}






