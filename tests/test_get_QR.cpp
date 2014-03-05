//
//  get_QR.cpp
//
//
//  Created by Sivaram Ambikasaran on 2/26/14.
//
//

#include "get_QR.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <Eigen/Dense>

using std::cout;
using std::endl;
using namespace Eigen;

int main(int argc, char* argv[]) {
        srand(time(NULL));

        int m           =       atoi(argv[1]);
        int n           =       atoi(argv[2]);
        MatrixXd A      =       MatrixXd::Random(m,n);

        MatrixXd Q, R;
        get_QR(A, Q, R);
        cout << "Error is: " << (A-Q*R).cwiseAbs().maxCoeff() << endl;
}
