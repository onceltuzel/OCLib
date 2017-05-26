//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//


#ifndef _ocvimage_h
#define _ocvimage_h

#include <cv.h>
#include <stdlib.h>
#include <stdio.h>


class OCVImage{
public:
	OCVImage();
	OCVImage(int width, int height, int dim = 1 , int depth = IPL_DEPTH_8U);
	OCVImage(const OCVImage& image);
	virtual ~OCVImage();

	//Image Initialization
	virtual void	Resize(int width, int height, int dim = 1 , int depth = IPL_DEPTH_8U);
	virtual void	Create(const unsigned char* buf, int width, int height, int dim = 1 , int depth = IPL_DEPTH_8U);
	virtual void	SafeRelease();

	virtual void	SetChannel(int c, OCVImage& cImage);
	virtual void	GetChannel(int c, OCVImage& cImage);

	//Image Access
	virtual inline unsigned char&	operator()(int x, int y, int d = 0);
	virtual inline unsigned char	operator()(int x, int y, int d = 0) const;
	virtual inline double&			D(int x, int y, int d = 0);
	virtual inline double			D(int x, int y, int d = 0) const;
	virtual inline float&			F(int x, int y, int d = 0);
	virtual inline const float		F(int x, int y, int d = 0) const;
	virtual inline int&				I(int x, int y, int d = 0);
	virtual inline int				I(int x, int y, int d = 0) const;

	//Generic element access
	virtual inline void*			P(int x, int y, int d = 0);
	virtual inline const void*		P(int x, int y, int d = 0) const;
	virtual inline void*			P(){return iplImage_->imageData;};
	virtual	inline const void*		P() const {return iplImage_->imageData;};
	//Object Access
	virtual inline operator	IplImage*();
	virtual inline operator const IplImage*() const { return iplImage_; };

	//Copy operators
	virtual void	operator=(IplImage* iplImage);
	virtual OCVImage&	operator=(const OCVImage& image);

	virtual void Display(const char* windowName) const;


	//Attributes
	virtual int		GetWidth() const;
	virtual int		GetHeight() const;
	virtual int		GetDim() const;
	virtual int		GetDepth() const;
	virtual int		GetSize() const;
	virtual char*	GetData();
	
	
	//data
	IplImage* iplImage_;	

	float*			fp_;
	double*			dp_;
	int*			ip_;
	unsigned char*	ucp_;
};


inline OCVImage::operator IplImage*()
{
	return iplImage_;
}

inline unsigned char& OCVImage::operator()(int x, int y, int d)
{
	assert(iplImage_->depth == IPL_DEPTH_8U);
	return (unsigned char&)(((unsigned char*)(iplImage_->imageData + iplImage_->widthStep*y))[x*iplImage_->nChannels+d]);
}

inline unsigned char OCVImage::operator()(int x, int y, int d) const
{
	assert(iplImage_->depth == IPL_DEPTH_8U);
	return (unsigned char)(((unsigned char*)(iplImage_->imageData + iplImage_->widthStep*y))[x*iplImage_->nChannels+d]);
}

inline int& OCVImage::I(int x, int y, int d)
{
	assert(iplImage_->depth == IPL_DEPTH_32S);
	return (int&)(((int*)(iplImage_->imageData + iplImage_->widthStep*y))[x*iplImage_->nChannels+d]);
}

inline int OCVImage::I(int x, int y, int d) const
{
	assert(iplImage_->depth == IPL_DEPTH_32S);
	return (int)(((int*)(iplImage_->imageData + iplImage_->widthStep*y))[x*iplImage_->nChannels+d]);
}

inline float& OCVImage::F(int x, int y, int d)
{
	assert(iplImage_->depth == IPL_DEPTH_32F);
	return (((float*)(iplImage_->imageData + iplImage_->widthStep*y))[x*iplImage_->nChannels+d]);
	//return fp_[iplImage_->widthStep*y/4 + x*iplImage_->nChannels+d];
}


inline const float OCVImage::F(int x, int y, int d) const
{
	assert(iplImage_->depth == IPL_DEPTH_32F);
	return (((float*)(iplImage_->imageData + iplImage_->widthStep*y))[x*iplImage_->nChannels+d]);
	//return fp_[iplImage_->widthStep*y/4 + x*iplImage_->nChannels+d];
}


inline double& OCVImage::D(int x, int y, int d)
{
	assert(iplImage_->depth == IPL_DEPTH_64F);
	return (double&)(((double*)(iplImage_->imageData + iplImage_->widthStep*y))[x*iplImage_->nChannels+d]);
}

inline double OCVImage::D(int x, int y, int d) const
{
	assert(iplImage_->depth == IPL_DEPTH_64F);
	return (double)(((double*)(iplImage_->imageData + iplImage_->widthStep*y))[x*iplImage_->nChannels+d]);
}

inline void* OCVImage::P(int x, int y, int d)
{
	return (void*)&(((char*)(iplImage_->imageData + iplImage_->widthStep*y))[(x*iplImage_->nChannels+d)*((iplImage_->depth & 0x0000FFFF) >> 3)]);
}

inline const void* OCVImage::P(int x, int y, int d) const
{
	return (void*)&(((char*)(iplImage_->imageData + iplImage_->widthStep*y))[(x*iplImage_->nChannels+d)*((iplImage_->depth & 0x0000FFFF) >> 3)]);
}


#endif