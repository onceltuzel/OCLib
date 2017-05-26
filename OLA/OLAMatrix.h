//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//


#ifndef _olamatrix_h
#define _olamatrix_h

#include "OLAVector.h"

class OLAMatrix {
public:
	OLAMatrix();
	OLAMatrix(int nRows, int nCols);
	OLAMatrix(const OLAMatrix& mat);

	virtual ~OLAMatrix();

	virtual void SafeRelease();
	virtual void Resize(int nRows, int nCols);

	// copy matrix
	virtual void operator=(const OLAMatrix& matrix);
	virtual void operator=(const double* data);
	virtual void operator=(double val);
	virtual void operator=(const OLAVector& vec);

	// scalar operations
	// add value 
	virtual void operator+=(double value);
	// add matrix
	virtual void operator+=(const OLAMatrix& matrix);

	// substract value
	virtual void operator-=(double value);
	// substract matrix
	virtual void operator-=(const OLAMatrix& matrix);

	// multiply value
	virtual void operator*=(double value);
	// multiply matrix
	virtual void operator*=(const OLAMatrix& matrix);

	// divide value
	virtual void operator/=(double value);
	// divide matrix
	virtual void operator/=(const OLAMatrix& matrix);

/*
	virtual void SetZero();
	virtual void SetIdentity();

	// transpose matrix
	virtual void Transpose();
	virtual void Transpose(OLAMatrix& matrix);

	// multiplication for square matrices
	virtual void Multiply(const OLAMatrix& matrix);

	// matrix vector multiplication
	virtual void Multiply(OLAVector& vec, OLAVector& res);

	// two operants
	virtual void Multiply(const OLAMatrix& matrix1, const OLAMatrix& matrix2);
	virtual void Subtract(const OLAMatrix& matrix1, const OLAMatrix& matrix2);
	virtual void Add(const OLAMatrix& matrix1, const OLAMatrix& matrix2);
	virtual void Cross(const OLAVector& vec1, const OLAVector& vec2);

	// invert matrix
	virtual void Inverse();
	virtual void Inverse(OLAMatrix& matrix);

	//matrix determinant
	virtual double Determinant();

	//matrix norms
	virtual double FrobeniusNorm();

	// complex functions
	virtual int Sqrt();
	virtual int Sqrt(OLAMatrix& matrix);

	virtual int Log();
	virtual int Log(OLAMatrix& matrix);

	virtual int Exp();
	virtual int Exp(OLAMatrix& matrix);

	virtual int Rank();
*/
	
	//
	// Element access
	//
	// value of element (r,c): row, column
	inline double operator()(int r = 0, int c = 0) const;

	// reference of element (r,c): row, column
	inline double& operator()(int r = 0, int c = 0);

    // matrix data
    double* data_;
    
    // rows
    int nRows_;    
    // columns
    int nCols_;

    // size
    int n_;
};




inline double OLAMatrix::operator()(int r, int c) const
{
   return data_[r+c*nRows_];
}

inline double& OLAMatrix::operator()(int r, int c)
{
   return data_[r+c*nRows_];
}


#endif