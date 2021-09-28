#ifndef DIFF_EQ_SOLVER_H
#define DIFF_EQ_SOLVER_H

#include <functional>

class DiffEqSolver
{
public:
    DiffEqSolver(
            std::function<double(double, double)> f_dir,
            std::function<double(double)> f,
            double x0, double y0,
            double step_size, double n_intervals);
protected:
    std::function<double(double, double)> f_dir;
    std::function<double(double)> f;
    double step_size;
    double n_intervals;
    double x0;
    double y0;
    std::vector<double> xs;
    std::vector<double> exact;
    std::vector<double> approximation;
    std::vector<double> lte;
    std::vector<double> gte;
};

#endif /* !DIFF_EQ_SOLVER_H */
