//
//  Created by Oncel Tuzel.
//  Copyright © 2006 Oncel Tuzel. All rights reserved.
//

#ifndef _oiintegralmgnthistogram_h
#define _oiintegralmgnthistogram_h

#include "OII/OIIIntegralHistogram.h"
#include "OII/OIIIntegralImage.h"
#include "OCV/OCVImage.h"
#include "OCV/OCVBufferND.h"

class OIIIntegralMgntHistogram : public OIIIntegralHistogram{
public:
	virtual ~OIIIntegralMgntHistogram() {};

	virtual void Resize(int width, int height, int dim);
	virtual void Construct(OCVImage& image, OCVImage& mgnt);
	virtual inline void Sum(int x, int y, int width, int height, double* data, double& mgnt);

private:

	OIIIntegralImage mgnt_;
};

inline void OIIIntegralMgntHistogram::Sum(int x, int y, int width, int height, double* data, double& mgnt)
{
	OIIIntegralHistogram::Sum(x, y, width, height, data);
	mgnt = mgnt_.Sum(x, y, width, height);
}


#endif