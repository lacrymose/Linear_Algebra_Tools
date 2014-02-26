//
//  get_Compressed_Low_Rank.hpp
//  
//
//  Created by Sivaram Ambikasaran on 2/25/14.
//
//

#ifndef __get_Compressed_Low_Rank__
#define __get_Compressed_Low_Rank__

#include "get_Compressed_Low_Rank.hpp"
#include "get_QR.hpp"
#include "get_SVD.hpp"

/*!
 Given a matrix in low-rank form obtains its SVD, i.e., XY^T = USV^T, where the matrices are stored using Eigen's MatrixXd.
 */
void get_Compressed_Low_Rank(MatrixXd X, MatrixXd Y, double tolerance, MatrixXd& U, VectorXd& S, MatrixXd& V, int& r) {
        //      Obtains QR of the matrix X.
        MatrixXd Q_X, R_X;
        get_QR(X, Q_X, R_X);                    //      X = Q_X R_X.

        //      Obtains QR of the matrix Y.
        MatrixXd Q_Y, R_Y;
        get_QR(Y.transpose(), Q_Y, R_Y);        //      Y = Q_Y R_Y.

        //      Obtains SVD of RX*RY^T.
        get_SVD(R_X*R_Y.transpose(), tolerance, U, S, V, r);    //      R_X R_Y^T = U S V^T.

        //      Obtains the row and column basis U and V.
        U       =       Q_X*U;
        V       =       Q_Y*V;
}

/*!
 Given a matrix in low-rank form obtains its SVD, i.e., XY^T = USV^T, where the matrices are stored in columnformat using double*.
 */
void get_Compressed_Low_Rank(double* X, double* Y, int m, int p, int n, double tolerance, double*& U, double*& S, double*& V, int& r) {
        //      Map the matrix from double format to MatrixXd format.
        Map<Matrix<double,Dynamic,Dynamic,ColMajor> >  X_E(X, m, p);
        Map<Matrix<double,Dynamic,Dynamic,ColMajor> >  Y_E(X, p, n);

        MatrixXd U_E, V_E;
        VectorXd S_E;

//        get_Compressed_Low_Rank(X_E, Y_E, tolerance, U_E, S_E, V_E, r);
        
        //      Maps the matrix back onto double.
        U       =       U_E.data();
        S       =       S_E.data();
        V       =       V_E.data();
}

#endif /* defined(__get_Compressed_Low_Rank__) */