#ifndef DIFF_EQ_SOLVER_H
#define DIFF_EQ_SOLVER_H

#include <functional>
#include <memory>

#include "NumericalMethod.h"

class DiffEqSolver
{
public:
    DiffEqSolver(
            std::function<double(double, double)> f_der,
            std::function<double(double)> f,
            double x0, double y0,
            double step_size, double n_intervals);

    void setNumericalMethod(std::unique_ptr<NumericalMethod> nm);

    void applyMethod();

    void calc_lte();

    void calc_gte();

    void test() const;
private:
    std::unique_ptr<NumericalMethod> nm;
private:
    std::function<double(double, double)> f_der;
    std::function<double(double)> f;
    double x0;
    double y0;
    double step_size;
    double n_intervals;
    std::vector<double> xs;
    std::vector<double> exact;
    std::vector<double> approximation;
    std::vector<double> lte;
    std::vector<double> gte;
};

#endif /* !DIFF_EQ_SOLVER_H */
