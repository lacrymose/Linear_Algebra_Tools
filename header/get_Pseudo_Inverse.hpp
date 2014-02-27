//
//  get_Pseudo_Inverse.hpp
//
//
//  Created by Sivaram Ambikasaran on 2/26/14.
//
//

#ifndef __get_Pseudo_Inverse_hpp__
#define __get_Pseudo_Inverse_hpp__

#include <Eigen/Dense>

using namespace Eigen;

/*!
 Obtains the pseudo inverse of a matrix, where the matrices are stored using Eigen's MatrixXd.
 */
void get_Pseudo_Inverse(MatrixXd A, double tolerance, MatrixXd& Apinv);

/*!
 Obtains the pseudo inverse of a matrix, where the matrices are stored using double*.
 */
void get_Pseudo_Inverse(double* A, int m, int n, double tolerance, double*& Apinv);

#endif