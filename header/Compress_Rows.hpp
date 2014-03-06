//
//  Compress_Rows.hpp
//
//
//  Created by Sivaram Ambikasaran on 3/5/14.
//
//

#ifndef __Compress_Rows_hpp__
#define __Compress_Rows_hpp__

#include "get_SVD.hpp"
#include <Eigen/Dense>

/*!
 Obtains the common row basis, i.e.,
  _   _          _         _
 |     |        |           |
 |  A  |        |  U1 S V^T |
 |     |  =     |           |
 |  B  |        |  U2 S V^T |
 |_   _|        |_         _|

 */
void Compress_Rows(const Eigen::MatrixXd A, const Eigen::MatrixXd B, const double tolerance, Eigen::MatrixXd& U1, Eigen::MatrixXd& U2, Eigen::VectorXd& S, Eigen::MatrixXd& V, int& rank) {
        Eigen::MatrixXd C, U;
        C.resize(A.rows()+B.rows(), A.cols());
        C << A, B;

        get_SVD(C, tolerance, U, S, V, rank);
        U1      =       U.block(0,0,A.rows(),rank);
        U2      =       U.block(A.rows(),0,B.rows(),rank);
}

#endif /* (defined __Compress_Rows_hpp__)*/