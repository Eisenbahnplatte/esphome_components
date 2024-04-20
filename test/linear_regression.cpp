#include "./linerar_regression.h"
#include <numeric>

LinearRegression::LinearRegression() {}

void LinearRegression::fit(std::vector<double> x, std::vector<double> y) {
    size_t n = x.size();
    double sum_x = std::accumulate(x.begin(), x.end(), 0.0);
    double sum_y = std::accumulate(y.begin(), y.end(), 0.0);
    double mean_x = sum_x / n;
    double mean_y = sum_y / n;

    double numerator = 0.0;
    double denominator = 0.0;
    for (size_t i = 0; i < n; ++i) {
        numerator += (x[i] - mean_x) * (y[i] - mean_y);
        denominator += (x[i] - mean_x) * (x[i] - mean_x);
    }

    slope = numerator / denominator;
    intercept = mean_y - slope * mean_x;
}

double LinearRegression::predict(double x) {
    return slope * x + intercept;
}

double LinearRegression::get_slope() {
    return slope;
}

double LinearRegression::get_intercept() {
    return intercept;
}
