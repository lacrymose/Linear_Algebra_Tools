//
//  test_get_Log_Determinant.cpp
//  
//
//  Created by Sivaram Ambikasaran on 3/4/14.
//
//

#include "get_Log_Determinant.hpp"
#include <iostream>
#include <Eigen/Dense>

int main() {
        int N                   =       10;
        Eigen::MatrixXd A       =       Eigen::MatrixXd::Random(N,N);
        double detc             =       get_Log_Determinant(A);
        double det              =       log(fabs(A.determinant()));
        std::cout << fabs(detc-det) << std::endl;
}