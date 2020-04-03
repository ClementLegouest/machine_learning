//
// Author :	Clément Legouest
// Date :	2020/04/02
//

#include <iostream>
#include <Eigen/Dense>

#include "functions.h"
#include "utils.h"

int main(int argc, char *argv[]) {
	
	/*
	// Hardcoded matrix to remove for final version
	Eigen::MatrixXd x(8, 4);
	Eigen::MatrixXd y(8, 1);

	x << 160, 1, 0, 0, 190, 1, 0, 0, 185, 0, 0, 1, 177, 0, 0, 1,
		187, 0, 0, 1, 185, 1, 0, 0, 166, 0, 0, 1, 177, 0, 1, 0;
	y << 24, 22, 23, 25, 23, 26, 25, 32;
	// End of hardcoded matrix to remove for final version
	*/

	// Hardcoded matrix to remove for final version
	Eigen::MatrixXd matrixX(300, 1);
	Eigen::MatrixXd matrixY(300, 1);

	for (int i = 0; i < matrixX.cols(); i++) {
		matrixX(i, 0) = i + 1;
		matrixY(i, 0) = getARandom(0.00, 1.00);
	}
	// End of hardcoded matrix to remove for final version

	displayAMatrix(matrixX, "x");
	displayAMatrix(matrixY, "y");
	displayAMatrix(W(matrixX, matrixY), "w(x, y)");
	displayAMatrix(iterrative_W(10000, matrixX, matrixY, 0.01, 1), "iterrative_W");
	// displayAMatrix(W(x, y) - iterrative_W(2000, x, y, 0.01, 1), "différence W - Iterrative_W");

	std::cin.get();
}