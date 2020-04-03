//
// Author :	Clément Legouest
// Date :	2020/04/02
//

#include <iostream>
#include <Eigen/Dense>
#include <fstream>
#include <cmath>
#include "utils.h"


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
Eigen::MatrixXd W(Eigen::MatrixXd matrixX, Eigen::MatrixXd matrixY) {

    matrixX = addAColOfNumber(matrixX, 1.0);

    Eigen::MatrixXd transposedMatrixX = matrixX.transpose();

    Eigen::MatrixXd matrixResult = (((transposedMatrixX * matrixX).inverse()) * transposedMatrixX) * matrixY;

    return matrixResult;
}


Eigen::MatrixXd g(Eigen::MatrixXd matrixX, Eigen::MatrixXd matrixW) {
    
    Eigen::MatrixXd result = matrixX * matrixW;

    for (int i = 0; i < result.rows(); i++) {
        result(i, 0) = sigmoid(result(i, 0));
    }

    return result;
}


// Return a matrix that is the W of two matrixes with the iterrative method
Eigen::MatrixXd iterrative_W(Eigen::MatrixXd matrixX,
                             Eigen::MatrixXd matrixY,
                             Eigen::MatrixXd matrixW, 
                             double alpha,
                             int k) {

    Eigen::MatrixXd w(2, 2);

    matrixX = addAColOfNumber(matrixX, 1.0);

    std::cout << "x.rows() : " << matrixX.rows() << " and y.rows() : " << matrixY.rows() << std::endl;

    if (matrixX.rows() != matrixY.rows()) {
        std::cerr << "MatrixX and matrixY" << std::endl;
        exit(1);
    }

    if (k < 1 || k > matrixX.rows()) {
        std::cerr << "Selection en dehors de x" << std::endl;
        exit(1);
    }

    if (k < 1 || k > matrixY.rows()) {
        std::cerr << "Selection en dehors de y" << std::endl;
        exit(1);
    }
    
    // Version régression linéaire
    // return matrixW + alpha * (-2.0 / matrixX.rows()) * matrixX.transpose() * (matrixY - g(matrixX, matrixW));

    // sigmoide
    return matrixW + alpha * (-2.0 / matrixX.rows()) * matrixX.transpose() * (matrixY - g(matrixX, matrixW));

}