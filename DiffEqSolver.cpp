#include <iostream>
#include <algorithm>

#include "include/DiffEqSolver.h"
using namespace std;

DiffEqSolver::DiffEqSolver(
        std::function<double(double, double)> f_dir,
        std::function<double(double)> f,
        double x0, double y0,
        double step_size, double n_intervals)
    :
    f_dir(f_dir),
    f(f),

    x0(x0), y0(y0),
    step_size(step_size),
    n_intervals(n_intervals),

    xs(vector<double>(n_intervals))
{
    for (int i = 0; i < n_intervals; ++i)
        xs[i] = x0 + i * step_size;

    transform(xs.begin(), xs.end(), back_inserter(exact), f);  
}

