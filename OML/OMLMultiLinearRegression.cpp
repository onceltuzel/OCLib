//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//


#include "OML/OMLMultiLinearRegression.h"
#include "OLA/OLAFunctions.h"


OMLMultiLinearRegression::OMLMultiLinearRegression()
{
}


void OMLMultiLinearRegression::Save(FILE* fout)
{
	OLALinearAlgebra::Write(fout, beta_);
	OLALinearAlgebra::Write(fout, beta0_);
}

void OMLMultiLinearRegression::Read(FILE* fin)
{
	OLALinearAlgebra::Read(fin, beta_);
	OLALinearAlgebra::Read(fin, beta0_);
}

void OMLMultiLinearRegression::Train(OLAVector* data, OLAVector* y, int n, double* weights)
{

}


double OMLMultiLinearRegression::Error(OLAVector* data, OLAVector* y, int n, double* weights)
{
	int i;
	double error;
	OLAVector response;

	response.Resize(y[0].Size());

	error = 0;
	for (i=0 ; i<n ; i++)
	{
		Score(data[i], response);
		response -= y[i];
		error += OLALinearAlgebra::Dot(response, response);
	}

	return error;
}


void OMLMultiLinearRegression::Score(OLAVector& vec, OLAVector& score)
{
	OLALinearAlgebra::MultiplyAdd(beta_, vec, beta0_, score);
}

