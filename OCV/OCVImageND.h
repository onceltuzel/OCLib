//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//


#ifndef _ocvimagend_h
#define _ocvimagend_h

#include "OCVImage.h"

class OCVImageND{
public:
	OCVImageND();
	OCVImageND(int time, int width, int height, int dim, int depth = IPL_DEPTH_8U);
	~OCVImageND();

	void	Resize(int time);
	void	Resize(int time, int width, int height, int dim, int depth = IPL_DEPTH_8U);
	void	SafeRelease();

	inline int GetWidth();
	inline int GetHeight();
	inline int GetTime();


	inline OCVImage*	operator()(int t);
	inline unsigned char&	operator()(int t, int x, int y, int d = 0);
	inline double&			D(int t, int x, int y, int d = 0);
	inline float&			F(int t, int x, int y, int d = 0);
	inline int&				I(int t, int x, int y, int d = 0);

	void	operator=(OCVImageND& image);

private:
	int time_;
	OCVImage* images_;
};


inline int OCVImageND::GetWidth()
{
	return images_[0].GetWidth();
}

inline int OCVImageND::GetHeight()
{
	return images_[0].GetHeight();
}

inline int OCVImageND::GetTime()
{
	return time_;
}


inline OCVImage* OCVImageND::operator()(int t)
{
	return &images_[t];
}

inline unsigned char& OCVImageND::operator()(int t, int x, int y, int d)
{
	return images_[t](x, y, d);
}

inline int& OCVImageND::I(int t, int x, int y, int d)
{
	return images_[t].I(x, y, d);
}


inline float& OCVImageND::F(int t, int x, int y, int d)
{
	return images_[t].F(x, y, d);
}

inline double& OCVImageND::D(int t, int x, int y, int d)
{
	return images_[t].D(x, y, d);
}

/*
inline float& OCVImage::F(int x, int y, int d)
{
	return (float&)(((float*)(iplImage_->imageData + iplImage_->widthStep*y))[x*iplImage_->nChannels+d]);
}


inline double& OCVImage::D(int x, int y, int d)
{
	return (double&)(((double*)(iplImage_->imageData + iplImage_->widthStep*y))[x*iplImage_->nChannels+d]);
}

inline void* OCVImage::P(int x, int y, int d)
{
	return (void*)&(((char*)(iplImage_->imageData + iplImage_->widthStep*y))[(x*iplImage_->nChannels+d)*((iplImage_->depth & 0x0000FFFF) >> 3)]);
}
*/

#endif