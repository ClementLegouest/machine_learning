//
// Author :	Clément Legouest
// Date :	2020/04/02
//

#pragma once

#include <Eigen/Dense>

double getARandom(double min, double max);

Eigen::MatrixXd addAColOfNumber(Eigen::MatrixXd x, double number);

Eigen::MatrixXd W(Eigen::MatrixXd x, Eigen::MatrixXd y);

void iterrative_W(Eigen::MatrixXd x, Eigen::MatrixXd y, double alpha, int k);