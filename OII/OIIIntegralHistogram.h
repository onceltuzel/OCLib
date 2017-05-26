//
//  Created by Oncel Tuzel.
//  Copyright © 2006 Oncel Tuzel. All rights reserved.
//

#ifndef _oiintegralhistogram_h
#define _oiintegralhistogram_h

#include "OCV/OCVImage.h"
#include "OCV/OCVBufferND.h"

class OIIIntegralHistogram {
public:
	OIIIntegralHistogram() {};
	OIIIntegralHistogram(int width, int height, int dim) {Resize(width, height, dim);};
	~OIIIntegralHistogram() {};

	virtual void Resize(int width, int height, int dim);
	virtual void Construct(OCVImage& image);

	virtual inline void Sum(int x, int y, int width, int height, double* data);

	inline operator	OCVBufferND*();

protected:

	OCVBufferND ihistogram_;
};

inline OIIIntegralHistogram::operator OCVBufferND*()
{
	return &ihistogram_;
}

inline void OIIIntegralHistogram::Sum(int x, int y, int width, int height, double* data)
{
	int d;

	for (d=0 ; d<ihistogram_.GetDim(); d++)
	{
		data[d] = ihistogram_(x, y, d);
		data[d] += ihistogram_(x+width, y+height, d);
		data[d] -= ihistogram_(x+width, y, d);
		data[d] -= ihistogram_(x, y+height, d);
	}

}

#endif