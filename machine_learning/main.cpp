#include <iostream>
#include <Eigen/Dense>

#include "functions.h"

int main(int argc, char *argv[]) {
	
	// Hardcoded matrix to remove for final version
	Eigen::MatrixXd x(8, 4);
	Eigen::MatrixXd y(8, 1);

	x << 160, 1, 0, 0, 190, 1, 0, 0, 185, 0, 0, 1, 177, 0, 0, 1,
		187, 0, 0, 1, 185, 1, 0, 0, 166, 0, 0, 1, 177, 0, 1, 0;
	y << 24, 22, 23, 25, 23, 26, 25, 32;
	// End of hardcoded matrix to remove for final version

	std::cout << "Matrice x : " << std::endl << x << std::endl;
	std::cout << "Matrice y : " << std::endl << y << std::endl;
	std::cout << "w(x, y) : " << std::endl << W(x, y) << std::endl;

	std::cin.get();
}