// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

double fn(double x)
{
    return pow(M_E, x * x);
}

double approximateValue(double a, double b, int n, double (*f)(double))
{
    double sum = 0;
    double delta = (b - a) / n;

    for (int i = 0; i < n; i++)
    {
        sum += f(a) + 4 * f((2 * a + delta) / 2) + f(a + delta);
        a += delta;
    }

    return sum * delta / 6;
}

double RungeMethod(double a, double b, double (*f)(double), double margin) 
{
    int h = 2;
    int h2 = 4;

    int count = 0;
       
    do
    {
        double ih = approximateValue(a, b, h, f);
        double ih2 = approximateValue(a, b, h2, f);

        double RungeMargin = (ih2 - ih) / 15;

        if (abs(RungeMargin) <= margin)
        {
            return ih2;
        }

        h >> 1;
        h2 >> 1;
        count++;
    } while (count < 1000);

    return 0;
}

void log()
{
    double x = 0;

    do
    {
        std::cout << RungeMethod(0, x, fn, 0.0001) << std::endl;
        x += 0.1;
    } while (x <= 1);
}

int main()
{
    // std::cout << RungeMethod(0, 1, fn, 0.0001);
    log();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
