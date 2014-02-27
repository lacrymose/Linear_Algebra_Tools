//
//  get_Pseudo_Inverse.cpp
//
//
//  Created by Sivaram Ambikasaran on 2/26/14.
//
//

#include "get_Pseudo_Inverse.hpp"
#include "get_SVD.hpp"

using namespace Eigen;

/*!
 Obtains the pseudo inverse of a matrix, where the matrices are stored using Eigen's MatrixXd.
 */
void get_Pseudo_Inverse(MatrixXd A, double tolerance, MatrixXd& Apinv) {
        MatrixXd U, V;
        VectorXd S;
        int r;
        get_SVD(A, tolerance, U, S, V, r);
        for (int k=0; k<r; ++k) {
                S(k)    =       1.0/S(k);
        }
        Apinv   =       V*S.asDiagonal()*U.transpose();
}

/*!
 Obtains the pseudo inverse of a matrix, where the matrices are stored using double*.
 */
void get_Pseudo_Inverse(double* A, int m, int n, double tolerance, double*& Apinv) {
        //      Maps the double to MatrixXd.
        Map<Matrix<double,Dynamic,Dynamic,ColMajor> >  A_E(A, m, n);

        //      Obtains the pseudo inverse.
        MatrixXd Apinv_E;
        get_Pseudo_Inverse(A_E, tolerance, Apinv_E);

        //      Maps the MatrixXd to double.
        Apinv   =       Apinv_E.data();
}