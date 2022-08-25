#include <math.h>
#include <assert.h>
#include <stdio.h>
#include "function.h"


int square_solver(const double a, const double b, const double c, double *x1, double *x2)
{

    assert (isfinite(a));
    assert (isfinite(b));
    assert (isfinite(c));
    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);

    if (compare (a, 0) == C_EQUAL)                  // a == 0
    {
        return linear_solver(b, c, &*x1);
    }
    if (compare (b, 0) == C_EQUAL)                  // b == 0
    {
        if (compare (c, 0) == C_EQUAL)              // c == 0 b == 0
        {
            *x1 = 0;
            return ONE_ROOT;
        }
        if (-c/a > 0)
        {
            *x1 = sqrt (-c / a);
            *x2 = -sqrt (-c / a);
            maxmin (&*x1, &*x2);
            return TWO_ROOTS;
        }
        else
            return ZERO_ROOTS;
    }

    double d = discriminant_solver (a, b, c);
    if ((compare (d, 0) == C_MORE))
    {
        *x1 = (-b + sqrt (d)) / (2 * a);
        *x2 = (-b - sqrt (d)) / (2 * a);
        maxmin (&*x1, &*x2);
        return TWO_ROOTS;
     }
     else if (compare (d, 0) == C_EQUAL)
     {
        *x1 = (-b + sqrt (d)) / (2 * a);
        return ONE_ROOT;
     }
     else
        return ZERO_ROOTS;

    return WRONG;
}


int linear_solver(const double k, const double b, double *x1)
{
    assert (isfinite (k));
    assert (isfinite (b));
    assert (x1 != NULL);

    if (compare (k, 0) == C_EQUAL)
    {
        if (compare (b, 0) == C_EQUAL)
        {
            return INF_ROOTS;
        }
        return ZERO_ROOTS;
    }

    *x1 = -b / k;

    return ONE_ROOT;
}


int compare(const double n1, const double n2)
{   if (fabs(n1 - n2) < 1e-6)
        return C_EQUAL;
    else if (n1 - n2 > 1e-6)
        return C_MORE;
    else
        return C_LESS;
}


double discriminant_solver(const double a, const double b, const double c)
{
    return b*b - 4*a*c;
}


void print_equation(const double a, const double b, const double c)
{
         if (compare(a,0) == C_MORE  && compare(b,0) == C_MORE  && compare(c,0) == C_MORE)  printf("%lg*x^2 + %lg*x + %lg = 0\n", a, fabs(b), fabs(c));
    else if (compare(a,0) == C_MORE  && compare(b,0) == C_MORE  && compare(c,0) == C_LESS)  printf("%lg*x^2 + %lg*x - %lg = 0\n", a, fabs(b), fabs(c));
    else if (compare(a,0) == C_MORE  && compare(b,0) == C_LESS  && compare(c,0) == C_MORE)  printf("%lg*x^2 - %lg*x + %lg = 0\n", a, fabs(b), fabs(c));
    else if (compare(a,0) == C_LESS  && compare(b,0) == C_MORE  && compare(c,0) == C_MORE)  printf("%lg*x^2 + %lg*x + %lg = 0\n", a, fabs(b), fabs(c));
    else if (compare(a,0) == C_MORE  && compare(b,0) == C_LESS  && compare(c,0) == C_LESS)  printf("%lg*x^2 - %lg*x - %lg = 0\n", a, fabs(b), fabs(c));
    else if (compare(a,0) == C_LESS  && compare(b,0) == C_LESS  && compare(c,0) == C_LESS)  printf("%lg*x^2 - %lg*x - %lg = 0\n", a, fabs(b), fabs(c));
    else if (compare(a,0) == C_LESS  && compare(b,0) == C_MORE  && compare(c,0) == C_LESS)  printf("%lg*x^2 + %lg*x - %lg = 0\n", a, fabs(b), fabs(c));
    else if (compare(a,0) == C_LESS  && compare(b,0) == C_LESS  && compare(c,0) == C_MORE)  printf("%lg*x^2 - %lg*x + %lg = 0\n", a, fabs(b), fabs(c));
    else if (compare(a,0) == C_EQUAL && compare(b,0) == C_LESS  && compare(c,0) == C_MORE)  printf("-%lg*x + %lg = 0\n", fabs(b), fabs(c));
    else if (compare(a,0) == C_EQUAL && compare(b,0) == C_MORE  && compare(c,0) == C_LESS)  printf("%lg*x - %lg = 0\n",  fabs(b), fabs(c));
    else if (compare(a,0) == C_EQUAL && compare(b,0) == C_MORE  && compare(c,0) == C_MORE)  printf("%lg*x + %lg = 0\n",  fabs(b), fabs(c));
    else if (compare(a,0) == C_EQUAL && compare(b,0) == C_LESS  && compare(c,0) == C_LESS)  printf("-%lg*x - %lg = 0\n", fabs(b), fabs(c));
    else if (compare(a,0) == C_EQUAL && compare(b,0) == C_EQUAL && compare(c,0) == C_MORE)  printf("%lg = 0\n", fabs(c));
    else if (compare(a,0) == C_EQUAL && compare(b,0) == C_EQUAL && compare(c,0) == C_LESS)  printf("-%lg = 0\n",fabs(c));
    else if (compare(a,0) == C_EQUAL && compare(b,0) == C_EQUAL && compare(c,0) == C_EQUAL) printf("0 = 0\n");
    else if (compare(a,0) == C_EQUAL && compare(b,0) == C_MORE  && compare(c,0) == C_EQUAL) printf("%lg*x = 0\n", fabs(b));
    else if (compare(a,0) == C_EQUAL && compare(b,0) == C_LESS  && compare(c,0) == C_EQUAL) printf("-%lg*x = 0\n",fabs(b));
    else if (compare(a,0) == C_LESS  && compare(b,0) == C_EQUAL && compare(c,0) == C_LESS)  printf("%lg*x^2 - %lg = 0\n",   a, fabs(c));
    else if (compare(a,0) == C_MORE  && compare(b,0) == C_EQUAL && compare(c,0) == C_LESS)  printf("%lg*x^2 - %lg = 0\n",   a, fabs(c));
    else if (compare(a,0) == C_MORE  && compare(b,0) == C_EQUAL && compare(c,0) == C_MORE)  printf("%lg*x^2 + %lg = 0\n",   a, fabs(c));
    else if (compare(a,0) == C_LESS  && compare(b,0) == C_EQUAL && compare(c,0) == C_MORE)  printf("%lg*x^2 + %lg = 0\n",   a, fabs(c));
    else if (compare(a,0) == C_LESS  && compare(b,0) == C_MORE  && compare(c,0) == C_EQUAL) printf("%lg*x^2 + %lg*x = 0\n", a, fabs(b));
    else if (compare(a,0) == C_MORE  && compare(b,0) == C_MORE  && compare(c,0) == C_EQUAL) printf("%lg*x^2 + %lg*x = 0\n", a, fabs(b));
    else if (compare(a,0) == C_MORE  && compare(b,0) == C_LESS  && compare(c,0) == C_EQUAL) printf("%lg*x^2 - %lg*x = 0\n", a, fabs(b));
    else if (compare(a,0) == C_LESS  && compare(b,0) == C_LESS  && compare(c,0) == C_EQUAL) printf("%lg*x^2 - %lg*x = 0\n", a, fabs(b));
}


void maxmin (double *x1, double *x2)
 {
        if (*x1 < *x2)
        {
            double t = *x1;
            *x1 = *x2;
            *x2 = t;
        }
 }


