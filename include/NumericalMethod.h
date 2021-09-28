#ifndef NUMERICALMETHOD_H
#define NUMERICALMETHOD_H

class NumericalMethod
{
public:
    virtual double calculate(
            double x_prev, 
            double y_prev,
            double step_size, 
            std::function<double(double, double)> f_der
            ) = 0;
};

class EulerMethod : public NumericalMethod
{
public:
    double calculate(
            double x_prev, 
            double y_prev,
            double step_size, 
            std::function<double(double, double)> f_der
            )
    {
        return y_prev + step_size * f_der(x_prev, y_prev);
    }
};

class ImprovedEulerMethod : public NumericalMethod
{
public:
    double calculate(
            double x_prev, 
            double y_prev,
            double step_size, 
            std::function<double(double, double)> f_der
            )
    {
        double k1 = step_size * f_der(x_prev, y_prev);
        double k2 = step_size * f_der(x_prev + step_size, y_prev + k1);
        return y_prev + (k1 + k2) / 2;
    }
};

class RungeKuttaMethod : public NumericalMethod
{
public:
    double calculate(
            double x_prev, 
            double y_prev,
            double step_size, 
            std::function<double(double, double)> f_der
            )
    {
        double k1 = step_size * f_der(x_prev, y_prev);
        double k2 = step_size * f_der(x_prev + step_size / 2, y_prev + k1 / 2);
        double k3 = step_size * f_der(x_prev + step_size / 2, y_prev + k2 / 2);
        double k4 = step_size * f_der(x_prev + step_size, y_prev + k3);

        return y_prev + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
    }
};

#endif /* !NUMERICALMETHOD_H */
