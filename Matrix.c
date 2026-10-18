#include <stdio.h>

#define MAX 10

void addMatrices(int a[MAX][MAX], int b[MAX][MAX],
                 int r, int c)
{
    int i, j;

    printf("\nMatrix Addition:\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
            printf("%d ", a[i][j] + b[i][j]);
        printf("\n");
    }
}

void multiplyMatrices(int a[MAX][MAX], int b[MAX][MAX],
                      int r1, int c1, int c2)
{
    int i, j, k, sum;

    printf("\nMatrix Multiplication:\n");
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            sum = 0;
            for (k = 0; k < c1; k++)
                sum += a[i][k] * b[k][j];

            printf("%d ", sum);
        }
        printf("\n");
    }
}

void transposeMatrix(int a[MAX][MAX], int r, int c)
{
    int i, j;

    printf("\nTranspose of First Matrix:\n");
    for (j = 0; j < c; j++)
    {
        for (i = 0; i < r; i++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

int main()
{
    int a[MAX][MAX], b[MAX][MAX];
    int r1, c1, r2, c2;
    int i, j;

    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and columns of second matrix: ");
    scanf("%d %d", &r2, &c2);

    if (r1 < 1 || r1 > MAX || c1 < 1 || c1 > MAX ||
        r2 < 1 || r2 > MAX || c2 < 1 || c2 > MAX)
    {
        printf("Invalid dimensions! Enter values from 1 to 10.\n");
        return 1;
    }

    printf("Enter elements of first matrix:\n");
    for (i = 0; i < r1; i++)
        for (j = 0; j < c1; j++)
            scanf("%d", &a[i][j]);

    printf("Enter elements of second matrix:\n");
    for (i = 0; i < r2; i++)
        for (j = 0; j < c2; j++)
            scanf("%d", &b[i][j]);

    if (r1 == r2 && c1 == c2)
        addMatrices(a, b, r1, c1);
    else
        printf("\nAddition is not possible: dimensions differ.\n");

    if (c1 == r2)
        multiplyMatrices(a, b, r1, c1, c2);
    else
        printf("\nMultiplication is not possible: columns of first matrix must equal rows of second.\n");

    transposeMatrix(a, r1, c1);

    return 0;
}
