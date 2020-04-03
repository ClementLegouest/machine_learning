//
// Author :	Clément Legouest
// Date :	2020/04/02
//

#include <iostream>
#include <Eigen/Dense>
#include <fstream>
#include <cmath>

void displayAMatrix(Eigen::MatrixXd x, std::string name) {
    std::cout << "Matrice " << name << " : rows : " << x.rows() << ", columns : " << x.cols() << " : " << std::endl << x << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
}


// Return a random number between min and max
double getARandom(double min, double max) {
    return (rand() / (double)RAND_MAX) * (max - min) + min;
}


double sigmoid(double x) {
    return 1.0 / (1.0 + _CMATH_::exp(-x));
}


Eigen::MatrixXd matrixColSigmoid(Eigen::MatrixXd matrixX, int col) {

    if (col >= matrixX.cols()) {
        std::cerr << "index plus grand que le nombre de colonnes" << std::endl;
        exit(1);
    }

    if (col < 0) {
        std::cerr << "index plus petit que 0" << std::endl;
        exit(1);
    }

    Eigen::MatrixXd result = matrixX;

    for (int i = 0; i < result.rows(); i++) {
        result(i, 0) = sigmoid(result(i, 0));
    }

    return result;
}

Eigen::MatrixXd matrixColLog(Eigen::MatrixXd matrixX, int col) {

    if (col >= matrixX.cols()) {
        std::cerr << "index plus grand que le nombre de colonnes" << std::endl;
        exit(1);
    }

    if (col < 0) {
        std::cerr << "index plus petit que 0" << std::endl;
        exit(1);
    }

    Eigen::MatrixXd result = matrixX;

    for (int i = 0; i < result.rows(); i++) {
        result(i, 0) = _CMATH_::log(result(i, 0));
    }

    return result;
}