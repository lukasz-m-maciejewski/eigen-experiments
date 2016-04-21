#include <iostream>
#include <Eigen/Dense>

using Eigen::MatrixXd;

int main()
{
    MatrixXd x(4, 2);
    for (const auto i : {0, 1, 2, 3})
    {
        x(i, 0) = 1;
    }
    x(0, 1) = 1;
    x(1, 1) = 2;
    x(2, 1) = 3;
    x(3, 1) = 4;

    MatrixXd b(4, 1);
    b(0, 0) = 6;
    b(1, 0) = 5;
    b(2, 0) = 7;
    b(3, 0) = 10;

    std::cout << x.transpose() * x  << std::endl;
    std::cout << x.transpose() * b << std::endl;
    auto toInvert = (x.transpose() * x);
    std::cout << "result: " << toInvert.inverse() * x.transpose() * b << std::endl;
}
