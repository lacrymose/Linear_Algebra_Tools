//
//  get_QR.cpp
//
//
//  Created by Sivaram Ambikasaran on 2/26/14.
//
//

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <Eigen/Dense>
#include "get_QR.hpp"

using std::cout;
using std::endl;
using namespace Eigen;

int main(int argc, char* argv[]) {
        srand(time(NULL));

        int m   =       atoi(argv[1]);
        int n   =       atoi(argv[2]);

//      Check the double version.
        double* A       =       new double[m*n];
        double* Q;
        double* R;

        double RANDMAX  =       double(RAND_MAX);
        //      Initialize A as a random matrix.
        for (int index=0; index<m*n; ++index) {
                A[index]        =       rand()/RANDMAX;
        }

        get_QR(A, m, n, Q, R);

//      Check the MatrixXd version.
        MatrixXd A_E    =       MatrixXd::Random(m,n);
        MatrixXd Q_E, R_E;
        get_QR(A_E, Q_E, R_E);
        cout << "Error is: " << (A_E-Q_E*R_E).norm() << endl;
}