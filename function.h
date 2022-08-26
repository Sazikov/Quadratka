/**
@brief Used to solve square equation ax^2 + bx + c=0
@param[in] coefficient a
@param[in] coefficient b
@param[in] coefficient c
@param[out] first root
@param[out] second root
@return number of roots
*/
int square_solver (const double a, const double b, const double c, double *x1, double *x2);

/**
@brief Used to solve linear equation y = kx + b
@param[in] coefficient k
@param[in] coefficient b
@param[out] root of equation
@return number of roots
*/
int linear_solver (const double k, const double b, double *x);

/**
@brief Used to input a,b,c coefficients
@param[out] coefficient a
@param[out] coefficient b
@param[out] coefficient c
*/
void input (double* a, double* b, double* c);

/**
@brief Used to output number of roots and roots
@param[out] number of roots
@param[out] first root
@param[out] second root
*/
void output (const int num_roots, double x1, double x2);

/**
@brief Used to solve discriminant of square equation ax^2 + bx + c = 0
@param[in] coefficient a
@param[in] coefficient b
@param[in] coefficient c
@return discriminant
*/
double calculate_discriminant (double a, double b, double c);

/**
@brief Used to compare double value
@param[in] first value
@param[in] second value
@return the result of comparison: LESS, MORE or EQUAL
*/
int compare (const double n1, const double n2);

/**
@brief Used to make first value max from both values
@param[out] first value
@param[out] second value
*/
void maxmin (double *x1, double *x2);

/**
@brief Used to print equation
@param[in] coefficient a
@param[in] coefficient b
@param[in] coefficient c
*/
void print_equation (const double a, const double b, const double c);


/**
@brief used to test square solver
@param[in] coefficient a
@param[in] coefficient b
@param[in] coefficient c
@param[in] coefficient number of roots
@param[in] coefficient first answer
@param[in] coefficient second answer
@param[out] coefficient test number
@return 0 if the test is successful and return not 0 if the test isn`t successful
*/
int Testing_square_solver (const double a, const double b, const double c, const int num_roots, const double x1_ans, const double x2_ans, int *test_number);

/**
@brief Used to do several tests of square solver
@return 0 if all test are successful and return not 0 if at least one test isn`t successful
*/
int Unit_test();

/**
@brief Used to assign numerical values to the comparison results
*/
enum comp
{
    C_MORE = 1,///<is assigned the value 1
    C_EQUAL = 0,///<is assigned the value 0
    C_LESS = -1///<is assigned the value -1
};

/**
@brief Used to assign numerical values to the number of roots
*/
enum roots
{
    INF_ROOTS = -1,///<is assigned the value -1
    ZERO_ROOTS = 0,///<is assigned the value 0
    ONE_ROOT = 1,///<is assigned the value 1
    TWO_ROOTS = 2,///<is assigned the value 2
    WRONG = 7///<is assigned the value 7
};


/**
@brief Used to make zero positive, if input value is negative zero
@param[in] double value
@return positive zero or other double value
*/
double minus_zero (double x);

