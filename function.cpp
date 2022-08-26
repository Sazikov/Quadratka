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
        return linear_solver(b, c, x1);
    }
    if (compare (b, 0) == C_EQUAL)                  // b == 0
    {
        if (compare (c, 0) == C_EQUAL)              // c == 0 b == 0
        {
            *x1 = 0;
            *x1 = minus_zero (*x1);
            return ONE_ROOT;
        }
        if (-c/a > 0)
        {
            *x1 = sqrt (-c / a);
            *x2 = -*x1;
            maxmin (&*x1, &*x2);
            *x1 = minus_zero (*x1);
            *x2 = minus_zero (*x2);
            return TWO_ROOTS;
        }
        else
            return ZERO_ROOTS;
    }

    double d = calculate_discriminant (a, b, c);
    if ((compare (d, 0) == C_MORE))
    {
        d = sqrt (d);
        *x1 = (-b + d) / (2 * a);
        *x2 = (-b - d) / (2 * a);
        maxmin (&*x1, &*x2);
        *x1 = minus_zero (*x1);
        *x2 = minus_zero (*x2);
        return TWO_ROOTS;
     }
     else if (compare (d, 0) == C_EQUAL)
     {
        *x1 = (-b + sqrt (d)) / (2 * a);
        *x1 = minus_zero (*x1);
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
    *x1 = minus_zero (*x1);
    return ONE_ROOT;
}


int compare(const double n1, const double n2)
{
    assert (isfinite (n1));
    assert (isfinite (n2));

    if (fabs(n1 - n2) < 1e-6)
        return C_EQUAL;
    else if (n1 - n2 > 1e-6)
        return C_MORE;
    else
        return C_LESS;
}


double calculate_discriminant (const double a, const double b, const double c)
{
    assert (isfinite (a));
    assert (isfinite (b));
    assert (isfinite (c));

    return b*b - 4*a*c;
}


void maxmin (double *x1, double *x2)
 {
    assert (isfinite (*x1));
    assert (isfinite (*x2));

    if (compare(*x1, *x2) == C_LESS)
    {
        double t = *x1;
        *x1 = *x2;
        *x2 = t;
    }
 }


double minus_zero (double x)
{
    if (compare (fabs(x), 0) == C_EQUAL) x = fabs(x);
    return x;
}
