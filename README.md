Linear_Algebra_Tools
====================

Collection of useful linear algebra tools. You need to have [Eigen](http://eigen.tuxfamily.org/) on your machine. This is essentially a convinient wrapper around Eigen. Here are some basic functionalities of this tool:

1. Obtains the reduced QR factorization:
	get_QR(double* A, int m, int n, double*& Q, double*& R);
	get_QR(MatrixXd A, MatrixXd& Q, MatrixXd& R);

2. Obtains the reduced SVD to any tolerance:
	get_SVD(double* A, int m, int n, double tolerance, double*& U, double*& S, double*& V, int& rank);
	get_SVD(MatrixXd A, double tolerance, MatrixXd& U, VectorXd& S, MatrixXd& V, int& rank);

3. Obtains a compressed low-rank for a low-rank matrix, i.e., given a low-rank matrix in the form X*Y, obtains the SVD in the form U*S*V':
	get_Compressed_Low_Rank(double* X, double* Y, int m, int p, int n, double tolerance, double*& U, double*& S, double*& V, int& r);
	get_Compressed_Low_Rank(MatrixXd X, MatrixXd Y, double tolerance, MatrixXd& U, VectorXd& S, MatrixXd& V, int& r);
