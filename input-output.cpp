#include "input-output.h"


#include <TXLib.h>
#include <stdio.h>
#incude <assert.h>

// TODO: prefer consts over preprocessor macros

#define ENDLESS -1

int ReadCoefficients(double* const a, double* const b, double* const c)
{
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);

    // TODO: check for aliasing?
    printf("������� ������������ ����� ������ � �������:\n\
����������� ��� x^2\n����������� ��� x\n��������� ����\n");



    int scanf_return = scanf("%lf %lf %lf", a, b, c);   //scanf ���������� ��������� ��������� ����������, � � ��� ������� ������� => ���� �������, �� �� �� �� �������
    while (scanf_return != 3) // TODO: 3? I prefer to just call scanf and compare it's return value with number of matches as closely to each other as possible, preferably in the same line scanf(...) != 3. Or you could write scanf() != 3 /* number of matches */
    { // TODO: do...while?
        if (scanf_return == -1)return 1;
        int sign = 0;
        while ((sign = getchar()) != '\n') { // TODO: extract, skip_line?
            printf("Got symb = %d\n", sign);
            if (sign == -1 || sign == 26) { // TODO: Write EOF explicitly
                return 1; //���� ����� ����� �� ����� ����
            }
        }
        printf("���� �����������. ���������, ��� ������� ��������� ������������ ����� ������ � �������:\n\
����������� ��� x^2\n����������� ��� x\n��������� ����\n");
        scanf_return = scanf("%lf %lf %lf", a, b, c);
    }




     //scanf ���������� ��������� ��������� ����������, � � ��� ������� ������� => ���� �������, �� �� �� �� �������
    while ((char scanf_return = scanf("%lf %lf %lf", a, b, c)) != 3) /* number of matches */
    { // TODO: do...while?
        if (scanf_return == -1) return 0;
        int sign = 0;
        while ((sign = getchar()) != '\n') { // TODO: extract, skip_line?
            if (sign == -1 || sign == 26) { // TODO: Write EOF explicitly
                return 1; //���� ����� ����� �� ����� ����
            }
        }
        printf("���� �����������. ���������, ��� ������� ��������� ������������\n");
    }



    return 1; // �� ��������� ����� �����
}

void SkipLine ()
{

}

void PrintRoots(const double x1, const double x2, const int num_roots)
{
    switch(num_roots) {
        case 0:
        case 1: ...
        ...
        default: ...
    }
    if (num_roots == 1) printf("x = %0.2lf", x1);
    else printf("x1 = %0.2lf, x2 = %0.2lf\n", x1, x2);
}

void PrintNumRoots(const int num_roots)
{
    printf("number of roots: ");
    if (num_roots == ENDLESS) printf("endless\n");
    else printf("%d\n", num_roots);
}
