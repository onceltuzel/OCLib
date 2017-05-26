//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//


#include "OML/OMLLinearMethods.h"
#include "OLA/OLAFunctions.h"


void OMLLinearMethods::LDATrain(OLAVector* data, double* weights, int pn, int nn, OLAVector& beta, double& beta0)
{
	int m;
	OLAVector pmean, nmean, vec;
	OLAMatrix pcov, ncov, cov, icov;
	double pw, nw;

	OLAMatrix tCov;

	m = data[0].n_;

	pmean.Resize(m);
	nmean.Resize(m);
	vec.Resize(m);
	pcov.Resize(m, m);
	ncov.Resize(m, m);
	cov.Resize(m, m);
	icov.Resize(m, m);

	OLAFunctions::Mean(data, weights, pn, pmean);
	OLAFunctions::Mean(&(data[pn]), &(weights[pn]), nn, nmean);

	OLAFunctions::Covariance(data, weights, pn, pcov);
	OLAFunctions::Covariance(&(data[pn]), &(weights[pn]), nn, ncov);

	pw = OLAFunctions::Sum(weights, pn);
	nw = OLAFunctions::Sum(&(weights[pn]), nn);

	pcov *= pw;
	ncov *= nw;

	OLALinearAlgebra::Add(pcov, ncov, cov);
	cov /= (pw+nw);

	OLALinearAlgebra::Inverse(cov, icov);

	//Compute beta
	OLALinearAlgebra::Subtract(pmean, nmean, vec);
	OLALinearAlgebra::Multiply(icov, vec, beta);

	//Compute beta0
	OLALinearAlgebra::Multiply(icov, pmean, vec);
	beta0 = OLALinearAlgebra::Dot(vec, pmean);
	OLALinearAlgebra::Multiply(icov, nmean, vec);
	beta0 -= OLALinearAlgebra::Dot(vec, nmean);
	beta0 /= 2;

}
