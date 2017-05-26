//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//


#ifndef _omlmultilinearregression_h
#define _omlmultilinearregression_h

#include "OLA/OLALinearAlgebra.h"

class OMLMultiLinearRegression {
public:
	OMLMultiLinearRegression();

	virtual void	Train(OLAVector* data, OLAVector* y, int n, double* weights = NULL);
	virtual double	Error(OLAVector* data, OLAVector* y, int n, double* weights = NULL);

	virtual void	Score(OLAVector& vec, OLAVector& score);

	virtual void	Save(FILE* fout);
	virtual void	Read(FILE* fin);

	virtual inline void operator=(const OMLMultiLinearRegression& c);

public:

	OLAMatrix beta_;
	OLAVector beta0_;
};
inline void OMLMultiLinearRegression::operator=(const OMLMultiLinearRegression& c)
{
	beta0_ = c.beta0_;
	beta_ = c.beta_;
}



#endif
