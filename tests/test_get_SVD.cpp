//
//  get_SVD.cpp
//
//
//  Created by Sivaram Ambikasaran on 2/26/14.
//
//

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <Eigen/Dense>
#include "get_SVD.hpp"

using std::cout;
using std::endl;
using namespace Eigen;

int main(int argc, char* argv[]) {
        srand(time(NULL));

        int m   =       atoi(argv[1]);
        int n   =       atoi(argv[2]);

//      Check the double version.
        double* A       =       new double[m*n];
        double* U;
        double* S;
        double* V;

        double RANDMAX  =       double(RAND_MAX);
//      Initialize A as a random matrix.
        for (int index=0; index<m*n; ++index) {
                A[index]        =       rand()/RANDMAX;
        }

        double tolerance=       1e-12;

        int rank;

        get_SVD(A, m, n, tolerance, U, S, V, rank);

//      Check the MatrixXd version.
        MatrixXd A_E    =       MatrixXd::Random(m,n);
        MatrixXd U_E, V_E;
        VectorXd S_E;
        get_SVD(A_E, tolerance, U_E, S_E, V_E, rank);
        cout << "Error is: " << (A_E-U_E*S_E.asDiagonal()*V_E.transpose()).norm() << endl;
        cout << "Rank is: " << rank << endl;
}