#include <iostream>
#include <memory>
#include <utility>

#include "include/DiffEqSolver.h"
#include "include/NumericalMethod.h"

using namespace std;

int main()
{
    DiffEqSolver des(
            [](double x, double y) { return (y * y + x * y - x * x) / (x * x); },
            [](double x) { return x * (1 + x * x / 3) / (1 - x * x / 3); },
            1, 2, 0.1, 10
            );

    unique_ptr<NumericalMethod> nm = make_unique<EulerMethod>();

    des.setNumericalMethod(move(nm));

    des.applyMethod();
    des.test();


    unique_ptr<NumericalMethod> nm1 = make_unique<ImprovedEulerMethod>();

    des.setNumericalMethod(move(nm1));

    des.applyMethod();
    des.test();


    unique_ptr<NumericalMethod> nm2 = make_unique<RungeKuttaMethod>();

    des.setNumericalMethod(move(nm2));

    des.applyMethod();
    des.test();



    return 0;
}
