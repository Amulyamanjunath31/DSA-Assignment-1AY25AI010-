#include <stdio.h>

typedef struct {
    int degree;
    float coef[101];
} polynomial;

polynomial add(polynomial a, polynomial b) {
    polynomial result;
    int i, exp;

    result.degree = (a.degree > b.degree) ? a.degree : b.degree;

    for (i = 0; i <= result.degree; i++) {
        exp = result.degree - i;

        result.coef[i] = 0;

        if (exp <= a.degree)
            result.coef[i] += a.coef[a.degree - exp];

        if (exp <= b.degree)
            result.coef[i] += b.coef[b.degree - exp];
    }

    return result;
}

void display(polynomial p) {
    int i, exp, printed = 0;
    float c;

    for (i = 0; i <= p.degree; i++) {
        c = p.coef[i];
        exp = p.degree - i;

        if (c == 0)
            continue;

        if (printed && c > 0)
            printf(" + ");
        else if (printed && c < 0)
            printf(" - ");
        else if (c < 0)
            printf("-");

        if (c < 0)
            c = -c;

        if (exp == 0)
            printf("%g", c);
        else if (exp == 1) {
            if (c == 1)
                printf("x");
            else
                printf("%gx", c);
        }
        else {
            if (c == 1)
                printf("x^%d", exp);
            else
                printf("%gx^%d", c, exp);
        }

        printed = 1;
    }

    if (!printed)
        printf("0");

    printf("\n");
}

int main() {
    polynomial a, b, result;
    int i;

    printf("Enter degree of first polynomial: ");
    scanf("%d", &a.degree);

    if (a.degree < 0 || a.degree > 100) {
        printf("Invalid degree\n");
        return 1;
    }

    printf("Enter coefficients of first polynomial from highest degree to constant:\n");
    for (i = 0; i <= a.degree; i++)
        scanf("%f", &a.coef[i]);

    printf("Enter degree of second polynomial: ");
    scanf("%d", &b.degree);

    if (b.degree < 0 || b.degree > 100) {
        printf("Invalid degree\n");
        return 1;
    }

    printf("Enter coefficients of second polynomial from highest degree to constant:\n");
    for (i = 0; i <= b.degree; i++)
        scanf("%f", &b.coef[i]);

    printf("\nFirst polynomial: ");
    display(a);

    printf("Second polynomial: ");
    display(b);

    result = add(a, b);

    printf("Sum of polynomials: ");
    display(result);

    return 0;
}
