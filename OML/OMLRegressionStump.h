//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//


#ifndef _omlregressionstump_h
#define _omlregressionstump_h

#include "OLA/OLALinearAlgebra.h"

class OMLRegressionStump {
public:
	virtual void	Train(OLAVector* data, OLAVector& y, int n, double* weights = NULL, int nTrials = 1);

	virtual double	Score(OLAVector& vec);

	virtual void	Save(FILE* fout);
	virtual void	Read(FILE* fin);

	virtual inline void operator=(const OMLRegressionStump& c);

public:
	double a_;
	double b_;
	double threshold_;
	int    dim_;
};
inline void OMLRegressionStump::operator=(const OMLRegressionStump& c)
{
	a_ = c.a_;
	b_ = c.b_;
	dim_ = c.dim_;
	threshold_ = c.threshold_;
}



#endif
