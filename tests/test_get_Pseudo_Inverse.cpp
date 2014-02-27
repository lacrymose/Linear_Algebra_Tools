//
//  test_get_Pseudo_Inverse.cpp
//
//
//  Created by Sivaram Ambikasaran on 2/25/14.
//
//

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <Eigen/Dense>
#include "get_Pseudo_Inverse.hpp"

using namespace Eigen;

using std::cout;
using std::endl;

int main(int argc, char* argv[]) {
        int m           =       atoi(argv[1]);    //      Number of rows.
        int n           =       atoi(argv[2]);    //      Number of columns.

        double* A       =       new double[m*n];
        
        double RANDMAX  =       double(RAND_MAX);
        
        int count       =       0;
        for (int i=0; i<m; ++i) {
                for (int j=0; j<n; ++j) {
                        A[count]        =       rand()/RANDMAX;
                        ++count;
                }
        }
        
        double tolerance=       1e-12;

        double* Apinv;

        //      Obtains the pseudo inverse.
        get_Pseudo_Inverse(A, m, n, tolerance, Apinv);
        
        MatrixXd A_E    =       MatrixXd::Random(m,n);
        MatrixXd Apinv_E;
        get_Pseudo_Inverse(A_E, tolerance, Apinv_E);

        if (m<n) {
                cout << "Error is: " << (A_E*Apinv_E-MatrixXd::Identity(m,m)).norm() << endl;
        }
        else {
                cout << "Error is: " << (Apinv_E*A_E-MatrixXd::Identity(n,n)).norm() << endl;
        }
}