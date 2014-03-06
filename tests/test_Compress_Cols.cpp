//
//  test_Compress_Cols.cpp
//  
//
//  Created by Sivaram Ambikasaran on 3/5/14.
//
//

#include "Compress_Cols.hpp"
#include <iostream>
#include <Eigen/Dense>

int main() {
        int m   =       40;
        int n   =       20;
        
        Eigen::MatrixXd A       =       Eigen::MatrixXd(m,n);
        Eigen::MatrixXd B       =       Eigen::MatrixXd(m,n);
        
        double tolerance        =       1e-14;
        
        Eigen::MatrixXd U, V1, V2;
        Eigen::VectorXd S;

        int rank;

        Compress_Cols(A, B, tolerance, U, S, V1, V2, rank);
        std::cout << (A-U*S.asDiagonal()*V1.transpose()).cwiseAbs().maxCoeff() << std::endl;
        std::cout << (B-U*S.asDiagonal()*V2.transpose()).cwiseAbs().maxCoeff() << std::endl;
}