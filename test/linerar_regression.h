#ifndef LINEAR_REGRESSION_H
#define LINEAR_REGRESSION_H

#include <vector>

class LinearRegression {
public:
    LinearRegression();
    void fit(std::vector<double> x, std::vector<double> y);
    double predict(double x);
    double get_slope();
    double get_intercept();

private:
    double slope;
    double intercept;
};

#endif
