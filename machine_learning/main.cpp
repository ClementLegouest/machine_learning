//
// Author :	Cl�ment Legouest
// Date :	2020/04/02
//

#include <iostream>
#include <Eigen/Dense>

#include "functions.h"
#include "utils.h"

int main(int argc, char *argv[]) {
	
	// Hardcoded matrix to remove for final version
	Eigen::MatrixXd x(8, 4);
	Eigen::MatrixXd y(8, 1);

	x << 160, 1, 0, 0, 190, 1, 0, 0, 185, 0, 0, 1, 177, 0, 0, 1,
		187, 0, 0, 1, 185, 1, 0, 0, 166, 0, 0, 1, 177, 0, 1, 0;
	y << 24, 22, 23, 25, 23, 26, 25, 32;
	// End of hardcoded matrix to remove for final version

	displayAMatrix(x, "x");
	displayAMatrix(y, "y");
	displayAMatrix(W(x, y), "w(x, y)");
	displayAMatrix(iterrative_W(10000, x, y, 0.01, 1), "iterrative_W");
	// displayAMatrix(W(x, y) - iterrative_W(2000, x, y, 0.01, 1), "diff�rence W - Iterrative_W");

	std::cin.get();
}