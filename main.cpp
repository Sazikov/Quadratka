#include <stdio.h>
#include <stdlib.h>

#include "function.h"

#define Test


int main()
{
#ifdef Test
    int succesful = Unit_test();
    if (!(succesful == 0)) return 0;
#endif

    printf ("Square equation solver\n");
    printf ("a*x^2 + b*x + c = 0\n");

    double  a = 0;
    double  b = 0;
    double  c = 0;
    double x1 = 0;
    double x2 = 0;


    input (&a, &b, &c);

    printf("%lg*x^2 + %lg*x + %lg = 0\n", a, b, c);


    int num_roots = square_solver (a, b, c, &x1, &x2);

    output (num_roots, x1, x2);
    return 0;
}



