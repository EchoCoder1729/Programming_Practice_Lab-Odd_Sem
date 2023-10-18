#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store student information
struct Student {
    int roll;
    char name[50];
    int scores[5];
};

// Function to add a student record to the file
void addRecord(FILE *file) {
    struct Student student;
    
    printf("Enter Roll: ");
    scanf("%d", &student.roll);

    // Check for duplicate roll numbers
    fseek(file, 0, SEEK_SET);
    while (fread(&student, sizeof(struct Student), 1, file)) {
        if (student.roll == student.roll) {
            printf("Roll number already exists. Choose a different roll number.\n");
            return;
        }
    }

    printf("Enter Name: ");
    scanf("%s", student.name);

    printf("Enter Scores in 5 subjects:\n");
    for (int i = 0; i < 5; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%d", &student.scores[i]);
    }

    fseek(file, 0, SEEK_END);
    fwrite(&student, sizeof(struct Student), 1, file);

    printf("Record added successfully.\n");
}

// Function to display all records
void displayRecords(FILE *file) {
    struct Student student;
    fseek(file, 0, SEEK_SET);
    printf("\nRoll\tName\tTotal Score\n");
    printf("---------------------------------\n");
    while (fread(&student, sizeof(struct Student), 1, file)) {
        int total = 0;
        for (int i = 0; i < 5; i++) {
            total += student.scores[i];
        }
        printf("%d\t%s\t%d\n", student.roll, student.name, total);
    }
}

// Function to search for a record by roll number
void searchRecord(FILE *file) {
    int roll;
    printf("Enter Roll to search: ");
    scanf("%d", &roll);

    struct Student student;
    fseek(file, 0, SEEK_SET);
    while (fread(&student, sizeof(struct Student), 1, file)) {
        if (student.roll == roll) {
            printf("\nRoll: %d\nName: %s\nScores: ", student.roll, student.name);
            for (int i = 0; i < 5; i++) {
                printf("%d ", student.scores[i]);
            }
            printf("\n");
            return;
        }
    }

    printf("Record not found.\n");
}

// Function to edit a record by roll number
void editRecord(FILE *file) {
    int roll;
    printf("Enter Roll to edit: ");
    scanf("%d", &roll);

    struct Student student;
    int found = 0;
    long pos = 0;

    fseek(file, 0, SEEK_SET);
    while (fread(&student, sizeof(struct Student), 1, file)) {
        if (student.roll == roll) {
            found = 1;
            break;
        }
        pos = ftell(file);
    }

    if (found) {
        printf("Enter new Name: ");
        scanf("%s", student.name);

        printf("Enter new Scores in 5 subjects:\n");
        for (int i = 0; i < 5; i++) {
            printf("Subject %d: ", i + 1);
            scanf("%d", &student.scores[i]);
        }

        fseek(file, pos, SEEK_SET);
        fwrite(&student, sizeof(struct Student), 1, file);

        printf("Record updated successfully.\n");
    } else {
        printf("Record not found.\n");
    }
}

// Function to mark a record as logically deleted
void deleteRecord(FILE *file) {
    int roll;
    printf("Enter Roll to delete: ");
    scanf("%d", &roll);

    struct Student student;
    int found = 0;
    long pos = 0;

    fseek(file, 0, SEEK_SET);
    while (fread(&student, sizeof(struct Student), 1, file)) {
        if (student.roll == roll) {
            found = 1;
            break;
        }
        pos = ftell(file);
    }

    if (found) {
        student.roll = -1;  // Mark as logically deleted
        fseek(file, pos, SEEK_SET);
        fwrite(&student, sizeof(struct Student), 1, file);

        printf("Record marked as deleted.\n");
    } else {
        printf("Record not found.\n");
    }
}

int main() {
    FILE *file;
    file = fopen("students.dat", "r+");
    if (file == NULL) {
        file = fopen("students.dat", "w+");
    }

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Search Record\n");
        printf("4. Edit Record\n");
        printf("5. Delete Record (Logical)\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord(file);
                break;
            case 2:
                displayRecords(file);
                break;
            case 3:
                searchRecord(file);
                break;
            case 4:
                editRecord(file);
                break;
            case 5:
                deleteRecord(file);
                break;
            case 6:
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 6);

    fclose(file);
    return 0;
}