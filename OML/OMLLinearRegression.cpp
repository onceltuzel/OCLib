//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//


#include "OML/OMLLinearRegression.h"
#include "OLA/OLAFunctions.h"



void OMLLinearRegression::Save(FILE* fout)
{
	OLALinearAlgebra::Write(fout, beta_);
	fprintf(fout, "%.20E\n", beta0_);
}

void OMLLinearRegression::Read(FILE* fin)
{
	OLALinearAlgebra::Read(fin, beta_);
	fscanf(fin, "%lf", &beta0_);

}

void OMLLinearRegression::Train(OLAVector* data, OLAVector& y, int n, double* weights)
{

}

double OMLLinearRegression::Score(OLAVector& vec)
{
	return OLALinearAlgebra::Dot(beta_, vec) + beta0_;
}

