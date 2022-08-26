/**
@brief Used to solve square equation ax^2 + bx + c = 0
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
@brief Used to makes the first argument maximum and the second argument minimum
@param[out] first argument
@param[out] second argument
*/
void maxmin (double *x1, double *x2);


/**
@brief used to test square solver
@param[in] coefficient a
@param[in] coefficient b
@param[in] coefficient c
@param[in] coefficient number of roots
@param[in] coefficient first answer
@param[in] coefficient second answer
@param[out] coefficient test number
@return 0 if the test is successful
@return 1 if the test isn`t successful
@return 9999 if the test wasn`t tested
*/
int Testing_square_solver (struct Test examp, int *test_number);

/**
@brief Used to do several tests of square solver
@return the number of failed tests
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



/**
@brief Used to determine the end of a line
@return True if '\n' was entered
@return False otherwise
*/
bool reading();

/**
@brief Used to swap arguments
@param[out] first argument
@param[out] second argument
*/
void swapp (double *x1, double *x2);


/**
@brief Used to make test for square_equation_solver
*/
struct Test
{
    double a; ///<coefficient a
    double b; ///<coefficient b
    double c; ///<coefficient c
    int num_roots; ///<right number of roots
    double x1_ans; ///<right first root
    double x2_ans; ///<right second root
};
