#include "tester.h"

#include <TXLib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#include "solver.h"

bool TestingSolver()
{
    printf("Hello from tests\n");
    int allright = 1;
    allright &= TestingOne(1, 5, 6, -2, -3, 2);
    allright &= TestingOne(0, 0, 0, 0, 0, -1);
    allright &= TestingOne(1, 0, -4, 2, -2, 2);
    return allright;
}

/*int TestingSolver()
{
    printf("Hello from tests\n");
    int allright = 1; // NOTE: prefer true/false from <stdbool.h>
    allright *= TestingOne(1, 5, 6, -2, -3, 2); // TODO: prefer &=
    allright *= TestingOne(0, 0, 0, 0, 0, -1);
    allright *= TestingOne(1, 0, -4, 2, -2, 2);
    return allright;
}  */

int TestingOne(const double a, const double b, const double c,
            const double target_x1, const  double target_x2, const double target_num_roots)
{
    double x1 = 0, x2 = 0;
    int num_roots = 0;
    SolveEquation(a, b, c, &x1, &x2, &num_roots);

    if (!(CompareWithZero(x1 - target_x1)) == 0
       && (CompareWithZero(x2 - target_x2)) == 0
       && (CompareWithZero(num_roots - target_num_roots)) == 0)  // сравниваем через ф-ю так как это double, хранящие ошибку
    {
        printf("Fail:\nEquationSolver (%.2lf, %.2lf, %.2lf) print x1 = %.2lf, x2 = %.2lf, shoud be x1 = %.2lf, x2 = %.2lf\n",
               a, b, c, x1, x2, target_x1, target_x2);
        return 0;
    }
    return 1;
}
