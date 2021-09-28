#include <iostream>
#include <vector>

#include "include/NumericalMethod.h"

using namespace std;

int main()
{
    NumericalMethod nm(
            [](double x, double y) { return (y * y + x * y - x * x) / (x * x); },
            [](double x) { return x * (1 + x * x / 3) / (1 - x * x / 3); },
            1, 2, 0.1, 10
            );
    cout << "here" << endl;

    nm.test();

    return 0;
}
