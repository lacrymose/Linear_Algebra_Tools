//
//  test_get_Pseudo_Inverse.cpp
//
//
//  Created by Sivaram Ambikasaran on 2/25/14.
//
//

#include "get_Pseudo_Inverse.hpp"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <Eigen/Dense>

int main(int argc, char* argv[]) {
        int m                   =       atoi(argv[1]);    //      Number of rows.
        int n                   =       atoi(argv[2]);    //      Number of columns.

        srand(time(NULL));
        Eigen::MatrixXd A       =       Eigen::MatrixXd::Random(m,n);
        double tolerance        =       1e-15;
        Eigen::MatrixXd Apinv;
        get_Pseudo_Inverse(A, tolerance, Apinv);

        int minmn               =       std::min(m,n);

        Eigen::MatrixXd I       =       Eigen::MatrixXd::Identity(minmn, minmn);

        if (m<n) {
                std::cout << (A*Apinv-I).cwiseAbs().maxCoeff() << std::endl;
        }
        else {
                std::cout << (Apinv*A-I).cwiseAbs().maxCoeff() << std::endl;
        }
}