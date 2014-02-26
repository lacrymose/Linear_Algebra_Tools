//
//  get_SVD.cpp
//
//
//  Created by Sivaram Ambikasaran on 2/26/14.
//
//

#include "get_SVD.hpp"

/*!
 Obtains the SVD decomposition as A=USV', where all the matrices are in Eigen MatrixXd format.
 */
void get_SVD(MatrixXd A, double tolerance, MatrixXd& U, VectorXd& S, MatrixXd& V, int& rank) {
        JacobiSVD<MatrixXd> svd(A, ComputeThinU | ComputeThinV);
        rank    =       0;
        VectorXd Sigma  =       svd.singularValues();
        while (rank < Sigma.size() && Sigma(rank)>tolerance) {
                ++rank;
        }
        U       =       svd.matrixU().block(0,0,A.rows(),rank);
        V       =       svd.matrixV().block(0,0,A.cols(),rank);
        S       =       Sigma.segment(0,rank);
}

/*!
 Obtains the SVD decomposition as A=USV', where all the matrices are in double format.
 */
void get_SVD(double* A, int m, int n, double tolerance, double*& U, double*& S, double*& V, int& rank) {
        //      Maps the double to MatrixXd.
        Map<Matrix<double,Dynamic,Dynamic,ColMajor> >  A_E(A, m, n);

        //      Obtains the SVD of A_E.
        MatrixXd U_E, V_E;
        VectorXd S_E;

        get_SVD(A_E, tolerance, U_E, S_E, V_E, rank);

        //      Maps the MatrixXd to double.
        U       =       U_E.data();
        S       =       S_E.data();
        V       =       V_E.data();
}