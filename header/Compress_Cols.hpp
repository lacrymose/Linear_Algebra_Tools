//
//  Compress_Cols.hpp
//  
//
//  Created by Sivaram Ambikasaran on 3/5/14.
//
//

#ifndef __Compress_Cols_hpp__
#define __Compress_Cols_hpp__

#include "get_SVD.hpp"
#include <Eigen/Dense>

/*!
 Obtains the common column basis, i.e.,
  _    _                 _                  _
 |      |               |                    |
 | A, B |       =       | U S V1^T, U S V2^T |
 |_    _|               |_                  _|

 */
void Compress_Cols(const Eigen::MatrixXd A, const Eigen::MatrixXd B, const double tolerance, Eigen::MatrixXd& U, Eigen::VectorXd& S, Eigen::MatrixXd& V1, Eigen::MatrixXd& V2, int& rank) {
        Eigen::MatrixXd C, V;
        C.resize(A.rows(), A.cols()+B.cols());
        C << A, B;

        get_SVD(C, tolerance, U, S, V, rank);
        V1      =       V.block(0,0,A.cols(),rank);
        V2      =       V.block(A.cols(),0,B.cols(),rank);
}

#endif /* (defined __Compress_Cols_hpp__)*/