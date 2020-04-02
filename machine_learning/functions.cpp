//
// Author :	Clément Legouest
// Date :	2020/04/02
//

#include <iostream>
#include <Eigen/Dense>
#include <fstream>
#include "utils.h"


// Return a random number between min and max
double getARandom(double min, double max) {
    return (rand() / (double)RAND_MAX) * (max - min) + min;
}


// Add a column of number at the end
Eigen::MatrixXd addAColOfNumber(Eigen::MatrixXd matrix, double number) {
    Eigen::MatrixXd tmp(matrix.rows(), 1);
    for (int i = 0; i < matrix.rows(); i++) {
        tmp(i, 0) = number;
    }

    Eigen::MatrixXd tmp2(matrix.rows(), matrix.cols() + 1);
    tmp2 << matrix, tmp;
    matrix = tmp2;

    return matrix;
}


// Return a matrix that is the W of two matrixes
Eigen::MatrixXd W(Eigen::MatrixXd x, Eigen::MatrixXd y) {

    x = addAColOfNumber(x, 1.0);

    Eigen::MatrixXd transposedX = x.transpose();

    Eigen::MatrixXd result = (((transposedX * x).inverse()) * transposedX) * y;

    return result;
}


Eigen::MatrixXd g(Eigen::MatrixXd x, Eigen::MatrixXd y) {
    return x * y;
}


// Return a matrix that is the W of two matrixes with the iterrative method
void iterrative_W(Eigen::MatrixXd x, Eigen::MatrixXd y, double alpha, int k) {
    Eigen::MatrixXd w(2, 2);

    // TODO : Put some code
    // w = w - alpha * (-2.0 / x.rows()) * x.transpose() * (y - g(x, y));

    x = addAColOfNumber(x, 1.0);

    std::cout << "x.rows() : " << x.rows() << " and y.rows() : " << y.rows() << std::endl;

    if (k < 1 || k > x.rows()) {
        std::cerr << "Selection en dehors de x" << std::endl;
        exit(1);
    }

    if (k < 1 || k > y.rows()) {
        std::cerr << "Selection en dehors de y" << std::endl;
        exit(1);
    }

    Eigen::MatrixXd result(x.rows(), 1);

    std::cout << "x.row(k) : " << x.row(k) << " y.row(k) : " << y.row(k) << std::endl;
}