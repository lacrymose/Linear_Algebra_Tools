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
using namespace Eigen;

/*!
 Obtains the QR decomposition as A=QR, where all the matrices are in Eigen MatrixXd format.
 */
void get_QR(MatrixXd A, MatrixXd& Q, MatrixXd& R);

/*!
 Obtains the QR decomposition as A=QR, where all the matrices are in double format.
 */
void get_QR(double* A, int m, int n, double*& Q, double*& R);

#endif /* defined(__get_QR_hpp__) */