//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//


#include "OCVImageND.h"


OCVImageND::OCVImageND()
{
	images_ = NULL;
	time_ = 0;
}

OCVImageND::OCVImageND(int time, int width, int height, int dim, int depth)
{
	int i;

	time_ = time;
	images_ = new OCVImage[time_];

	for (i=0 ; i<time_ ; i++)
		images_[i].Resize(width, height, dim, depth);
}

OCVImageND::~OCVImageND()
{
	SafeRelease();
}

void OCVImageND::Resize(int time)
{
	SafeRelease();

	time_ = time;
	images_ = new OCVImage[time_];
}


void OCVImageND::Resize(int time, int width, int height, int dim, int depth)
{
	int i;

	SafeRelease();

	time_ = time;
	images_ = new OCVImage[time_];

	for (i=0 ; i<time_ ; i++)
		images_[i].Resize(width, height, dim, depth);
}

void OCVImageND::SafeRelease()
{
	if (images_)
		delete[] images_;

	images_ = NULL;
}

void OCVImageND::operator=(OCVImageND& image)
{
	int i;
	if (!images_ || GetTime() != image.GetTime() || GetWidth() != image.GetWidth() || GetHeight() != image.GetHeight()||
		images_[0].GetDim() != image(0)->GetDim() || images_[0].GetDepth() != image(0)->GetDepth())
	{
		Resize(image.GetTime(), image.GetWidth(), image.GetHeight(), image(0)->GetDim(), image(0)->GetDepth());
	}

	for (i=0 ; i<time_ ; i++)
		cvCopy(*(image(i)), images_[i]);
}

