#include <stdio.h>
#include <math.h>
#include <TXLib.h>
#include "function.h"


void input (double* a, double* b, double* c)
{
    printf ("Enter a, b, c coefficient\n");
    bool input_fl = true;
    while (input_fl)
    {
        int success_read = scanf("%lg %lg %lg", a, b, c);
        if (success_read == 3)
            input_fl = false;
        else
            printf ("These are not numbers, repeat please:\n");

        while (reading()) continue;
    }
}


bool reading()
{
    return getchar() != '\n';
}


void output (const int num_roots,  double x1,  double x2)
{
    txSetConsoleAttr (FOREGROUND_GREEN);
    switch (num_roots)
    {
        case ZERO_ROOTS:
            printf ("no roots\n");
            break;
        case ONE_ROOT:
            printf ("one root: ");
            printf ("%lg\n", x1);
            break;
        case TWO_ROOTS:
            printf ("two roots: ");
            printf ("%lg, %lg\n", x1, x2);
            break;
        case INF_ROOTS:
            printf ("infinite number of roots\n");
            break;
        default:
            printf ("Error in square_solver, num_roots = %d, x1 = %lg, x2 = %lg", num_roots, x1, x2);
    }
    txSetConsoleAttr (FOREGROUND_WHITE);
}
