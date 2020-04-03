//
// Author :	Clément Legouest
// Date :	2020/04/02
//

#include <iostream>
#include <Eigen/Dense>
#include <fstream>

void displayAMatrix(Eigen::MatrixXd x, std::string name) {
    std::cout << "Matrice " << name << " : rows : " << x.rows() << ", columns : " << x.cols() << " : " << std::endl << x << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl;
}


// Return a random number between min and max
double getARandom(double min, double max) {
    return (rand() / (double)RAND_MAX) * (max - min) + min;
}


double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}