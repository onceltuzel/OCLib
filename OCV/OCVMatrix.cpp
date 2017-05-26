//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//


#include "OCVMatrix.h"

OCVMatrix::OCVMatrix()
{
	cvMatrix_ = NULL;
}

OCVMatrix::OCVMatrix(int rows, int cols, int depth)
{
	cvMatrix_ = cvCreateMat(rows, cols, depth);
}


OCVMatrix::~OCVMatrix()
{
	SafeRelease();
}

void OCVMatrix::SafeRelease()
{
	if (cvMatrix_)
		cvReleaseMat(&cvMatrix_);

	cvMatrix_ = NULL;
}

void OCVMatrix::Resize(int rows, int cols, int depth)
{
	SafeRelease();
	cvMatrix_ = cvCreateMat(rows, cols, depth);
}


void OCVMatrix::operator=(CvMat* cvMatrix)
{
	SafeRelease();
	cvMatrix_ = cvMatrix;
}


void OCVMatrix::operator=(OCVMatrix& matrix)
{
	SafeRelease();

	cvMatrix_ = cvCloneMat(matrix.cvMatrix_);
}


