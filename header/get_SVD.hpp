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
using namespace Eigen;

/*!
 Obtains the SVD as A=USV', where all the matrices are in Eigen MatrixXd format.
 */
void get_SVD(MatrixXd A, double tolerance, MatrixXd& U, VectorXd& S, MatrixXd& V, int& rank);

/*!
 Obtains the SVD decomposition as A=USV', where all the matrices are in double format.
 */
void get_SVD(double* A, int m, int n, double tolerance, double*& U, double*& S, double*& V, int& rank);

#endif /* defined(__get_SVD_hpp__) */