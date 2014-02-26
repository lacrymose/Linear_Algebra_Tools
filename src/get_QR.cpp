//
//  get_QR.cpp
//
//
//  Created by Sivaram Ambikasaran on 2/26/14.
//
//

#include "get_QR.hpp"

/*!
 Obtains the QR decomposition as A=QR, where all the matrices are in Eigen MatrixXd format.
 */
void get_QR(MatrixXd A, MatrixXd& Q, MatrixXd& R) {
        HouseholderQR<MatrixXd> qr(A);
        Q  =   qr.householderQ()*(MatrixXd::Identity(A.rows(),A.cols()));
        R  =   qr.matrixQR().block(0,0,A.cols(),A.cols()).triangularView<Upper>();
}

/*!
 Obtains the QR decomposition as A=QR, where all the matrices are in double format.
 */
void get_QR(double* A, int m, int n, double*& Q, double*& R) {
        //      Maps the double to MatrixXd.
        Map<Matrix<double,Dynamic,Dynamic,ColMajor> >  A_E(A, m, n);

        //      Obtains the QR of A_E.
        MatrixXd Q_E, R_E;
        get_QR(A_E, Q_E, R_E);

        //      Maps the MatrixXd to double.
        Q       =       Q_E.data();
        R       =       R_E.data();
}