//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//

#include "OCVBufferND.h"
#include <string.h>
#include <stdio.h>

OCVBufferND::OCVBufferND()
{
	buffer_ = NULL;
	width_ = 0;
	height_ = 0;
	dim_ = 0;
}

OCVBufferND::OCVBufferND(int width, int height, int dim)
{
	width_ = width;
	height_ = height;
	dim_ = dim;

	buffer_ = new double[width*height*dim];
	memset (buffer_, 0, width*height*dim*sizeof(double));
}

OCVBufferND::OCVBufferND(const OCVBufferND& image) 
{	
	buffer_ = NULL;
	width_ = 0;
	height_ = 0;
	dim_ = 0;

	*this = image;
}

void OCVBufferND::operator=(const OCVBufferND& image)
{
	if (GetWidth() != image.GetWidth() || GetHeight() != image.GetHeight()  || GetDim() != image.GetDim())
	{
		Resize(image.GetWidth(), image.GetHeight(), image.GetDim());
	}

	memcpy(buffer_, image, sizeof(double)*width_*height_*dim_);	
}

OCVBufferND::~OCVBufferND()
{
	SafeRelease();
}

void OCVBufferND::Resize(int width, int height, int dim)
{
	SafeRelease();

	width_ = width;
	height_ = height;
	dim_ = dim;

	buffer_ = new double[width*height*dim];
	if (buffer_ == NULL)
		printf("Memory error!!! - Requested bytes : %d\n", width*height*dim*sizeof(double));
	memset (buffer_, 0, width*height*dim*sizeof(double));
}

void OCVBufferND::SafeRelease()
{
	if (buffer_)
		delete[] buffer_;

	buffer_ = NULL;
}



/*   
OCVBufferND::OCVBufferND()
{
	buffer_ = NULL;
}

OCVBufferND::OCVBufferND(int width, int height, int dim)
{
	width_ = width;
	height_ = height;
	dim_ = dim;

	buffer_ = new double*[width*height];
	for (int i=0 ; i<width_*height_ ; i++)
	{
		buffer_[i] = new double[dim];
		memset (buffer_[i], 0, dim);
	}
	
}

OCVBufferND::~OCVBufferND()
{
	SafeRelease();
}

void OCVBufferND::Resize(int width, int height, int dim)
{
	SafeRelease();

	width_ = width;
	height_ = height;
	dim_ = dim;

	buffer_ = new double*[width*height];
	for (int i=0 ; i<width_*height_ ; i++)
	{
		buffer_[i] = new double[dim];
		memset (buffer_[i], 0, dim);
	}
}

void OCVBufferND::SafeRelease()
{
	if (buffer_)
	{
		for (int i=0 ; i<width_*height_ ; i++)
		{
			delete[] buffer_[i];
			buffer_[i] = NULL;
		}
	}

	delete[] buffer_;
	buffer_ = NULL;
}
*/