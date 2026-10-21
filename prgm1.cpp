#include <stdio.h>
#include <stdlib.h>

struct Student {
    int roll_no;
    char name[20];
    float marks;
};

int main() {
    struct Student *ptr, *temp;
    int n, i, choice;
    float sum = 0, avg;
    struct Student *top;

    printf("Enter number of students: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of students\n");
        return 1;
    }

    ptr = (struct Student *)malloc(n * sizeof(struct Student));

    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("\nEnter roll number, name and marks:\n");
        scanf("%d %19s %f",
              &(ptr + i)->roll_no,
              (ptr + i)->name,
              &(ptr + i)->marks);
    }

    printf("\nDo you want to add 2 more students? (1=Yes, 0=No): ");
    scanf("%d", &choice);

    if (choice == 1) {
        temp = (struct Student *)realloc(ptr, (n + 2) * sizeof(struct Student));

        if (temp == NULL) {
            printf("Memory reallocation failed\n");
            free(ptr);
            return 1;
        }

        ptr = temp;

        for (i = n; i < n + 2; i++) {
            printf("\nEnter roll number, name and marks:\n");
            scanf("%d %19s %f",
                  &(ptr + i)->roll_no,
                  (ptr + i)->name,
                  &(ptr + i)->marks);
        }

        n = n + 2;
    }

    top = ptr;

    for (i = 0; i < n; i++) {
        sum += (ptr + i)->marks;

        if ((ptr + i)->marks > top->marks) {
            top = ptr + i;
        }
    }

    avg = sum / n;

    printf("\nAverage marks = %.2f\n", avg);

    printf("\nStudent with highest marks:\n");
    printf("Roll No: %d\n", top->roll_no);
    printf("Name: %s\n", top->name);
    printf("Marks: %.2f\n", top->marks);

    free(ptr);

    return 0;
}
