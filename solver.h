#ifndef SOLUTION_H
#define SOLUTION_H

// TODO: read about Makefiles, DO NO READ "Хабр: Makefile для самых маленьких". You can read "man make" or google "GNU Makefile docs"
// TODO: read about INFs NANs +0/-0 in floating point arithmetic
void SolveEquation(double a, double b,
double c, double* x1, double* x2, int* num_roots);

void DetermineEquationType(double a, double b, double c,
    double* x1, double* x2, int* num_roots);

void SolveSquareEquation(double a, double b, double c,
    double* x1, double* x2, int* num_roots);

void SolveLinearEquation(double b, double c,
    double* x1, int* num_roots);

int CompareWithZero(double t);

#endif
