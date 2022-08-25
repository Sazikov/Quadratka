#include <stdio.h>
#include <math.h>

#include "function.h"


int Testing_square_solver (const double a, const double b, const double c, const int num_roots, const double x1_ans, const double x2_ans, int *test_number)
{
    *test_number = *test_number + 1;
    double x1 = 0;
    double x2 = 0;
    int numroots = square_solver (a, b, c, &x1, &x2);
    if (!(numroots == num_roots && (compare (x1,x1_ans) == C_EQUAL && compare (x2, x2_ans) == C_EQUAL)))
    {
        printf ("Test %i failed: numroots = %d, x1 = %lg, x2 = %lg\nExpected: numroots = %d, x1 = %lg, x2 = %lg\n", *test_number, numroots, x1,x2,num_roots,x1_ans,x2_ans);
        return 1;
    }
    else
    {
        printf ("Test %i successful\n", *test_number);
        return 0;
    }
    return 9999;
}


int Unit_test()
{
    int number_test = 0;
    int number_succesful_test = 0;
    number_succesful_test = number_succesful_test + Testing_square_solver (  0,   0,  0, -1,   0,  0, &number_test);//1test
    number_succesful_test = number_succesful_test + Testing_square_solver (  0,   1,  0,  1,   0,  0, &number_test);//2test
    number_succesful_test = number_succesful_test + Testing_square_solver (  0,   0,  1,  0,   0,  0, &number_test);//3test
    number_succesful_test = number_succesful_test + Testing_square_solver (  1,   1,  0,  2,   0, -1, &number_test);//4test
    number_succesful_test = number_succesful_test + Testing_square_solver (  0,   1,  1,  1,  -1,  0, &number_test);//5test
    number_succesful_test = number_succesful_test + Testing_square_solver (  1,   0,  1,  0,   0,  0, &number_test);//6test
    number_succesful_test = number_succesful_test + Testing_square_solver (  1,   0, -1,  2,   1, -1, &number_test);//7test
    number_succesful_test = number_succesful_test + Testing_square_solver (  1,   1,  1,  0,   0,  0, &number_test);//8test
    number_succesful_test = number_succesful_test + Testing_square_solver (  1,  -2,  1,  1,   1,  0, &number_test);//9test
    number_succesful_test = number_succesful_test + Testing_square_solver (-15, -24, 12,  2, 0.4, -2, &number_test);//10test
    return number_succesful_test;
}
