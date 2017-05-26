//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//

#include "OLAMatrix.h"

#include <math.h>
#include <stdio.h>
#include <string.h>

#define OLAMatrixMaxCMIteration 5
#define OLAMatrixEpsilon 0.000001
#define OLAMatrixConvergenceEpsilon 1.0

OLAMatrix::OLAMatrix()
{
	data_ = NULL;
	nRows_ = 0;
	nCols_ = 0;
	n_ = 0;
}

OLAMatrix::OLAMatrix(int nRows, int nCols)
{
	nRows_ = nRows;
	nCols_ = nCols;
	n_ = nRows_ * nCols_;

	data_ = new double[n_];
	memset(data_, 0, n_*sizeof(double));
}

OLAMatrix::OLAMatrix(const OLAMatrix& mat)
{
	nRows_ = mat.nRows_;
	nCols_ = mat.nCols_;
	n_ = nRows_ * nCols_;

	data_ = new double[n_];
	memcpy(data_, mat.data_, n_*sizeof(double));
}


OLAMatrix::~OLAMatrix()
{
	SafeRelease();
}

void OLAMatrix::SafeRelease()
{
	if (data_)
		delete[] data_;
	data_ = NULL;
}

void OLAMatrix::Resize(int nRows, int nCols)
{
	SafeRelease();
	
	nRows_ = nRows;
	nCols_ = nCols; 
	n_ = nRows_ * nCols_;

	data_ = new double[n_];
	memset(data_, 0, n_*sizeof(double));
}


void OLAMatrix::operator=(const OLAMatrix& matrix)
{
	if (nRows_ != matrix.nRows_	|| nCols_!= matrix.nCols_)
	{
		Resize(matrix.nRows_, matrix.nCols_);
	}

	memcpy(data_, matrix.data_, n_*sizeof(double));
}

void OLAMatrix::operator=(const double* data)
{
	memcpy(data_, data, n_*sizeof(double));
}

void OLAMatrix::operator=(const OLAVector& vec)
{
	if (nRows_ != vec.n_|| nCols_!= vec.n_)
	{
		Resize(vec.n_, vec.n_);
	}

	memset(data_, 0, n_*sizeof(double));
	for(int i=0 ; i<nCols_ ; i++)
	{
		operator()(i,i) = vec(i);
	}
	
}

void OLAMatrix::operator=(double val)
{
	int i;

	for (i=0 ; i<n_ ; i++)
	{
		data_[i] = val;
	}
}


void OLAMatrix::operator+=(const OLAMatrix& matrix)
{
	int i;

	for (i=0 ; i<n_ ; i++)
	{
		data_[i] += matrix.data_[i];
	}
}

void OLAMatrix::operator+=(double value)
{
	int i;

	for (i=0 ; i<n_ ; i++)
	{
		data_[i] += value;
	}
}

void OLAMatrix::operator-=(const OLAMatrix& matrix)
{
	int i;

	for (i=0 ; i<n_ ; i++)
	{
		data_[i] -= matrix.data_[i];
	}
}

void OLAMatrix::operator-=(double value)
{
	int i;

	for (i=0 ; i<n_ ; i++)
	{
		data_[i] -= value;
	}
}

void OLAMatrix::operator*=(const OLAMatrix& matrix)
{
	int i;

	for (i=0 ; i<n_ ; i++)
	{
		data_[i] *= matrix.data_[i];
	}
}


void OLAMatrix::operator*=(double value)
{
	int i;

	for (i=0 ; i<n_ ; i++)
	{
		data_[i] *= value;
	}
}

void OLAMatrix::operator/=(const OLAMatrix& matrix)
{
	int i;

	for (i=0 ; i<n_ ; i++)
	{
		data_[i] /= matrix.data_[i];
	}
}

void OLAMatrix::operator/=(double value)
{
	int i;

	for (i=0 ; i<n_ ; i++)
	{
		data_[i] /= value;
	}
}

/*
void OLAMatrix::Multiply(OLAVector& vec, OLAVector& res)
{
	int i, j;

	res.SetZero();

	for (i=0 ; i<nRows_ ; i++)
	{
		for (j=0 ; j<nCols_ ; j++)
		{
			res(i) += (data_[i+j*nRows_] * vec.data_[j]);
		}
	}
}


void OLAMatrix::Multiply(const OLAMatrix& matrix)
{
	int i, j, k;
	double value;
	double* data;

	data = new double[n_];

	for (i=0 ; i<nRows_ ; i++)
	{
		for (j=0 ; j<nCols_ ; j++)
		{
			value = 0.0;
			for (k=0 ; k<nCols_ ; k++)
			{
				value += data_[i+k*nRows_]*matrix.data_[k+j*nRows_];
			}
			data[i + j*nRows_] = value;
		}
	}

	memcpy(data_, data, sizeof(double) * n_);
	delete[] data;
}


void OLAMatrix::Subtract(const OLAMatrix& matrix1, const OLAMatrix& matrix2)
{
	int i;
	double* m1data;
	double* m2data;

	m1data = matrix1.data_;
	m2data = matrix2.data_;

	for (i=0 ; i<n_ ; i++)
	{
		data_[i] = m1data[i] - m2data[i];
	}
}


void OLAMatrix::Add(const OLAMatrix& matrix1, const OLAMatrix& matrix2)
{
	int i;
	double* m1data;
	double* m2data;

	m1data = matrix1.data_;
	m2data = matrix2.data_;

	for (i=0 ; i<n_ ; i++)
	{
		data_[i] = m1data[i] + m2data[i];
	}
}


void OLAMatrix::Cross(const OLAVector& vec1, const OLAVector& vec2)
{
	int i, j; 

	for (i=0 ; i<nRows_ ; i++)
	{
		for (j=0 ; j<nCols_	; j++)
		{
			data_[i + j*nRows_] = vec1(i)*vec2(j);
		}
	}

}


void OLAMatrix::Multiply(const OLAMatrix& matrix1, const OLAMatrix& matrix2)
{
	int i, j, k, p;
	double value;
	double* m1data;
	double* m2data;

	double* data = new double[n_];

	p = matrix1.nCols_;
	m1data = matrix1.data_;
	m2data = matrix2.data_;

	for (i=0 ; i<nRows_ ; i++)
	{
		for (j=0 ; j<nCols_ ; j++)
		{
			value = 0.0;
			for (k=0 ; k<p ; k++)
			{
				value += matrix1(i, k) * matrix2(k, j);//m1data[i+k*nRows_]*m2data[k+j*nCols_];
			}

			data[i+j*nRows_] = value;
		}
	}

	memcpy(data_, data, sizeof(double) * n_);
	delete[] data;
}

void OLAMatrix::Transpose()
{
	int i, j, t;
	double* data;

	data = new double[n_];

	for (i=0 ; i<nRows_ ; i++)
	{
		for (j=0 ; j<nCols_ ; j++)
		{
			data[j+i*nCols_] = data_[i+j*nRows_];
		}		
	}

	t = nRows_;
	nRows_ = nCols_;
	nCols_ = t;

	memcpy(data_, data, sizeof(double)*n_);
	delete[] data;
}


void OLAMatrix::Transpose(OLAMatrix& matrix)
{
	int i, j;

	for (i=0 ; i<nRows_ ; i++)
	{
		for (j=0 ; j<nCols_ ; j++)
		{
			matrix.data_[j+i*nCols_] = data_[i+j*nRows_];
		}		
	}
}

int OLAMatrix::Rank()
{

	int rank;
	char jobu = 'N';
	char jobvt = 'N';
	integer m = nRows_;
	integer n = nCols_;
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
	memcpy(data, data_,m*n*sizeof(double));

   
	dgesvd_(&jobu, &jobvt, &m, &n, data, &lda, s, u, &ldu,
			vt, &ldvt, work, &lwork, &info);

	rank = mindim;
	for (int i=0 ; i<mindim ; i++)
	{
		if (s[i]<OLAMatrixEpsilon)
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


void OLAMatrix::Inverse()
{ 
	integer n;
	integer lda;
	integer lwork;
	integer info;

	integer* ipiv;
	double* work;

	n = nRows_;
	lda = nRows_;
	lwork = n_;

	ipiv = new integer[n];
	work = new double[lwork];

	dgetrf_(&n, &n, data_, &lda, ipiv, &info);
	dgetri_(&n, data_, &lda, ipiv, work, &lwork, &info);

	delete[] work;
	delete[] ipiv;
	
}


void OLAMatrix::Inverse(OLAMatrix& matrix)
{
	matrix = *this;
	matrix.Inverse();
}




double OLAMatrix::Determinant()
{
	int i;
	integer n;
	integer lda;
	integer info;
	double	det, sgn;

	integer* ipiv;
	OLAMatrix matrix(nRows_, nCols_);

	n = nRows_;
	lda = nRows_;

	ipiv = new integer[n];

	matrix = *this;
	dgetrf_(&n, &n, matrix.data_, &lda, ipiv, &info);

	det = 1.0;
	sgn = 1.0;
	for (i=0; i<nRows_; i++)
	{
		det = det * matrix(i,i);
		if (ipiv[i]!=(i+1))		
			sgn = -sgn;
	}
	det *= sgn;

	delete [] ipiv;
	return det;
}

double OLAMatrix::FrobeniusNorm()
{
	int i;
	double norm;

	norm = 0;
	for (i=0 ; i<n_ ; i++)
		norm += data_[i]*data_[i];

	return sqrt(norm);
}



void OLAMatrix::SetZero()
{
	memset(data_, 0, sizeof(double) * n_);
}

void OLAMatrix::SetIdentity()
{
	int i;

	SetZero();
	for (i=0 ; i<nRows_ ; i++)
	{
		(*this)(i,i) = 1.0;
	}
}

int OLAMatrix::Sqrt()
{
	int i;
	double norm;

	OLAMatrix X(nRows_, nCols_), Y(nRows_, nCols_), iX(nRows_, nCols_), iY(nRows_, nCols_), D(nRows_, nCols_);

	X = *this;
	Y.SetIdentity();

	i = 0;
	D.Multiply(X, X);
	D -= *this;
	norm = D.FrobeniusNorm();
	while (i < OLAMatrixMaxCMIteration && norm > OLAMatrixEpsilon)
	{
		X.Inverse(iX);
		Y.Inverse(iY);

		X += iY;
		X *= 0.5;

		Y += iX;
		Y *= 0.5;

		D.Multiply(X, X);
		D -= *this;
		
		norm = D.FrobeniusNorm();
		i++;
	}

	if (norm > OLAMatrixConvergenceEpsilon)
		return 1;

	*this = X;

	return 0;
}

int OLAMatrix::Sqrt(OLAMatrix& matrix)
{
	matrix = *this;
	return matrix.Sqrt();
}




int OLAMatrix::Log()
{
	int i, j, k;
	double norm;
	OLAMatrix EYE(nRows_, nCols_), X(nRows_, nCols_), Z(nRows_, nCols_), A(nRows_, nCols_), M(nRows_, nCols_);
	
	EYE.SetIdentity();
	A = *this;

	k = 0;
	j = 0;
	M.Subtract(A, EYE);
	norm = M.FrobeniusNorm();
	while (j < OLAMatrixMaxCMIteration && norm >= 0.5)
	{
		if (A.Sqrt() == 1)
			return 1;

		k = k+1;

		M.Subtract(A, EYE);
		norm = M.FrobeniusNorm();
		j++;
	}

	A -= EYE;
	A *= -1;
	Z = A;
	X = A;
	
	i = 1;
	j = 0;
	norm = Z.FrobeniusNorm();
	while (j < OLAMatrixMaxCMIteration && norm > OLAMatrixEpsilon)
	{
		Z.Multiply(A);
		i = i+1;
		M = Z;
		M /= i;
		X += M;
		j++;
		norm = Z.FrobeniusNorm();
	}

	X *= (-1.0*pow(2.0,k));
	*this = X;

	return 0;
}

int OLAMatrix::Log(OLAMatrix& matrix)
{
	matrix = *this;
	return matrix.Log();
}

int OLAMatrix::Exp()
{
	int j, k, q;
	double c;
	OLAMatrix A(nRows_, nCols_), X(nRows_, nCols_), D(nRows_, nCols_), N(nRows_, nCols_), cX(nRows_, nCols_), M(nRows_, nCols_);

	//Number of iterations;
	q = 6;

	A = *this;
	j = (int) (1 + log10(A.FrobeniusNorm() + OLAMatrixEpsilon)/log10(2.0));
	if (j<0)
		j = 0;

	A *= pow(2.0, -j);
	D.SetIdentity();
	N.SetIdentity();
	X.SetIdentity();

	c = 1;

	for (k=1 ; k<=q ; k++)
	{
		c = (c*(q-k+1))/(k*(2*q-k+1));
		M.Multiply(A,X);
		X = M;
		M = X;
		M *= c;
		N += M;
		M *= pow(-1.0, k);
		D += M;
	}

	D.Inverse(M);
	X.Multiply(M, N);

	for (k=0 ; k<j ; k++)
		X.Multiply(X);

	*this = X;

	return 0;
}

int OLAMatrix::Exp(OLAMatrix& matrix)
{
	matrix = *this;
	return matrix.Exp();
}
*/