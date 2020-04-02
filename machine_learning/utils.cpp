//
// Author :	Clément Legouest
// Date :	2020/04/02
//

#include <iostream>
#include <Eigen/Dense>
#include <fstream>

void displayAMatrix(Eigen::MatrixXd x, std::string name) {
    std::cout << "Matrice " << name << " : rows : " << x.rows() << ", columns : " << x.cols() << " : " << std::endl << x << std::endl;
}