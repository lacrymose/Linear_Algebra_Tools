//
//  get_QR.hpp
//
//
//  Created by Sivaram Ambikasaran on 2/26/14.
//
//

#ifndef __get_QR_hpp__
#define __get_QR_hpp__

#include <Eigen/Dense>
#include <cstdlib>
#include <algorithm>

/*!
 Obtains the QR decomposition as A=QR.
 */
void get_QR(Eigen::MatrixXd A, Eigen::MatrixXd& Q, Eigen::MatrixXd& R) {
        int m           =       A.rows();
        int n           =       A.cols();
        int minmn       =       std::min(m,n);

        Eigen::HouseholderQR<Eigen::MatrixXd> qr(A);
        Q = qr.householderQ()*(Eigen::MatrixXd::Identity(m,minmn));
        R = qr.matrixQR().block(0,0,minmn,n).triangularView<Eigen::Upper>();
}

#endif /* defined(__get_QR_hpp__) */