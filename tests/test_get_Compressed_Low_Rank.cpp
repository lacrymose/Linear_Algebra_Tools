//
//  test_get_Compressed_Low_Rank.cpp
//  
//
//  Created by Sivaram Ambikasaran on 2/25/14.
//
//

#include "get_Compressed_Low_Rank.hpp"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <Eigen/Dense>

int main(int argc, char* argv[]) {
        srand(time(NULL));
        int m           =       atoi(argv[1]);    //      Number of rows.
        int n           =       atoi(argv[2]);    //      Number of columns.
        int p           =       atoi(argv[3]);    //      Rank of the matrix.

        Eigen::MatrixXd X       =       Eigen::MatrixXd::Random(m,p);
        Eigen::MatrixXd Y       =       Eigen::MatrixXd::Random(p,n);
        Eigen::MatrixXd Z       =       Eigen::MatrixXd::Random(p,p);

        double tolerance=       1e-12;

        Eigen::MatrixXd U;
        Eigen::VectorXd S;
        Eigen::MatrixXd V;

        int rank;

        get_Compressed_Low_Rank(X, Y, tolerance, U, S, V, rank);

        std::cout << (X*Y-U*S.asDiagonal()*V.transpose()).cwiseAbs().maxCoeff() << std::endl;

        get_Compressed_Low_Rank(X, Z, Y, tolerance, U, S, V, rank);

        std::cout << (X*Z*Y-U*S.asDiagonal()*V.transpose()).cwiseAbs().maxCoeff() << std::endl;
}