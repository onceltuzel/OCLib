//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//


#ifndef _omldecisionstump_h
#define _omldecisionstump_h

#include "OLA/OLALinearAlgebra.h"

class OMLDecisionStump {
public:
	virtual void	Train(OLAVector* data, int pn, int nn, double* weights=NULL, int nTrials=1);

	virtual int		Classify(OLAVector& vec);	
	virtual double	Score(OLAVector& vec);

	virtual void	Save(FILE* fout);
	virtual void	Read(FILE* fin);

	virtual inline void operator=(const OMLDecisionStump& c);

public:
	double sign_;
	double threshold_;
	int    dim_;
};
inline void OMLDecisionStump::operator=(const OMLDecisionStump& c)
{
	dim_ = c.dim_;
	sign_ = c.sign_;
	threshold_ = c.threshold_;
}



#endif
