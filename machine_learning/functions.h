//
// Author :	Clément Legouest
// Date :	2020/04/02
//

#pragma once

#include <Eigen/Dense>

Eigen::MatrixXd addAColOfNumber(Eigen::MatrixXd x, double number);

Eigen::MatrixXd W(Eigen::MatrixXd x, Eigen::MatrixXd y);

Eigen::MatrixXd g(Eigen::MatrixXd matrixX, Eigen::MatrixXd matrixW);

Eigen::MatrixXd iterrative_W(int steps,
                             Eigen::MatrixXd matrixX,
                             Eigen::MatrixXd matrixY,
                             double alpha,
                             int k);