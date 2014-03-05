//
//  get_Log_Determinant.hpp
//  
//
//  Created by Sivaram Ambikasaran on 3/4/14.
//
//

#ifndef __get_Log_Determinant_hpp__
#define __get_Log_Determinant_hpp__

#include <cmath>
#include <Eigen/Dense>

/*!
 Obtains the log(determinant) of the matrix 'A'. This should be used as opposed to finding the determinant and then the logarithm to avoid overflow and underflow issues.
 */

double get_Log_Determinant(const Eigen::MatrixXd A) {
        Eigen::MatrixXd LU     =       A.lu().matrixLU();
        double logdet   =       0.0;
        for (int k=0; k<LU.rows(); ++k) {
                logdet+=log(fabs(LU(k,k)));
        }
        return logdet;
}

#endif /* defined(__get_Log_Determinant_hpp__)*/