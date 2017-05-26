//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//


#ifndef _omllinearregression_h
#define _omllinearregression_h

#include "OLA/OLALinearAlgebra.h"

class OMLLinearRegression {
public:
	virtual void	Train(OLAVector* data, OLAVector& y, int n, double* weights = NULL);

	virtual double	Score(OLAVector& vec);

	virtual void	Save(FILE* fout);
	virtual void	Read(FILE* fin);

	virtual inline void operator=(const OMLLinearRegression& c);

public:

	OLAVector beta_;
	double beta0_;	
};
inline void OMLLinearRegression::operator=(const OMLLinearRegression& c)
{
	beta0_ = c.beta0_;
	beta_ = c.beta_;
}



#endif
