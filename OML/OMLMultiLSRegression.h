// Created by: Oncel Tuzel 
// Date: 01/12/2005

#ifndef _omlmultilsregression_h
#define _omlmultilsregression_h

#include "OLA/OLALinearAlgebra.h"
#include "OMLMultiLinearRegression.h"

class OMLMultiLSRegression : public OMLMultiLinearRegression{
public:
	virtual void	Train(OLAVector* data, OLAVector* y, int n, double* weights = NULL);


};


#endif
