//! Нахождение корней x1 и x2 и их количества квадратного уравнения a*x^2 + b*x + с = 0

#include <TXLib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "input-output.h"
#include "solver.h"


int main ()
{
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    int num_roots = 0;
    if (!ReadCoefficients(&a, &b, &c)) return 1;  //встретили конец ввода до ввода коэфициентов
    SolveEquation(a, b, c, &x1, &x2, &num_roots);
    PrintNumRoots(num_roots);
    PrintRoots(x1, x2, num_roots);
    return 0;
}
