//
//  get_SVD.cpp
//
//
//  Created by Sivaram Ambikasaran on 2/26/14.
//
//

#include "get_SVD.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <Eigen/Dense>

int main(int argc, char* argv[]) {
        srand(time(NULL));

        int m   =       atoi(argv[1]);
        int n   =       atoi(argv[2]);

        Eigen::MatrixXd A       =       Eigen::MatrixXd::Random(m,n);
        Eigen::MatrixXd U, V;
        Eigen::VectorXd S;
        int rank;
        double tolerance        =       1e-10;
        get_SVD(A, tolerance, U, S, V, rank);
        std::cout << (A-U*S.asDiagonal()*V.transpose()).cwiseAbs().maxCoeff() << std::endl;
}