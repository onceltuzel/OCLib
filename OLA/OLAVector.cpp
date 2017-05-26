//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//


#include "OLAVector.h"

OLAVector::OLAVector()
{
	data_ = NULL;	
	n_ = 0;
}

OLAVector::OLAVector(int n)
{
	n_ = n;

	data_ = new double[n_];
	memset(data_, 0, n_*sizeof(double));
}


OLAVector::OLAVector(const OLAVector& vec)
{
	n_ = vec.n_;
	data_ = new	double[n_];
	memcpy(data_, vec.data_, n_*sizeof(double));
}

OLAVector::~OLAVector()
{
	SafeRelease();
}

void OLAVector::SafeRelease()
{
	if (data_)
		delete[] data_;

	data_ = NULL;
}

void OLAVector::Resize(int n)
{
	SafeRelease();
	n_ = n;

	data_ = new double[n_];
	memset(data_, 0, n_*sizeof(double));
}


