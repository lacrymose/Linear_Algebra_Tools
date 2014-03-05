Linear_Algebra_Tools
====================

Collection of useful linear algebra tools. You need to have [Eigen](http://eigen.tuxfamily.org/) on your machine. This is essentially a convenient wrapper around Eigen. Everything is in the header file and each has one specific function. As a matter of policy, any header file should not have more than '3' functions. Beyond that it might be good idea to have some of the functions in a new header file.

Here are some basic functionalities of this tool:

1. Obtains the reduced QR factorization (available in the header file get_QR.hpp):

		get_QR(const Eigen::MatrixXd A, Eigen::MatrixXd& Q, Eigen::MatrixXd& R);

2. Obtains the reduced SVD to any tolerance (available in the header file get_SVD.hpp):

		get_SVD(const Eigen::MatrixXd A, const double tolerance, Eigen::MatrixXd& U, Eigen::VectorXd& S, Eigen::MatrixXd& V, int& rank);

3. Obtains a compressed low-rank for a low-rank matrix, i.e., given a low-rank matrix in the form X\*Y or X\*Z\*Y, obtains the SVD to a desired tolerance in the form U\*S\*V' (available in the header file get_Compressed_Low_Rank.hpp):

		get_Compressed_Low_Rank(const Eigen::MatrixXd X, const Eigen::MatrixXd Y, const double tolerance, Eigen::MatrixXd& U, Eigen::VectorXd& S, Eigen::MatrixXd& V, int& r);
		
		get_Compressed_Low_Rank(const Eigen::MatrixXd X, const Eigen::MatrixXd Z, const Eigen::MatrixXd Y, const double tolerance, Eigen::MatrixXd& U, Eigen::VectorXd& S, Eigen::MatrixXd& V, int& r);

4. Obtains the Pseudo-Inverse of the matrix, i.e., given a matrix A finds its SVD as USV' and returns VS^{-1}U'.

		get_Pseudo_Inverse(const Eigen::MatrixXd A, const double tolerance, Eigen::MatrixXd& Apinv);

5. Obtains the log-determinant of a matrix without running into underflow or overflow issues.

		double get_Log_Determinant(const Eigen::MatrixXd A);