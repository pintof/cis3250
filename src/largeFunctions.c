#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "helperFunctions.h"
#include "largeFunctions.h"

// Found in Conversions
void time()
{
    int from, to;
    double t1, t2;

    printf("\n\t\tseconds(1)\t\tminutes(2)\t\thours(3)\t\tdays(4)\n\n\n\t\tweeks(5)\t\tmonths(6)\t\tyears(7)\t\tDecades(8)\n\n\n\t\tcenturies(9)\t\tmilleniums(10)\t\tlight years(11)\t\tGenerations(12):");
    printf("\n\n\n\t\tConvert from(number):");
    scanf("%d", &from);
    printf("\n\n\n\t\tConvert to(number):");
    scanf("%d", &to);
    if (from == to)
    {
        printf("Enter time:");
        scanf("%lf", &t1);
        printf("The resultant value is %f", t1);
    }
    else
    {
        printf("\n\n\n\t\tEnter the time:");
        scanf("%lf", &t1);
        if (from == 1)
        {
            if (to == 2)
            {
                t2 = t1 / 60;
                if (t2 <= 1 && t2 >= 0)
                {
                    printf("\n\n\n\t\t%f seconds = %f minute", t1, t2);
                }
                else if (t1 == 1)
                {
                    printf("\n\n\n\t\t1 second = %f minute", t2);
                }
                else
                {
                    printf("\n\n\n\t\t%f seconds = %f minutes", t1, t2);
                }
            }
            if (to == 3)
            {
                t2 = t1 / 3600;
                if (t2 <= 1 && t2 >= 0)
                {
                    printf("\n\n\n\t\t%f seconds = %f hour", t1, t2);
                }
                else if (t1 == 1)
                {
                    printf("\n\n\n\t\t1 second = %f hour", t2);
                }
                else
                {
                    printf("\n\n\n\t\t%f seconds = %f hours", t1, t2);
                }
            }
            if (to == 4)
            {
                t2 = t1 / (3600 * 24);
                if (t2 <= 1 && t2 >= 0)
                {
                    printf("\n\n\n\t\t%f seconds = %f day", t1, t2);
                }
                else if (t1 == 1)
                {
                    printf("\n\n\n\t\t1 second = %f ", t2);
                }
                else
                {
                    printf("\n\n\n\t\t%f seconds = %f days", t1, t2);
                }
            }
            if (to == 5)
            {
                t2 = t1 / (3600 * 24 * 7);
                if (t2 <= 1 && t2 >= 0)
                {
                    printf("\n\n\n\t\t%f seconds = %f week", t1, t2);
                }
                else if (t1 == 1)
                {
                    printf("\n\n\n\t\t1 second = %f week", t2);
                }
                else
                {
                    printf("\n\n\n\t\t%f seconds = %f weeks", t1, t2);
                }
            }
            if (to == 6)
            {
                t2 = t1 / (3600 * 24 * 30);
                if (t2 <= 1 && t2 >= 0)
                {
                    printf("\n\n\n\t\t%f seconds = %f month", t1, t2);
                }
                else if (t1 == 1)
                {
                    printf("\n\n\n\t\t1 second = %f month", t2);
                }
                else
                {
                    printf("\n\n\n\t\t%f seconds = %f months", t1, t2);
                }
            }
            if (to == 7)
            {
                t2 = t1 / (3600 * 24 * 365.25);
                if (t2 <= 1 && t2 >= 0)
                {
                    printf("\n\n\n\t\t%f seconds = %f year ", t1, t2);
                }
                else if (t1 == 1)
                {
                    printf("\n\n\n\t\t1 second = %f year", t2);
                }
                else
                {
                    printf("\n\n\n\t\t%f seconds = %f years", t1, t2);
                }
            }
            if (to == 8)
            {
                t2 = t1 / (3600 * 24 * 365.25 * 10);
                if (t2 <= 1 && t2 >= 0)
                {
                    printf("\n\n\n\t\t%f seconds = %f decade", t1, t2);
                }
                else if (t1 == 1)
                {
                    printf("\n\n\n\t\t1 second = %f decade", t2);
                }
                else
                {
                    printf("\n\n\n\t\t%f seconds = %f decades", t1, t2);
                }
            }
            if (to == 9)
            {
                t2 = t1 / (3600 * 24 * 365.25 * 100);
                if (t2 <= 1 && t2 >= 0)
                {
                    printf("\n\n\n\t\t%f seconds = %f century", t1, t2);
                }
                else if (t1 == 1)
                {
                    printf("\n\n\n\t\t1 second = %f century", t2);
                }
                else
                {
                    printf("\n\n\n\t\t%f seconds = %f centuries", t1, t2);
                }
            }
            if (to == 10)
            {
                t2 = t1 / (3600 * 24 * 365.25 * 1000);
                if (t2 <= 1 && t2 >= 0)
                {
                    printf("\n\n\n\t\t%f seconds = %f millenium", t1, t2);
                }
                else if (t1 == 1)
                {
                    printf("\n\n\n\t\t1 second = %f millenium", t2);
                }
                else
                {
                    printf("\n\n\n\t\t%f seconds = %f milleniums", t1, t2);
                }
            }
            if (to == 12)
            {
                t2 = t1 / (3600 * 24 * 365.25 * 30);
                if (t2 <= 1 && t2 >= 0)
                {
                    printf("%f seconds = %f Generation", t1, t2);
                }
                else if (t1 == 1)
                {
                    printf("1 second = %f Generation", t2);
                }
                else
                {
                    printf("%f seconds = %f Generations", t1, t2);
                }
            }
        }
    }
}

// Found in Conversions
void temp()
{
    int from, to;
    double t1, t2, t3;

    printf("\n\n\n\t\t\tCelsius(1)\t\t\tFahrenheit(2)\t\t\tKelvin(3)");
    printf("\n\n\n\t\t\tConvert from(number):");
    scanf("%d", &from);
    printf("\n\n\n\t\t\tConvert to(number):");
    scanf("%d", &to);
    printf("\n\n\n\t\t\tEnter temperature:");
    scanf("%lf", &t1);

    if (from == to)
    {
        printf("\n\n\n\t\t\t The resulting temperature remains the same; %f", t1);
    }
    else
    {
        switch (from)
        {
        case 1:
            switch (to)
            {
            case 2:
                t2 = t1 * 9 / 5 + 32.0;
                printf("\n\n\n\t\t\t%fC=%fF", t1, t2);
                break;
            case 3:
                t2 = t1 + 273.15;
                printf("\n\n\n\t\t\t%fC=%fK", t1, t2);
                break;
            }
            break;
        case 2:
            switch (to)
            {
            case 1:
                t2 = (t1 - 32.0) * 5 / 9;
                printf("\n\n\n\t\t\t%fF=%fC", t1, t2);
                break;
            case 3:
                t1 = (t1 - 32.0) * 5 / 9;
                t2 = t1 + 273.15;
                printf("\n\n\n\t\t\t%fF=%fK", t1, t2);
                break;
            }
        case 3:
            switch (to)
            {
            case 1:
                t2 = t1 - 273.15;
                printf("\n\n\n\t\t\t%fK=%fC", t1, t2);
                break;
            case 2:
                t2 = (t1 - 273.15) * 9 / 5 + 32;
                printf("\n\n\n\t\t\t%fK=%fF", t1, t2);
                break;
            }
        }
    }
}

// Found in factorial
/*Factorial function inefficient for values after 20*/
unsigned long long int fact(int n)
{
    unsigned long long int fact;
    int i;
    fact = 1;

    for (i = n; i > 0; i--)
    {
        fact *= i;
    }
    return fact;
}

// Found in Matrices
void matrix_sum()
{

    int i, j, n1, m1, n2, m2;

    printf("Enter the number of rows of matrix 1:");
    scanf("%d", &n1);
    printf("Enter the number of columns of matrix :");
    scanf("%d", &m1);
    printf("Enter the number of rows of matrix 2:");
    scanf("%d", &n2);
    printf("Enter the number of columns of matrix 2:");
    scanf("%d", &m2);
    if (n1 == n2 && m1 == m2)
    {

        float a[n1][m1];
        float b[n2][m2];
        float c[n1][m1];

        for (i = 0; i < n1; i++)
        {
            printf("Enter the members of matrix 1 row %d :", i + 1);
            for (j = 0; j < m1; j++)
            {
                scanf("%f", &a[i][j]);
            }
        }
        for (i = 0; i < n2; i++)
        {
            printf("Enter the members of matrix 2 row %d :", i + 1);
            for (j = 0; j < m2; j++)
            {
                scanf("%f", &b[i][j]);
            }
        }
        for (i = 0; i < n1; i++)
        {
            for (j = 0; j < m1; j++)
            {
                c[i][j] = a[i][j] + b[i][j];
            }
        }
        printf("The sum of both matrices is\n:");
        for (j = 0; j < m1; j++)
        {
            for (i = 0; i < n1; i++)
            {
                printf("\t\t %.0f", c[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("\n\tThe matrices are incompatible");
    }
}

// Found in Matrices
void matrix_product()
{

    int i, j, n1, m1, n2, m2, l, k;

    printf("Enter the number of rows of matrix 1:");
    scanf("%d", &n1);
    printf("Enter the number of columns of matrix :");
    scanf("%d", &m1);
    printf("Enter the number of rows of matrix 2:");
    scanf("%d", &n2);
    printf("Enter the number of columns of matrix 2:");
    scanf("%d", &m2);

    float a[n1][m1];
    float b[n2][m2];
    float c[n1][m1];
    for (i = 0; i < n1; i++)
    {
        printf("Enter the members of matrix 1 row %d :", i + 1);
        for (j = 0; j < m1; j++)
        {
            scanf("%f", &a[i][j]);
        }
    }
    for (i = 0; i < n2; i++)
    {
        printf("Enter the members of matrix 2 row %d :", i + 1);
        for (j = 0; j < m2; j++)
        {
            scanf("%f", &b[i][j]);
        }
    }
    c[i][j] = 1;
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < m2; j++)
        {
            c[i][j] = 0;
            c[i][j] += a[i][j] * b[i][j];
        }
    }

    printf("The  of the matrix is\n:");
    for (j = 0; j < m1; j++)
    {
        for (i = 0; i < n2; i++)
        {
            printf("\t\t %.0f", a[i][j]);
        }
        printf("\n");
    }
}

// Found in Matrices
void matrix_transpose()
{

    int i, j, n, m;

    printf("Enter the number of rows:");
    scanf("%d", &n);
    printf("Enter the number of columns:");
    scanf("%d", &m);

    float a[n][m];

    for (i = 0; i < n; i++)
    {
        printf("Enter the members of row %d :", i + 1);
        for (j = 0; j < m; j++)
        {
            scanf("%f", &a[i][j]);
        }
    }

    printf("The transpose of the matrix is\n:");
    for (j = 0; j < m; j++)
    {
        for (i = 0; i < n; i++)
        {
            printf("\t\t %.0f", a[i][j]);
        }
        printf("\n");
    }
}

// Found in PowerFunction
double powerfn(double x, int n)
{
    int i;
    double result = 1;

    for (i = 1; i <= n; i++)
    {
        result *= x;
    }
    return result;
}