//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//

#include "OCVImage.h"
#include <highgui.h>


OCVImage::OCVImage()
{
	iplImage_ = NULL;
}

OCVImage::OCVImage(int width, int height, int dim , int depth)
{
	CvSize size;

	size.width = width;
	size.height = height;

	iplImage_ = cvCreateImage(size, depth, dim);
	cvSetZero(iplImage_);

	fp_ = (float*) iplImage_->imageData;
}



OCVImage::OCVImage(const OCVImage& image)
{
	iplImage_ = NULL;
	*this = image;
}

OCVImage::~OCVImage()
{
	SafeRelease();
}

void OCVImage::SafeRelease()
{
	if (iplImage_)
		cvReleaseImage(&iplImage_);

	iplImage_ = NULL;
}

void OCVImage::Resize(int width, int height, int dim , int depth)
{
	CvSize size;

	SafeRelease();

	size.width = width;
	size.height = height;

	iplImage_ = cvCreateImage(size, depth, dim);
	cvSetZero(iplImage_);

	fp_ = (float*) iplImage_->imageData;
}

void OCVImage::Create(const unsigned char* buf, int width, int height, int dim, int depth)
{
	Resize(width, height, dim, depth);
	memcpy(iplImage_->imageData, buf, sizeof(unsigned char)*width*height*dim);
}


void OCVImage::operator=(IplImage* iplImage)
{
	SafeRelease();
	iplImage_ = iplImage;
}


OCVImage& OCVImage::operator=(const OCVImage& image)
{
	if (!iplImage_ || image.GetWidth() != GetWidth() || image.GetHeight() != GetHeight() || 
		image.GetDim() != GetDim() || image.GetDepth() != GetDepth())
	{
		SafeRelease();
		iplImage_ = cvCloneImage(image.iplImage_);
	}
	else
	{
		cvCopy(image.iplImage_, iplImage_);
	}

	return *this;
}




//Attributes
int	OCVImage::GetWidth() const
{
	return iplImage_->width;
}

int	OCVImage::GetHeight() const
{
	return iplImage_->height;
}

int	OCVImage::GetDim() const
{
	return iplImage_->nChannels;
}

int	OCVImage::GetDepth() const
{
	//return ((iplImage_->depth & 0x0000FFFF) >> 3);
	return iplImage_->depth;//((iplImage_->depth & 0x0000FFFF) >> 3);
}

int	OCVImage::GetSize() const
{
	return iplImage_->width*iplImage_->height*iplImage_->nChannels*((iplImage_->depth & 0x0000FFFF) >> 3);
}

char* OCVImage::GetData()
{
	return iplImage_->imageData;
}



void OCVImage::SetChannel(int c, OCVImage& cImage)
{
	switch(iplImage_->depth)
	{
	case IPL_DEPTH_8U:
		{
#pragma omp parallel for
			for (int y=0 ; y<iplImage_->height ; y++)
			{
				for (int x=0 ; x<iplImage_->width ; x++)
				{
					operator()(x,y,c) = cImage(x,y);
				}
			}
		}
		break;
	case IPL_DEPTH_32S:
		{
#pragma omp parallel for
			for (int y=0 ; y<iplImage_->height ; y++)
			{
				for (int x=0 ; x<iplImage_->width ; x++)
				{
					I(x,y,c) = cImage.I(x,y);
				}
			}
		}
		break;
	case IPL_DEPTH_32F:
		{
#pragma omp parallel for
			for (int y=0 ; y<iplImage_->height ; y++)
			{
				for (int x=0 ; x<iplImage_->width ; x++)
				{
					F(x,y,c) = cImage.F(x,y);
				}
			}
		}
		break;
	case IPL_DEPTH_64F:
		{
#pragma omp parallel for
			for (int y=0 ; y<iplImage_->height ; y++)
			{
				for (int x=0 ; x<iplImage_->width ; x++)
				{
					D(x,y,c) = cImage.D(x,y);
				}
			}
		}
		break;	
	}
	


}

void OCVImage::GetChannel(int c, OCVImage& cImage)
{
	switch(iplImage_->depth)
	{
	case IPL_DEPTH_8U:
		{
#pragma omp parallel for
			for (int y=0 ; y<iplImage_->height ; y++)
			{
				for (int x=0 ; x<iplImage_->width ; x++)
				{
					cImage(x,y) = operator()(x,y,c);
				}
			}
		}
		break;
	case IPL_DEPTH_32S:
		{
#pragma omp parallel for
			for (int y=0 ; y<iplImage_->height ; y++)
			{
				for (int x=0 ; x<iplImage_->width ; x++)
				{
					cImage.I(x,y) = I(x,y,c);
				}
			}
		}
		break;
	case IPL_DEPTH_32F:
		{
#pragma omp parallel for
			for (int y=0 ; y<iplImage_->height ; y++)
			{
				for (int x=0 ; x<iplImage_->width ; x++)
				{
					cImage.F(x,y) = F(x,y,c);
				}
			}
		}
		break;
	case IPL_DEPTH_64F:
		{
#pragma omp parallel for
			for (int y=0 ; y<iplImage_->height ; y++)
			{
				for (int x=0 ; x<iplImage_->width ; x++)
				{
					cImage.D(x,y) = D(x,y,c);
				}
			}
		}
		break;	
	}

}

void OCVImage::Display(const char* windowName) const
{
	cvNamedWindow(windowName, 1);
	cvShowImage(windowName, *this);
}
