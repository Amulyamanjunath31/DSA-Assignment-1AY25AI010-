/* Input format: Enter rows, columns, and all matrix elements. */

#include <stdio.h>

#define MAX 100

typedef struct {
    int row, col, value;
} term;

void display(term a[]) {
    int i;

    printf("Row\tCol\tValue\n");

    for (i = 0; i <= a[0].value; i++) {
        printf("%d\t%d\t%d\n",
               a[i].row, a[i].col, a[i].value);
    }
}

void fast_transpose(term a[], term b[]) {
    int row_terms[MAX];
    int starting_pos[MAX];
    int i, j, num_cols;

    num_cols = a[0].col;

    /* Initialize row_terms array */
    for (i = 0; i < num_cols; i++)
        row_terms[i] = 0;

    /* Count the number of terms in each column */
    for (i = 1; i <= a[0].value; i++)
        row_terms[a[i].col]++;

    /* Calculate starting positions */
    starting_pos[0] = 1;

    for (i = 1; i < num_cols; i++)
        starting_pos[i] =
            starting_pos[i - 1] + row_terms[i - 1];

    /* Print row_terms array */
    printf("\nrow_terms[]:\n");
    for (i = 0; i < num_cols; i++)
        printf("%d ", row_terms[i]);

    /* Print starting_pos array */
    printf("\n\nstarting_pos[]:\n");
    for (i = 0; i < num_cols; i++)
        printf("%d ", starting_pos[i]);

    /* Set header of transposed matrix */
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].value = a[0].value;

    /* Perform fast transpose */
    for (i = 1; i <= a[0].value; i++) {
        j = starting_pos[a[i].col]++;

        b[j].row = a[i].col;
        b[j].col = a[i].row;
        b[j].value = a[i].value;
    }
}

int main() {
    term a[MAX], b[MAX];
    int matrix[MAX][MAX];
    int rows, cols, i, j, k = 1;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    if (rows <= 0 || cols <= 0 ||
        rows >= MAX || cols >= MAX) {
        printf("Invalid matrix dimensions\n");
        return 1;
    }

    printf("Enter matrix elements:\n");

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    /* Create array-of-triples representation */
    a[0].row = rows;
    a[0].col = cols;
    a[0].value = 0;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                a[k].row = i;
                a[k].col = j;
                a[k].value = matrix[i][j];
                k++;
                a[0].value++;
            }
        }
    }

    printf("\nOriginal Matrix Triples:\n");
    display(a);

    fast_transpose(a, b);

    printf("\n\nTransposed Matrix Triples:\n");
    display(b);

    printf("\nThe transposed triples are in row-major order.\n");

    return 0;
}
