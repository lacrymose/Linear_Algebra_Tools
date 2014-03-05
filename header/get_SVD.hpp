//
//  get_SVD.hpp
//
//
//  Created by Sivaram Ambikasaran on 2/26/14.
//
//

#ifndef __get_SVD_hpp__
#define __get_SVD_hpp__

#include <Eigen/Dense>

/*!
 Obtains the SVD decomposition as A=USV', where all the matrices are in Eigen MatrixXd format.
 */
void get_SVD(const Eigen::MatrixXd A, const double tolerance, Eigen::MatrixXd& U, Eigen::VectorXd& S, Eigen::MatrixXd& V, int& rank) {
        Eigen::JacobiSVD<Eigen::MatrixXd> svd(A, Eigen::ComputeThinU | Eigen::ComputeThinV);
        rank    =       0;
        S       =       svd.singularValues();
        while (rank < S.size() && S(rank)>tolerance) {
                ++rank;
        }
        U       =       svd.matrixU().block(0,0,A.rows(),rank);
        V       =       svd.matrixV().block(0,0,A.cols(),rank);
        S       =       S.segment(0,rank);
}

#endif /* defined(__get_SVD_hpp__) */