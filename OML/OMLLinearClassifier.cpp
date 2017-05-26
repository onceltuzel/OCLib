//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//


#include "OML/OMLLinearClassifier.h"
#include "OLA/OLAFunctions.h"



void OMLLinearClassifier::Save(FILE* fout)
{
	OLALinearAlgebra::Write(fout, beta_);
	fprintf(fout, "%.20E\n", beta0_);
}

void OMLLinearClassifier::Read(FILE* fin)
{
	OLALinearAlgebra::Read(fin, beta_);
	fscanf(fin, "%lf\n", &beta0_);

}

void OMLLinearClassifier::Train(OLAVector* data, double* weights, int pn, int nn)
{

}

int OMLLinearClassifier::Classify(OLAVector& vec)
{
	return ((OLALinearAlgebra::Dot(beta_, vec) - beta0_)  > 0);
}

double OMLLinearClassifier::Score(OLAVector& vec)
{
	return OLALinearAlgebra::Dot(beta_, vec) - beta0_;
}

