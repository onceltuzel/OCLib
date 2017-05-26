//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//


#include "OLALinearAlgebra.h"

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <cv.h>


#include "clapack.h"


#define OLAMatrixMaxCMIteration 50 
#define OLAMatrixEpsilon 1e-10
#define OLAMatrixConvergenceEpsilon 1.0




void OLALinearAlgebra::Subtract(OLAMatrix& inmat, OLAVector& vec, OLAMatrix& outmat, int order)
{
	int i, j;

	switch (order)
	{
	case 0:
		for (i=0 ; i<inmat.nRows_ ; i++)
		{
			for (j=0 ; j<inmat.nCols_ ;j++)
			{
				outmat(i, j) = inmat(i, j) - vec(i);
			}
		}
		break;
	case 1:
		for (i=0 ; i<inmat.nRows_ ; i++)
		{
			for (j=0 ; j<inmat.nCols_ ;j++)
			{
				outmat(i,j) = inmat(i,j) - vec(j);
			}
		}
		break;
	}

}

void OLALinearAlgebra::Copy(OLAVector* vec, OLAMatrix& mat, int n, int order)
{
	int i, j;

	switch (order)
	{
	case 0:
		for (i=0 ; i<n ; i++)
		{
			for (j=0 ; j<mat.nRows_ ;j++)
			{
				mat(j, i) = vec[i](j);
			}
		}
		break;
	case 1:
		for (i=0 ; i<n ; i++)
		{
			for (j=0 ; j<mat.nCols_ ;j++)
			{
				mat(i, j) = vec[i](j);
			}
		}
		break;
	}
}

//Vector operations
void OLALinearAlgebra::Zero(OLAVector& vec)
{
	memset(vec.data_, 0, sizeof(double)*vec.n_);
} 

//Two element operations
void OLALinearAlgebra::Subtract(const OLAVector& invec1, const OLAVector& invec2, OLAVector& outvec)
{ 
	int i;

	double* data1 = invec1.data_;
	double* data2 = invec2.data_;
	double* data = outvec.data_;
	int n = outvec.n_;

	for (i=0 ; i<n ; i++)
		data[i] = data1[i] - data2[i];	
}

void OLALinearAlgebra::Add(const OLAVector& invec1, const OLAVector& invec2, OLAVector& outvec)
{
	int i;

	double* data1 = invec1.data_;
	double* data2 = invec2.data_;
	double* data = outvec.data_;
	int n = outvec.n_;

	for (i=0 ; i<n ; i++)
		data[i] = data1[i] + data2[i];	
}


double OLALinearAlgebra::Norm(const OLAVector& vec)
{
	return (double) sqrt(Norm2(vec));
}

double OLALinearAlgebra::Norm1(const OLAVector& vec)
{
	int i;
	double val = 0;
	double* data = vec.data_;
	int n = vec.n_;

	for (i=0 ; i<n ; i++)
		val += (double)fabs(data[i]);

	return val;
}

double OLALinearAlgebra::Norm2(const OLAVector& vec)
{
	int i;
	double val = 0;
	double* data = vec.data_;
	int n = vec.n_;

	for (i=0 ; i<n ; i++)
		val += data[i]*data[i];

	return val;
}

void OLALinearAlgebra::Normalize(OLAVector& vec)
{
	const double norm = OLALinearAlgebra::Norm(vec);

	double* data = vec.data_;
	const int n = vec.n_;

	for (int i=0; i<n; ++i)
	{
		data[i] /= norm;
	}
}

void OLALinearAlgebra::Cross3(const OLAVector& invec1, const OLAVector& invec2, OLAVector& outvec)
{
	outvec(0) = invec1(1)*invec2(2) - invec1(2)*invec2(1);
	outvec(1) = invec1(2)*invec2(0) - invec1(0)*invec2(2);
	outvec(2) = invec1(0)*invec2(1) - invec1(1)*invec2(0);
}



double OLALinearAlgebra::Dot(const OLAVector& vec1, const OLAVector& vec2)
{
	CvMat cvec1, cvec2;
	cvInitMatHeader( &cvec1, 1, vec1.n_, CV_64FC1, vec1.data_ );
	cvInitMatHeader( &cvec2, 1, vec2.n_, CV_64FC1, vec2.data_ );

	return cvDotProduct( &cvec1, &cvec2 );

	/*
	int i;
	double val = 0;
	double* data1 = vec1.data_;
	double* data2 = vec2.data_;
	int n = vec1.n_;

	for (i=0 ; i<n ; i++)
		val += data1[i]*data2[i];	

	return val;

	*/
}


//Matrix operations
void OLALinearAlgebra::Zero(OLAMatrix& matrix)
{
	memset(matrix.data_, 0, sizeof(double) * matrix.n_);
}

void OLALinearAlgebra::Identity(OLAMatrix& matrix)
{	
	int i;

	Zero(matrix);
	for (i=0 ; i<matrix.nRows_ ; i++)
	{
		matrix(i,i) = 1.0; 
	}
}

void OLALinearAlgebra::MultiplyAdd(const OLAMatrix& inmatrix, const OLAVector& invec, const OLAVector& addvec, OLAVector& outvec)
{
	CvMat cinmatrix, cinvec, caddvec, coutvec;

	cvInitMatHeader( &cinmatrix, inmatrix.nCols_, inmatrix.nRows_, CV_64FC1, inmatrix.data_ );
	cvInitMatHeader( &cinvec, 1, invec.n_, CV_64FC1, invec.data_ );
	cvInitMatHeader( &caddvec, 1, addvec.n_, CV_64FC1, addvec.data_ );
	cvInitMatHeader( &coutvec, 1, outvec.n_, CV_64FC1, outvec.data_ );

	cvMatMulAdd( &cinvec, &cinmatrix,  &caddvec, &coutvec );
}


void OLALinearAlgebra::Multiply(const OLAMatrix& inmatrix, const OLAVector& invec, OLAVector& outvec)
{
	CvMat cinmatrix, cinvec, coutvec;

	cvInitMatHeader( &cinmatrix, inmatrix.nCols_, inmatrix.nRows_, CV_64FC1, inmatrix.data_ );
	cvInitMatHeader( &cinvec, 1, invec.n_, CV_64FC1, invec.data_ );
	cvInitMatHeader( &coutvec, 1, outvec.n_, CV_64FC1, outvec.data_ );

	cvMatMul( &cinvec, &cinmatrix,  &coutvec );
	

	/*
	int i, j;

	Zero(outvec);

	for (i=0 ; i<inmatrix.nRows_ ; i++)
	{
		for (j=0 ; j<inmatrix.nCols_ ; j++)
		{
			outvec(i) += (inmatrix(i,j) * invec(j));
		}
	}
	*/
}


void OLALinearAlgebra::MultiplyAdd(const OLAMatrix& inmatrix1, const OLAMatrix& inmatrix2, const OLAMatrix& addmatrix, OLAMatrix& outmatrix)
{
	CvMat cinmatrix1, cinmatrix2, caddmatrix, coutmatrix;

	cvInitMatHeader( &cinmatrix1, inmatrix1.nCols_, inmatrix1.nRows_, CV_64FC1, inmatrix1.data_ );
	cvInitMatHeader( &cinmatrix2, inmatrix2.nCols_, inmatrix2.nRows_, CV_64FC1, inmatrix2.data_ );
	cvInitMatHeader( &caddmatrix, addmatrix.nCols_, addmatrix.nRows_, CV_64FC1, addmatrix.data_ );
	cvInitMatHeader( &coutmatrix, outmatrix.nCols_, outmatrix.nRows_, CV_64FC1, outmatrix.data_ );

	cvMatMulAdd( &cinmatrix2, &cinmatrix1,  &caddmatrix, &coutmatrix );
}

void OLALinearAlgebra::MultiplyTranspose(const OLAMatrix& inmatrix, OLAMatrix& outmatrix, int order)
{
	CvMat cinmatrix, coutmatrix;

	cvInitMatHeader( &cinmatrix, inmatrix.nCols_, inmatrix.nRows_, CV_64FC1, inmatrix.data_ );
	cvInitMatHeader( &coutmatrix, outmatrix.nCols_, outmatrix.nRows_, CV_64FC1, outmatrix.data_ );

	cvMulTransposed( &cinmatrix, &coutmatrix, order);
}


void OLALinearAlgebra::Multiply(const OLAMatrix& inmatrix1, const OLAMatrix& inmatrix2, OLAMatrix& outmatrix)
{

	CvMat cinmatrix1, cinmatrix2, coutmatrix;

	cvInitMatHeader( &cinmatrix1, inmatrix1.nCols_, inmatrix1.nRows_, CV_64FC1, inmatrix1.data_ );
	cvInitMatHeader( &cinmatrix2, inmatrix2.nCols_, inmatrix2.nRows_, CV_64FC1, inmatrix2.data_ );
	cvInitMatHeader( &coutmatrix, outmatrix.nCols_, outmatrix.nRows_, CV_64FC1, outmatrix.data_ );

	cvMatMul( &cinmatrix2, &cinmatrix1,  &coutmatrix );


/*	
	int i, j, k, p;
	double value;
	double *d1, *d2;

	p = inmatrix1.nCols_;

	for (i=0 ; i<outmatrix.nRows_ ; i++)
	{

		for (j=0 ; j<outmatrix.nCols_ ; j++)
		{
			value = 0.0;
			for (k=0 ; k<p ; k++)
			{
				value += inmatrix1(i, k) * inmatrix2(k, j);
			}

			outmatrix(i,j) = value;
		}
	}
*/	
}



void OLALinearAlgebra::Subtract(const OLAMatrix& inmatrix1, const OLAMatrix& inmatrix2, OLAMatrix& outmatrix)
{
	int i;
	double* m1data;
	double* m2data;

	m1data = inmatrix1.data_;
	m2data = inmatrix2.data_;

	for (i=0 ; i<outmatrix.n_ ; i++)
	{
		outmatrix.data_[i] = m1data[i] - m2data[i];
	}
}


void OLALinearAlgebra::Add(const OLAMatrix& inmatrix1, const OLAMatrix& inmatrix2, OLAMatrix& outmatrix)
{
	int i;
	double* m1data;
	double* m2data;

	m1data = inmatrix1.data_;
	m2data = inmatrix2.data_;

	for (i=0 ; i<outmatrix.n_ ; i++)
	{
		outmatrix.data_[i] = m1data[i] + m2data[i];
	}
}


void OLALinearAlgebra::OuterProduct(const OLAVector& invec1, const OLAVector& invec2, OLAMatrix& outmatrix)
{
	int i, j; 

	for (i=0 ; i<outmatrix.nRows_ ; i++)
	{
		for (j=0 ; j<outmatrix.nCols_	; j++)
		{
			outmatrix(i,j) = invec1(i)*invec2(j);
		}
	}

}
     

void OLALinearAlgebra::Transpose(const OLAMatrix& inmatrix, OLAMatrix& outmatrix)
{
	CvMat cinmatrix, coutmatrix;

	cvInitMatHeader( &cinmatrix, inmatrix.nCols_, inmatrix.nRows_, CV_64FC1, inmatrix.data_ );
	cvInitMatHeader( &coutmatrix, outmatrix.nCols_, outmatrix.nRows_, CV_64FC1, outmatrix.data_ );
	
	cvTranspose(&cinmatrix, &coutmatrix);
/*
	int i, j;

	for (i=0 ; i<inmatrix.nRows_ ; i++)
	{
		for (j=0 ; j<inmatrix.nCols_ ; j++)
		{
			outmatrix(j,i) = inmatrix(i,j);
		}		
	}
*/
}

void OLALinearAlgebra::PInverse(const OLAMatrix& inmatrix, OLAMatrix& outmatrix)
{
	/*
	CvMat cinmatrix, coutmatrix;

	cvInitMatHeader( &cinmatrix, inmatrix.nCols_, inmatrix.nRows_, CV_64FC1, inmatrix.data_ );
	cvInitMatHeader( &coutmatrix, outmatrix.nCols_, outmatrix.nRows_, CV_64FC1, outmatrix.data_ );

	double v = cvInvert( &cinmatrix, &coutmatrix, CV_SVD );
	*/


	
	int i, j, k;
	int mindim;
	OLAMatrix U, Vt;
	OLAVector S;

	if (inmatrix.nRows_ > inmatrix.nCols_)
		mindim = inmatrix.nCols_;
	else
		mindim = inmatrix.nRows_;

	U.Resize(inmatrix.nRows_, inmatrix.nRows_);
	Vt.Resize(inmatrix.nCols_, inmatrix.nCols_);
	S.Resize(mindim);
	SVD(inmatrix, U, S, Vt);


	int rank = mindim;
	for (i=1 ; i<mindim ; i++)
	{
		if ((S(i) / S(0)) < OLAMatrixEpsilon)
		{
			rank = i;
			break;
		}
	}
	
	for (i=0 ; i<outmatrix.nRows_ ; i++)
	{
		for (j=0 ; j<outmatrix.nCols_ ; j++)
		{
			double value = 0.0;
			for (k=0 ; k<rank ; k++)
			{
				value += (Vt(k, i) * U(j, k)) / S(k);
				//value += inmatrix1(i, k) * inmatrix2(k, j);
			}

			outmatrix(i,j) = value;
		}
	}
	
}





void OLALinearAlgebra::SVD(const OLAMatrix& matrix, OLAMatrix& U, OLAVector& S, OLAMatrix& Vt)
{


	int rank;
	char jobu = 'A';
	char jobvt = 'A';
	integer m = matrix.nRows_;
	integer n = matrix.nCols_;
	int maxdim;
	int mindim;
	if (m>n)
	{
		maxdim = m;
		mindim = n;
	}
	else
	{
		maxdim = n;
		mindim = m;
	}
	integer lda = m; 
	double* s = S.data_;//new double[mindim];
	double *u = U.data_;//NULL;
	integer ldu = m;
	double *vt = Vt.data_;//NULL;
	integer ldvt = n;
	double* work = new double[5*maxdim];
	integer lwork = 5*maxdim;
	integer info;
	double* data = new double[n*m];
	memcpy(data, matrix.data_,m*n*sizeof(double));


	dgesvd_(&jobu, &jobvt, &m, &n, data, &lda, s, u, &ldu,
		vt, &ldvt, work, &lwork, &info);

	delete [] work;
	delete [] data;


}


int OLALinearAlgebra::Rank(const OLAMatrix& matrix)
{

	int rank;
	char jobu = 'N';
	char jobvt = 'N';
	integer m = matrix.nRows_;
	integer n = matrix.nCols_;
	int maxdim;
	int mindim;
	if (m>n)
	{
		maxdim = m;
		mindim = n;
	}
	else
	{
		maxdim = n;
		mindim = m;
	}
	integer lda = m; 
	double* s = new double[mindim];
	double *u = NULL;
	integer ldu = m;
	double *vt = NULL;
	integer ldvt = n;
	double* work = new double[5*maxdim];
	integer lwork = 5*maxdim;
	integer info;
	double* data = new double[n*m];
	memcpy(data, matrix.data_,m*n*sizeof(double));

   
	dgesvd_(&jobu, &jobvt, &m, &n, data, &lda, s, u, &ldu,
			vt, &ldvt, work, &lwork, &info);

	rank = mindim;
	for (int i=0 ; i<mindim ; i++)
	{
		if ((s[i] / s[0]) < OLAMatrixEpsilon)
		{
			rank = i;
			break;
		}
	}

	delete [] s;   
	delete [] work;
	delete [] data;

	return rank;


}


void OLALinearAlgebra::Inverse(const OLAMatrix& inmatrix, OLAMatrix& outmatrix)
{

	/*
	CvMat cinmatrix, coutmatrix;

	cvInitMatHeader( &cinmatrix, inmatrix.nCols_, inmatrix.nRows_, CV_64FC1, inmatrix.data_ );
	cvInitMatHeader( &coutmatrix, outmatrix.nCols_, outmatrix.nRows_, CV_64FC1, outmatrix.data_ );

	cvInvert( &cinmatrix, &coutmatrix, CV_LU );
	*/

	
	integer n;
	integer lda;
	integer lwork;
	integer info;

	integer* ipiv;
	double* work;

	outmatrix = inmatrix;

	n = outmatrix.nRows_;
	lda = outmatrix.nRows_;
	lwork = outmatrix.n_;

	ipiv = new integer[n];
	work = new double[lwork];

	dgetrf_(&n, &n, outmatrix.data_, &lda, ipiv, &info);
	dgetri_(&n, outmatrix.data_, &lda, ipiv, work, &lwork, &info);

	delete[] work;
	delete[] ipiv;

}



double OLALinearAlgebra::Determinant(const OLAMatrix& matrix)
{
	int i;
	integer n;
	integer lda;
	integer info;
	double	det, sgn;

	integer* ipiv;
	OLAMatrix tmatrix(matrix.nRows_, matrix.nCols_);

	n = matrix.nRows_;
	lda = matrix.nRows_;

	ipiv = new integer[n];

	tmatrix = matrix;
	dgetrf_(&n, &n, tmatrix.data_, &lda, ipiv, &info);

	det = 1.0;
	sgn = 1.0;
	for (i=0; i<tmatrix.nRows_; i++)
	{
		det = det * tmatrix(i,i);
		if (ipiv[i]!=(i+1))		
			sgn = -sgn;
	}
	det *= sgn;

	delete [] ipiv;
	return det;
}

double OLALinearAlgebra::FrobeniusNorm(const OLAMatrix& matrix)
{
	int i;
	double norm;

	norm = 0;
	for (i=0 ; i<matrix.n_ ; i++)
		norm += matrix.data_[i]*matrix.data_[i];

	return sqrt(norm);
}


int OLALinearAlgebra::Sqrt(const OLAMatrix& inmatrix, OLAMatrix& outmatrix)
{
	int i;
	double norm;

	int nRows = inmatrix.nRows_;
	int nCols = inmatrix.nCols_;

	OLAMatrix X(nRows, nCols), Y(nRows, nCols), iX(nRows, nCols), iY(nRows, nCols), D(nRows, nCols);

	X = inmatrix;
	Identity(Y);

	i = 0;
	Multiply(X, X, D);
	D -= inmatrix;
	norm = FrobeniusNorm(D);
	while (i < OLAMatrixMaxCMIteration && norm > OLAMatrixEpsilon)
	{
		Inverse(X, iX);
		Inverse(Y, iY);

		X += iY;
		X *= 0.5;

		Y += iX;
		Y *= 0.5;

		Multiply(X, X, D);
		D -= inmatrix;
		
		norm = FrobeniusNorm(D);
		i++;
	}

	if (norm > OLAMatrixConvergenceEpsilon)
		return 1;

	outmatrix = X;

	return 0;
}

void OLALinearAlgebra::EIG(const OLAMatrix& matrix, OLAMatrix& V, OLAVector& D)
{

	char jobz = 'V';
	char uplo = 'U';
	integer n = matrix.nCols_;
	integer lda = n;
	integer lwork = 3*n-1;
	doublereal* work = new doublereal[lwork];
	integer info;

	int m;
	OLAMatrix tMatrix1, tMatrix2;

	m = matrix.nRows_;
	V.Resize(m, m);
	D.Resize(m);

	tMatrix1.Resize(m, m);
	tMatrix2.Resize(m, m);

	V = matrix;

	dsyev_(&jobz, &uplo, &n, V.data_, &lda, D.data_, work, &lwork, &info);

	delete [] work;


}



int OLALinearAlgebra::SPDExp(const OLAMatrix& inmatrix, OLAMatrix& outmatrix)
{
#if 0
	char jobz = 'V';
	char uplo = 'U';
	integer n = inmatrix.nCols_;
	integer lda = n;
	integer lwork = 3*n-1;
	doublereal* work = new doublereal[lwork];
	integer info;

	int m;
	OLAMatrix eigenvectors;
	OLAVector eigenvalues;
	OLAMatrix tMatrix1, tMatrix2;

	m = inmatrix.nRows_;
	eigenvectors.Resize(m, m);
	eigenvalues.Resize(m);

	tMatrix1.Resize(m, m);
	tMatrix2.Resize(m, m);

	eigenvectors = inmatrix;

	dsyev_(&jobz, &uplo, &n, eigenvectors.data_, &lda, eigenvalues.data_, work, &lwork, &info);

	delete[] work;

#else

	const int m = inmatrix.nRows_;
	OLAMatrix eigenvectors(m, m);
	OLAVector eigenvalues(m);
	OLAMatrix tMatrix1(m, m), tMatrix2(m, m);

	EIG(inmatrix, eigenvectors, eigenvalues);
	const int info = 0;

#endif


	for (int i=0 ; i<m ; i++)
	{
		eigenvalues(i) = exp(eigenvalues(i));
	}
	tMatrix1 = eigenvalues;
	OLALinearAlgebra::Multiply(eigenvectors, tMatrix1, tMatrix2);
	OLALinearAlgebra::Transpose(eigenvectors, tMatrix1);
	OLALinearAlgebra::Multiply(tMatrix2, tMatrix1, outmatrix);

	return (info != 0);
}


int OLALinearAlgebra::SPDSqrt(const OLAMatrix& inmatrix, OLAMatrix& outmatrix)
{
#if 0

	char jobz = 'V';
	char uplo = 'U';
	integer n = inmatrix.nCols_;
	integer lda = n;
	integer lwork = 3*n-1;
	doublereal* work = new doublereal[lwork];
	integer info;

	int m;
	OLAMatrix eigenvectors;
	OLAVector eigenvalues;
	OLAMatrix tMatrix1, tMatrix2;

	m = inmatrix.nRows_;
	eigenvectors.Resize(m, m);
	eigenvalues.Resize(m);

	tMatrix1.Resize(m, m);
	tMatrix2.Resize(m, m);

	eigenvectors = inmatrix;

	dsyev_(&jobz, &uplo, &n, eigenvectors.data_, &lda, eigenvalues.data_, work, &lwork, &info);

	delete[] work;

#else

	const int m = inmatrix.nRows_;
	OLAMatrix eigenvectors(m, m);
	OLAVector eigenvalues(m);
	OLAMatrix tMatrix1(m, m), tMatrix2(m, m);

	EIG(inmatrix, eigenvectors, eigenvalues);
	const int info = 0;

#endif

	for (int i=0 ; i<m ; i++)
	{
		if (eigenvalues(i) < -1e-8)
			printf("Error eigenvalue <= 0\n %lf", eigenvalues(i));

		if (eigenvalues(i) < 1e-8)
			eigenvalues(i) = 1e-8;

		eigenvalues(i) = sqrt(eigenvalues(i));
	}
	tMatrix1 = eigenvalues;
	OLALinearAlgebra::Multiply(eigenvectors, tMatrix1, tMatrix2);
	OLALinearAlgebra::Transpose(eigenvectors, tMatrix1);
	OLALinearAlgebra::Multiply(tMatrix2, tMatrix1, outmatrix);


	return (info != 0);
}



int OLALinearAlgebra::PD(const OLAMatrix& inmatrix, OLAMatrix& outmatrix)
{
#if 0

	char jobz = 'V';
	char uplo = 'U';
	integer n = inmatrix.nCols_;
	integer lda = n;
	integer lwork = 3*n-1;
	doublereal* work = new doublereal[lwork];
	integer info;

	int m;
	OLAMatrix eigenvectors;
	OLAVector eigenvalues;

	m = inmatrix.nRows_;
	eigenvectors.Resize(m, m);
	eigenvalues.Resize(m);

	eigenvectors = inmatrix;

	dsyev_(&jobz, &uplo, &n, eigenvectors.data_, &lda, eigenvalues.data_, work, &lwork, &info);

	delete[] work;

#else

	const int m = inmatrix.nRows_;
	OLAMatrix eigenvectors(m, m);
	OLAVector eigenvalues(m);

	EIG(inmatrix, eigenvectors, eigenvalues);
	const int info = 0;

#endif

	for (int i=0 ; i<m ; i++)
	{ 
		if (eigenvalues(i) < 1e-10)
		{
			eigenvalues(i) = 1e-10;
		}
	}


	for (int i=0 ; i<m ; i++)
	{
		for (int j=0 ; j<m ; j++)
		{
			double value = 0.0;
			for (int k=0 ; k<m ; k++)
			{
				value += eigenvectors(i, k) * eigenvectors(j, k) * eigenvalues(k);
			}

			outmatrix(i,j) = value;
		}
	}

	return (info != 0);
}


int OLALinearAlgebra::SPDLog(const OLAMatrix& inmatrix, OLAMatrix& outmatrix)
{
#if 0

	char jobz = 'V';
	char uplo = 'U';
	integer n = inmatrix.nCols_;
	integer lda = n;
	integer lwork = 3*n-1;
	doublereal* work = new doublereal[lwork];
	integer info;

	int m;
	OLAMatrix eigenvectors;
	OLAVector eigenvalues;

	m = inmatrix.nRows_;
	eigenvectors.Resize(m, m);
	eigenvalues.Resize(m);


	eigenvectors = inmatrix;

	dsyev_(&jobz, &uplo, &n, eigenvectors.data_, &lda, eigenvalues.data_, work, &lwork, &info);

	delete[] work;

#else

	const int m = inmatrix.nRows_;
	OLAMatrix eigenvectors(m, m);
	OLAVector eigenvalues(m);

	EIG(inmatrix, eigenvectors, eigenvalues);
	const int info = 0;

#endif

	for (int i=0 ; i<m ; i++)
	{ 
		
		if (eigenvalues(i) < -1e-5)
			printf("Error eigenvalue <= 0\n %lf", eigenvalues(i));
			

		if (eigenvalues(i) < 1e-15)
			eigenvalues(i) = 1e-15;//1e-10;
		else if (eigenvalues(i) > 1e+15)
			eigenvalues(i) = 1e+15;

		eigenvalues(i) = log(eigenvalues(i)); 
	}

	
	for (int i=0 ; i<m ; i++)
	{
		for (int j=0 ; j<m ; j++)
		{
			double value = 0.0;
			for (int k=0 ; k<m ; k++)
			{
				value += eigenvectors(i, k) * eigenvectors(j, k) * eigenvalues(k);
			}

			outmatrix(i,j) = value;
		}
	}


	/*
	OLAMatrix tMatrix1, tMatrix2;
	tMatrix1.Resize(m, m);
	tMatrix2.Resize(m, m);
	tMatrix1 = eigenvalues;
	OLALinearAlgebra::Multiply(eigenvectors, tMatrix1, tMatrix2);
	OLALinearAlgebra::Transpose(eigenvectors, tMatrix1);
	OLALinearAlgebra::Multiply(tMatrix2, tMatrix1, outmatrix);
	*/

	
	return (info != 0);
}

int OLALinearAlgebra::Log(const OLAMatrix& inmatrix, OLAMatrix& outmatrix)
{
	int i, j, k;
	double norm;

	int nRows = inmatrix.nRows_;
	int nCols = inmatrix.nCols_;

	OLAMatrix EYE(nRows, nCols), X(nRows, nCols), Z(nRows, nCols), A(nRows, nCols), M(nRows, nCols), T(nRows, nCols);
	
	Identity(EYE);
	A = inmatrix;

	k = 0;
	j = 0;
	Subtract(A, EYE, M);
	norm = FrobeniusNorm(M);
	while (j < OLAMatrixMaxCMIteration && norm >= 0.5)
	{
		if (Sqrt(A, T) == 1)
			return 1;

		A = T;
		k = k+1;

		Subtract(A, EYE, M);
		norm = FrobeniusNorm(M);
		j++;
	}

	if (norm >= 0.5)
	{
		printf("Possible Error !1! in log function\n");
	}

	A -= EYE;
	A *= -1;
	Z = A;
	X = A;
	
	i = 1;
	j = 0;
	norm = FrobeniusNorm(Z);
	while (j < OLAMatrixMaxCMIteration && norm > OLAMatrixEpsilon)
	{
		Multiply(Z, A, T);
		Z = T;
		i = i+1;
		M = Z;
		M /= i;
		X += M;
		j++;
		norm = FrobeniusNorm(Z);
	}

	if (norm > OLAMatrixEpsilon)
	{
		printf("Possible Error !2! in log function\n");
	}


	X *= (-1.0*pow(2.0,k));
	outmatrix = X;

	return 0;
}


int OLALinearAlgebra::Exp(const OLAMatrix& inmatrix, OLAMatrix& outmatrix)
{
	int j, k, q;
	double c;

	int nRows = inmatrix.nRows_;
	int nCols = inmatrix.nCols_;

	OLAMatrix A(nRows, nCols), X(nRows, nCols), D(nRows, nCols), N(nRows, nCols), cX(nRows, nCols), M(nRows, nCols), T(nRows, nCols);

	//Number of iterations;
	q = 6;

	A = inmatrix;
	j = (int) (1 + log10(FrobeniusNorm(A) + OLAMatrixEpsilon)/log10(2.0));
	if (j<0)
		j = 0;

	A *= pow(2.0, -j);
	Identity(D);
	Identity(N);
	Identity(X);

	c = 1;

	for (k=1 ; k<=q ; k++)
	{
		c = (c*(q-k+1))/(k*(2*q-k+1));
		Multiply(A, X, M);
		X = M;
		M = X;
		M *= c;
		N += M;
		M *= pow(-1.0, k);
		D += M;
	}

	Inverse(D, M);
	Multiply(M, N, X);

	for (k=0 ; k<j ; k++)
	{
		Multiply(X, X, T);
		X = T;
	}

	outmatrix = X;

	return 0;
}



void OLALinearAlgebra::Solve(const OLAMatrix& A, const OLAVector& b, OLAVector& x, int method)
{
	CvMat cA, cb, cx;

	cvInitMatHeader( &cA, A.nCols_, A.nRows_, CV_64FC1, A.data_ );
	cvInitMatHeader( &cb, b.n_, 1, CV_64FC1, b.data_ );
	cvInitMatHeader( &cx, x.n_, 1, CV_64FC1, x.data_ );

	cvSolve( &cA, &cb, &cx, method);
}

void OLALinearAlgebra::Solve(const OLAMatrix& A, const OLAMatrix& B, OLAMatrix& X, int method)
{
	CvMat cA, cB, cX;

	cvInitMatHeader( &cA, A.nCols_, A.nRows_, CV_64FC1, A.data_ );
	cvInitMatHeader( &cB, B.nCols_, B.nRows_, CV_64FC1, B.data_ );
	cvInitMatHeader( &cX, X.nCols_, X.nRows_, CV_64FC1, X.data_ );

	cvSolve( &cA, &cB, &cX, method);

}



void OLALinearAlgebra::Read(FILE* fin, OLAVector& vec)
{
	int i, n;

	fscanf(fin, "%d", &n);
	vec.Resize(n);

	for (i=0 ; i<vec.n_ ;i++)
	{
		fscanf(fin, "%lf", &(vec(i)));
	}
}

void OLALinearAlgebra::Read(FILE* fin, OLAMatrix& matrix)
{
	int i, j;
	int nRows, nCols;

	fscanf(fin, "%d %d", &nRows, &nCols);
	matrix.Resize(nRows, nCols);

	for (i=0 ; i<matrix.nRows_ ;i++)
	{
		for (j=0 ; j<matrix.nCols_ ;j++)
		{
			fscanf(fin, "%lf", &(matrix(i,j)));
		}
	}
}


void OLALinearAlgebra::Write(FILE* fout, const OLAVector& vec)
{
	int i;

	fprintf(fout, "%d\n", vec.n_);
	for (i=0 ; i<vec.n_ ;i++)
	{
		//fprintf(fout, "%d:%.20E ", i+1, vec(i));
		fprintf(fout, "%.20E ", vec(i));
	}

	fprintf(fout, "\n");	
}

void OLALinearAlgebra::Write(FILE* fout, const OLAMatrix& matrix)
{
	int i, j;

	fprintf(fout, "%d %d\n", matrix.nRows_, matrix.nCols_);

	for (i=0 ; i<matrix.nRows_ ;i++)
	{
		for (j=0 ; j<matrix.nCols_ ;j++)
		{
			fprintf(fout, "%.20E ", matrix(i,j));
		}

		fprintf(fout, "\n");
	}
}


void OLALinearAlgebra::Write(const OLAMatrix& matrix)
{
	int i, j;

	for (i=0 ; i<matrix.nRows_ ;i++)
	{
		for (j=0 ; j<matrix.nCols_ ;j++)
		{
			printf("%7.4lf ", matrix(i,j));
		}

		printf("\n");
	}
}

void  OLALinearAlgebra::Write(const OLAVector& vec)
{
	int i;

	for (i=0 ; i<vec.n_ ;i++)
	{
		printf("%7.4lf ", vec(i));
	}

	printf("\n");
} 


