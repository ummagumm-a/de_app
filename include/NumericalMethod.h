#ifndef NUMERICALMETHOD_H
#define NUMERICALMETHOD_H

#include <functional>

class NumericalMethod
{
public:
    NumericalMethod(
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

#endif /* !NUMERICALMETHOD_H */
