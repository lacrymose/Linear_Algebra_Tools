//
//  test_Compress_Rows.cpp
//
//
//  Created by Sivaram Ambikasaran on 3/5/14.
//
//

#include "Compress_Rows.hpp"
#include <iostream>
#include <Eigen/Dense>

int main() {
        int m   =       20;
        int n   =       40;

        Eigen::MatrixXd A       =       Eigen::MatrixXd(m,n);
        Eigen::MatrixXd B       =       Eigen::MatrixXd(m,n);

        double tolerance        =       1e-14;

        Eigen::MatrixXd U1, U2, V;
        Eigen::VectorXd S;

        int rank;

        Compress_Rows(A, B, tolerance, U1, U2, S, V, rank);
        std::cout << (A-U1*S.asDiagonal()*V.transpose()).cwiseAbs().maxCoeff() << std::endl;
        std::cout << (B-U2*S.asDiagonal()*V.transpose()).cwiseAbs().maxCoeff() << std::endl;
}