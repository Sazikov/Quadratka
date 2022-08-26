#include <stdio.h>
#include <math.h>
#include <TXLib.h>
#include "function.h"


int Testing_square_solver (struct Test examp, int *test_number)
{
    double a = examp.a;
    double b = examp.b;
    double c = examp.c;
    int num_roots = examp.num_roots;
    double x1_ans = examp.x1_ans;
    double x2_ans = examp.x2_ans;
    *test_number = *test_number + 1;
    double x1 = 0;
    double x2 = 0;
    int numroots = square_solver (a, b, c, &x1, &x2);
    if (!(numroots == num_roots && (compare (x1,x1_ans) == C_EQUAL && compare (x2, x2_ans) == C_EQUAL)))
    {
        txSetConsoleAttr (FOREGROUND_RED);
        printf ("Test %i failed: numroots = %d, x1 = %lg, x2 = %lg\nExpected: numroots = %d, x1 = %lg, x2 = %lg\n", *test_number, numroots, x1,x2,num_roots,x1_ans,x2_ans);
        txSetConsoleAttr (FOREGROUND_WHITE);
        return 1;
    }
    else
    {
        txSetConsoleAttr (FOREGROUND_GREEN);
        printf ("Test %i successful\n", *test_number);
        txSetConsoleAttr (FOREGROUND_WHITE);
        return 0;
    }
    return 9999;
}


int Unit_test()
{
    int number_test = -1;
    int number_succesful_test = 0;
    #define test_num 11
    struct Test examples[test_num] = {
    {1,    3,  2, 2,   -1,  -2}, // 0 test
    {0,    0,  0, -1,   0,  0},  // 1 test
    { 0,    1,  0,  1,   0,  0}, // 2 test
    { 0,    0,  1,  0,   0,  0}, // 3 test
    { 1,    1,  0,  2,   0, -1}, // 4 test
    { 0,    1,  1,  1,  -1,  0}, // 5 test
    { 0,    1,  1,  1,  -1,  0}, // 6 test
    { 1,    0, -1,  2,   1, -1}, // 7 test
    { 1,    1,  1,  0,   0,  0}, // 8 test
    { 1,   -2,  1,  1,   1,  0}, // 9 test
    {-15, -24, 12,  2, 0.4, -2}  // 10 test
                                };

    for (int i = 0; i < test_num; i ++)
    {
        number_succesful_test += Testing_square_solver (examples[i],  &number_test);
    }

    return number_succesful_test;
}
