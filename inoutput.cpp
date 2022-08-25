#include <stdio.h>
#include <math.h>

#include "function.h"


void input (double* a, double* b, double* c)
{
    printf ("Enter a, b, c coefficient\n");
    bool input_fl = true;
    while (input_fl)
    {
        int times = scanf("%lg %lg %lg", a, b, c);
        if (times == 3) input_fl = false;
        else printf ("These are not numbers, repeat please:\n");
        while (getchar() != '\n') continue;
    }
}


void output (int *num_roots,  double *x1,  double *x2)
{
    switch (*num_roots)
    {
    case ZERO_ROOTS:
        printf ("no roots\n");
        break;
    case ONE_ROOT:
        printf ("one root: ");
        if (compare (fabs(*x1), 0) == C_EQUAL) *x1 = fabs(*x1);
        printf ("%lg\n", *x1);
        break;
    case TWO_ROOTS:
        printf ("two roots: ");
        if (compare (fabs(*x1), 0) == C_EQUAL) *x1 = fabs(*x1);
        if (compare (fabs(*x2), 0) == C_EQUAL) *x2 = fabs(*x2);
        printf ("%lg, %lg\n", *x1, *x2);
        break;
    case INF_ROOTS:
        printf ("infinite number of roots\n");
        break;
    default:
        printf ("Error in square_solver, num_roots = %d, x1 = %lg, x2 = %lg", *num_roots, *x1, *x2);
    }

}
