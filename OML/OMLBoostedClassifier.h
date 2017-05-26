//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//


#ifndef _omlboostedclassifier_h
#define _omlboostedclassifier_h

#include "OML/OMLLDAClassifier.h"

class OMLBoostedClassifier {
public:
	OMLBoostedClassifier();
	virtual ~OMLBoostedClassifier();

	virtual void	Train(OLAVector* data, double* weights, int nPos, int nNeg, int nClassifiers);

	virtual int		Classify(OLAVector& vec);
	virtual double	Score(OLAVector& vec);

	virtual void	Save(FILE* fout);
	virtual void	Read(FILE* fin);

	virtual inline void operator=(const OMLBoostedClassifier& c);

	virtual void	SafeRelease();


private:
	int					nClassifiers_;
	double*				weights_;
	OMLLDAClassifier*	classifiers_;

	virtual void Normalize(double* data, int n);
};

inline void OMLBoostedClassifier::operator=(const OMLBoostedClassifier& c)
{
	if (nClassifiers_ != c.nClassifiers_)
	{
		SafeRelease();
		nClassifiers_ = c.nClassifiers_;

		classifiers_ = new OMLLDAClassifier[nClassifiers_];
		weights_ = new double[nClassifiers_];

	}
	memcpy(weights_, c.weights_, sizeof(double)*nClassifiers_);

	for (int i=0 ; i<nClassifiers_ ; i++)
	{
		classifiers_[i] = c.classifiers_[i];		
	}
}


#endif
