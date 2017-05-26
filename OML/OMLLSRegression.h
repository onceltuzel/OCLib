//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//


#ifndef _omllsregression_h
#define _omllsregression_h

#include "OLA/OLALinearAlgebra.h"
#include "OMLLinearRegression.h"

class OMLLSRegression : public OMLLinearRegression{
public:
	virtual void	Train(OLAVector* data, OLAVector& y, int n, double* weights = NULL);


};


#endif
