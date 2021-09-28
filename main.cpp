#include <iostream>
#include <vector>

#include "include/DiffEqSolver.h"

using namespace std;

int main()
{
    DiffEqSolver des(
            [](double x, double y) { return (y * y + x * y - x * x) / (x * x); },
            [](double x) { return x * (1 + x * x / 3) / (1 - x * x / 3); },
            1, 2, 0.1, 10
            );

    return 0;
}
