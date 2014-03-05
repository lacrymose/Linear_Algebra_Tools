//
//  get_Compressed_Low_Rank.hpp
//
//
//  Created by Sivaram Ambikasaran on 2/25/14.
//
//

#ifndef __get_Compressed_Low_Rank_hpp__
#define __get_Compressed_Low_Rank_hpp__

#include "get_QR.hpp"
#include "get_SVD.hpp"
#include <Eigen/Dense>

/*!
 Given a matrix in low-rank form obtains its SVD, i.e., XY^T = USV^T, where the matrices are stored using Eigen's MatrixXd.
 */
void get_Compressed_Low_Rank(const Eigen::MatrixXd X, const Eigen::MatrixXd Y, const double tolerance, Eigen::MatrixXd& U, Eigen::VectorXd& S, Eigen::MatrixXd& V, int& r) {
        //      Obtains QR of the matrix X.
        Eigen::MatrixXd Q_X, R_X;
        get_QR(X, Q_X, R_X);                                    //      X = Q_X R_X.

        //      Obtains QR of the matrix Y.
        Eigen::MatrixXd Q_Y, R_Y;
        get_QR(Y.transpose(), Q_Y, R_Y);                        //      Y = Q_Y R_Y.

        //      Obtains SVD of RX*RY^T.
        get_SVD(R_X*R_Y.transpose(), tolerance, U, S, V, r);    //      R_X R_Y^T = U S V^T.

        //      Obtains the row and column basis U and V.
        U       =       Q_X*U;
        V       =       Q_Y*V;
}

/*!
 Given a matrix in low-rank form obtains its SVD, i.e., XZY^T = USV^T, where the matrices are stored using Eigen's MatrixXd.
 */
void get_Compressed_Low_Rank(const Eigen::MatrixXd X, const Eigen::MatrixXd Z, const Eigen::MatrixXd Y, const double tolerance, Eigen::MatrixXd& U, Eigen::VectorXd& S, Eigen::MatrixXd& V, int& r) {
        //      Obtains QR of the matrix X.
        Eigen::MatrixXd Q_X, R_X;
        get_QR(X, Q_X, R_X);                                    //      X = Q_X R_X.

        //      Obtains QR of the matrix Y.
        Eigen::MatrixXd Q_Y, R_Y;
        get_QR(Y.transpose(), Q_Y, R_Y);                        //      Y = Q_Y R_Y.

        //      Obtains SVD of RX*RY^T.
        get_SVD(R_X*Z*R_Y.transpose(), tolerance, U, S, V, r);  //      R_X Z R_Y^T = U S V^T.

        //      Obtains the row and column basis U and V.
        U       =       Q_X*U;
        V       =       Q_Y*V;
}

#endif /* defined(__get_Compressed_Low_Rank__) */