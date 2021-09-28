#include <iostream>
#include <algorithm>
#include <utility>

#include "include/DiffEqSolver.h"
using namespace std;

DiffEqSolver::DiffEqSolver(
        std::function<double(double, double)> f_der,
        std::function<double(double)> f,
        double x0, double y0,
        double step_size, double n_intervals)
    :
    f_der(f_der),
    f(f),

    x0(x0), y0(y0),
    step_size(step_size),
    n_intervals(n_intervals),

    xs(vector<double>(n_intervals)),
    approximation(vector<double>(n_intervals))
{
    for (int i = 0; i < n_intervals; ++i)
        xs[i] = x0 + i * step_size;

    transform(xs.begin(), xs.end(), back_inserter(exact), f);  
}

void DiffEqSolver::setNumericalMethod(std::unique_ptr<NumericalMethod>&& nm)
{
    this->nm = move(nm);
}

void DiffEqSolver::applyMethod()
{
    approximation[0] = y0;
    for (int i = 1; i < n_intervals; ++i)
       approximation[i] = nm->calculate(xs[i - 1], approximation[i - 1], step_size, f_der);
}

void DiffEqSolver::test() const
{
    for (const auto& tmp : xs)
        cout << tmp << " ";
    cout << endl;

    for (const auto& tmp : exact)
        cout << tmp << " ";
    cout << endl;

    for (const auto& tmp : approximation)
        cout << tmp << " ";
    cout << endl;
}
