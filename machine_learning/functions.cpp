//
// Author :	Clément Legouest
// Date :	2020/04/02
//

#include <iostream>
#include <Eigen/Dense>


// Return a random number between min and max
double getARand(double min, double max) {
    return (rand() / (double)RAND_MAX) * (max - min) + min;
}


// Return a matrix that is the W of two matrixes
Eigen::MatrixXd W(Eigen::MatrixXd x, Eigen::MatrixXd y) {
    
    Eigen::MatrixXd tmp(x.rows(), 1);
    for (int i = 0; i < x.rows(); i++) {
        tmp(i, 0) = 1;
    }

    Eigen::MatrixXd tmp2(x.rows(), x.cols() + 1);
    tmp2 << x, tmp;
    x = tmp2;

    std::cout << "Matrix x with the additional column of ones : " << std::endl << x << std::endl;

    Eigen::MatrixXd transposedX = x.transpose();

    Eigen::MatrixXd result = (((transposedX * x).inverse()) * transposedX) * y;

    return result;
}


// Return a matrix that is the W of two matrixes with the iterrative method
Eigen::MatrixXd iterrative_W(Eigen::MatrixXd x, Eigen::MatrixXd y, double alpha, ) {
    Eigen::MatrixXd w(2, 2);

    // TODO : Put some code

    return w;
}