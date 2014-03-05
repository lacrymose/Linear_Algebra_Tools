//
//  get_Pseudo_Inverse.hpp
//
//
//  Created by Sivaram Ambikasaran on 2/26/14.
//
//

#ifndef __get_Pseudo_Inverse_hpp__
#define __get_Pseudo_Inverse_hpp__

#include "get_SVD.hpp"
#include <Eigen/Dense>

/*!
 Obtains the pseudo inverse of a matrix.
 */
void get_Pseudo_Inverse(const Eigen::MatrixXd A, const double tolerance, Eigen::MatrixXd& Apinv) {
        Eigen::MatrixXd U, V;
        Eigen::VectorXd S;
        int r;
        get_SVD(A, tolerance, U, S, V, r);
        for (int k=0; k<r; ++k) {
                S(k)    =       1.0/S(k);
        }
        Apinv   =       V*S.asDiagonal()*U.transpose();
}

#endif /* (__get_Pseudo_Inverse_hpp__) */