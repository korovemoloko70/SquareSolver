#include "solver.h"

#include <math.h>
#include <assert.h>
#include "input-output.h"

#define ANYTHING_IS_ROOT -1
#define E 0.0000001

void SolveEquation(const double a, const double b, const double c,
    double* const x1, double* const x2, int* const num_roots)
{
    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    assert(num_roots != NULL);
    DetermineEquationType(a, b, c, x1, x2, num_roots);
}

void DetermineEquationType(const double a, const double b, const double c,
    double* const x1, double* const x2, int* const num_roots)
{
    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);
    assert(num_roots != NULL);

    if (CompareWithZero(a) == 0) SolveLinearEquation(b, c, x1, num_roots);  // линейное
    else SolveSquareEquation(a, b, c, x1, x2, num_roots);  // квадратное уравнение
}

void SolveSquareEquation(const double a, const double b, const double c,
    double* const x1, double* const x2, int* const num_roots)
{
    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);
    assert(num_roots != NULL);

    const double d = b*b - 4*a*c;
    const double sq_root = sqrt(d);

    if (CompareWithZero(d) == 0)
    {
        *x1 = (- b + sq_root) / (2 * a); // квадратное уравнение c 1 корнем
        *num_roots = 1;
    }
    else if (CompareWithZero(d) > 0) //квадратное уравнение c d > 0
    {
        *x1 = (- b + sq_root) / (2 * a);
        *x2 = (- b - sq_root) / (2 * a);
        *num_roots = 2;
    }
    else *num_roots = 0;//квадратное уравнение c d < 0
}

void SolveLinearEquation(const double b, const double c, double* const x1,
    int* const num_roots)
{
    assert (x1 != NULL);
    assert(num_roots != NULL);

    if (CompareWithZero(b) == 0)
    {
       if (CompareWithZero(c) == 0) return *num_roots = ANYTHING_IS_ROOT;    // a = 0, b = 0, c = 0
       else *num_roots = 0;           // a = 0, b = 0, c != 0
    }
    else
    {
        *x1 = -c / b;
        *num_roots = 1;
    }
}

int CompareWithZero(const double t)
{
   if (E <= t && t <= -E) return 0;
   if (E < t) return 1;
   return -1;
}
