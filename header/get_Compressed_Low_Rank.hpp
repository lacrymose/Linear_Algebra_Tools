//
//  get_Compressed_Low_Rank.hpp
//  
//
//  Created by Sivaram Ambikasaran on 2/25/14.
//
//

#ifndef __get_Compressed_Low_Rank__
#define __get_Compressed_Low_Rank__

#include <Eigen/Dense>

using namespace Eigen;

/*!
 Given a matrix in low-rank form obtains its SVD, i.e., XY^T = USV^T, where the matrices are stored using Eigen's MatrixXd.
 */
void get_Compressed_Low_Rank(MatrixXd X, MatrixXd Y, double tolerance, MatrixXd& U, VectorXd& S, MatrixXd& V, int& r);

/*!
 Given a matrix in low-rank form obtains its SVD, i.e., XY^T = USV^T, where the matrices are stored in column format using double*.
 */
void get_Compressed_Low_Rank(double* X, double* Y, int m, int p, int n, double tolerance, double*& U, double*& S, double*& V, int& r);

#endif /* defined(__get_Compressed_Low_Rank__) */