//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//


#ifndef _OMLDecisionStumpPW_h
#define _OMLDecisionStumpPW_h

#include "OLA/OLALinearAlgebra.h"

class OMLDecisionStumpPW {
public:
	virtual void	Train(OLAVector* data, int pn, int nn, double* weights=NULL, int nTrials=1);

	virtual int		Classify(OLAVector& vec);	
	virtual double	Score(OLAVector& vec);

	virtual void	Save(FILE* fout);
	virtual void	Read(FILE* fin);

	virtual inline void operator=(const OMLDecisionStumpPW& c);

public:
	double sign_;

	double threshold_;

	int    dim1_;
	int    dim2_;
};
inline void OMLDecisionStumpPW::operator=(const OMLDecisionStumpPW& c)
{
	dim1_ = c.dim1_;
	dim2_ = c.dim2_;

	threshold_ = c.threshold_;

	sign_ = c.sign_;
}



#endif
