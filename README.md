Linear_Algebra_Tools
====================

Collection of useful linear algebra tools. You need to have [Eigen](http://eigen.tuxfamily.org/) on your machine. This is essentially a convenient wrapper around Eigen. Each header file has one specific function. As a matter of policy, any header file and the corresponding cpp file should contain ideally just '2' function, at the most '5' functions. Beyond that it might be good idea to have some of the functions in a new header file.

Here are some basic functionalities of this tool:

1. Obtains the reduced QR factorization (available in the header file get_QR.hpp):

		get_QR(double* A, int m, int n, double*& Q, double*& R);
		get_QR(MatrixXd A, MatrixXd& Q, MatrixXd& R);

2. Obtains the reduced SVD to any tolerance (available in the header file get_SVD.hpp):

		get_SVD(double* A, int m, int n, double tolerance, double*& U, double*& S, double*& V, int& rank);
		get_SVD(MatrixXd A, double tolerance, MatrixXd& U, VectorXd& S, MatrixXd& V, int& rank);

3. Obtains a compressed low-rank for a low-rank matrix, i.e., given a low-rank matrix in the form X\*Y, obtains the SVD to a desired tolerance in the form U\*S\*V' (available in the header file get_Compressed_Low_Rank.hpp):

		get_Compressed_Low_Rank(double* X, double* Y, int m, int p, int n, double tolerance, double*& U, double*& S, double*& V, int& r);
		get_Compressed_Low_Rank(MatrixXd X, MatrixXd Y, double tolerance, MatrixXd& U, VectorXd& S, MatrixXd& V, int& r);