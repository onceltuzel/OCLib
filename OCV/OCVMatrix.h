//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//


#include <cv.h>

#ifndef _OCVMatrix_h
#define _OCVMatrix_h


class OCVMatrix{
public:
	OCVMatrix();
	OCVMatrix(int rows, int cols, int depth = CV_8UC1);
	~OCVMatrix();

	//Image Initialization
	void	Resize(int rows, int cols, int depth = CV_8UC1);
	void	SafeRelease();

	//Image Access
	inline unsigned char&	operator()(int r, int c);
	inline double&			D(int r, int c);
	inline float&			F(int r, int c);
	inline int&				I(int r, int c);

	//Generic element access
	inline void*			P(int r, int c);

	//Object Access
	inline operator	CvMat*();

	//Copy operators
	void	operator=(CvMat* cvMatrix);
	void	operator=(OCVMatrix& matrix);
		
	CvMat* cvMatrix_;
	
};

inline OCVMatrix::operator	CvMat*()
{
	return cvMatrix_;
}

inline unsigned char& OCVMatrix::operator()(int r, int c)
{
	return ((unsigned char*)(cvMatrix_->data.ptr + cvMatrix_->step*r))[c];
}

inline int& OCVMatrix::I(int r, int c)
{
	return ((int*)(cvMatrix_->data.ptr + cvMatrix_->step*r))[c];
}

inline float& OCVMatrix::F(int r, int c)
{
	return ((float*)(cvMatrix_->data.ptr + cvMatrix_->step*r))[c];
}

inline double& OCVMatrix::D(int r, int c)
{
	return ((double*)(cvMatrix_->data.ptr + cvMatrix_->step*r))[c];
}


#endif