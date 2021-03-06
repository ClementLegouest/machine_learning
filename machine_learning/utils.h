//
// Author :	Cl�ment Legouest
// Date :	2020/04/02
//

#pragma once

#include <Eigen/Dense>

void displayAMatrix(Eigen::MatrixXd x, std::string name);

double getARandom(double min, double max);

double sigmoid(double x);

Eigen::MatrixXd matrixColSigmoid(Eigen::MatrixXd matrixX, int col);

Eigen::MatrixXd matrixColLog(Eigen::MatrixXd matrixX, int col);

Eigen::MatrixXd matrixColMinusOne(Eigen::MatrixXd matrixX, int col);