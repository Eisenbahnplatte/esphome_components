#include "./linear_regression.h"
#include <iostream>

int main() {
    std::vector<double> x = {1.0, 2.0, 3.0, 4.0, 5.0};
    std::vector<double> y = {2.0, 4.0, 5.5, 7.5, 8.0};

    LinearRegression lr;
    lr.fit(x, y);

    std::cout << "Slope: " << lr.get_slope() << std::endl;
    std::cout << "Intercept: " << lr.get_intercept() << std::endl;

    double x_new = 6.0;
    double y_pred = lr.predict(x_new);
    std::cout << "Predicted value for x=" << x_new << ": " << y_pred << std::endl;

    return 0;
}