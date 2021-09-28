#include <iostream>
#include <algorithm>

#include "include/NumericalMethod.h"
using namespace std;

NumericalMethod::NumericalMethod(
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

void NumericalMethod::test() const
{
    cout << "xs: " << endl;
    for (const auto& tmp : xs)
        cout << tmp << " ";
    cout << endl;
    cout << "end xs" << endl;

    cout << "exact: " << endl;
    for (const auto& tmp : exact)
        cout << tmp << " ";
    cout << endl;
    cout << "end exact" << endl;
}

