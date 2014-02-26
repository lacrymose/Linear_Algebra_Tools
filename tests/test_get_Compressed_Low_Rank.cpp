//
//  test_SVD_Low_Rank.cpp
//  
//
//  Created by Sivaram Ambikasaran on 2/25/14.
//
//

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <Eigen/Dense>
#include "get_Compressed_Low_Rank.hpp"

using namespace Eigen;

using std::cout;
using std::endl;

int main(int argc, char* argv[]) {
        int m           =       atoi(argv[1]);    //      Number of rows.
        int n           =       atoi(argv[2]);    //      Number of columns.
        int p           =       atoi(argv[3]);    //      Rank of the matrix.

        //      The matrix X*Y.
        double* X       =       new double[m*p];
        double* Y       =       new double[n*p];

        double RANDMAX  =       double(RAND_MAX);

        int count       =       0;
        for (int i=0; i<m; ++i) {
                for (int j=0; j<p; ++j) {
                        X[count]        =       rand()/RANDMAX;
                        ++count;
                }
        }

        count           =       0;
        for (int i=0; i<n; ++i) {
                for (int j=0; j<p; ++j) {
                        Y[count]        =       rand()/RANDMAX;
                        ++count;
                }
        }

        double tolerance=       1e-16;

        //      X*Y     =       U*S*V' + e
        double* U;
        double* S;
        double* V;

        //      'r' is the rank.
        int r;

        //      Obtains the compressed low-rank form, i.e., for a given tolerance outputs X*Y = U*S*V' + e
        get_Compressed_Low_Rank(X, Y, m, p, n, tolerance, U, S, V, r);

        MatrixXd X_E    =       MatrixXd::Random(m,p);
        MatrixXd Y_E    =       MatrixXd::Random(p,n);
        MatrixXd U_E, V_E;
        VectorXd S_E;
        get_Compressed_Low_Rank(X_E, Y_E, tolerance, U_E, S_E, V_E, r);
        cout << "Error is: " << (X_E*Y_E - U_E*S_E.asDiagonal()*V_E.transpose()).norm() << endl;
        cout << "Rank is: " << r << endl;
}