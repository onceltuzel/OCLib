//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//


#ifndef _omllinearclassifier_h
#define _omllinearclassifier_h

#include "OLA/OLALinearAlgebra.h"

class OMLLinearClassifier {
public:
	virtual void	Train(OLAVector* data, double* weights, int pn, int nn);

	virtual int		Classify(OLAVector& vec);
	virtual double	Score(OLAVector& vec);

	virtual void	Save(FILE* fout);
	virtual void	Read(FILE* fin);

	virtual inline void operator=(const OMLLinearClassifier& c);

public:

	OLAVector beta_;
	double beta0_;	
};
inline void OMLLinearClassifier::operator=(const OMLLinearClassifier& c)
{
	beta0_ = c.beta0_;
	beta_ = c.beta_;
}



#endif
