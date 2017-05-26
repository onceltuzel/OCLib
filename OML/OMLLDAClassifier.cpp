//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//


#include "OML/OMLLDAClassifier.h"
#include "OLA/OLAFunctions.h"

void OMLLDAClassifier::Train(OLAVector* data, double* weights, int pn, int nn)
{
	int m;
	OLAVector pmean, nmean, vec;
	OLAMatrix pcov, ncov, cov, icov;
	OLAMatrix identity;
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

	identity.Resize(m, m);
	OLALinearAlgebra::Identity(identity);
	identity *= 1e-10;

	beta_.Resize(m);

	OLAFunctions::Mean(data, weights, pn, pmean);
	OLAFunctions::Mean(&(data[pn]), &(weights[pn]), nn, nmean);

	OLAFunctions::Covariance(data, weights, pn, pcov);
	OLAFunctions::Covariance(&(data[pn]), &(weights[pn]), nn, ncov);

	pw = OLAFunctions::Sum(weights, pn);
	nw = OLAFunctions::Sum(&(weights[pn]), nn);
	//printf("%f %f %f\n",pw, nw, pw+nw);

	//pcov += identity;
	//ncov += identity;

	pcov *= pw;
	ncov *= nw;

	OLALinearAlgebra::Add(pcov, ncov, cov);
	cov /= (pw+nw);

	OLALinearAlgebra::PInverse(cov, icov);

	//Compute beta_
	OLALinearAlgebra::Subtract(pmean, nmean, vec);
	OLALinearAlgebra::Multiply(icov, vec, beta_);

	//Compute beta0_
	OLALinearAlgebra::Multiply(icov, pmean, vec);
	beta0_ = OLALinearAlgebra::Dot(vec, pmean);
	OLALinearAlgebra::Multiply(icov, nmean, vec);
	beta0_ -= OLALinearAlgebra::Dot(vec, nmean);
	beta0_ = beta0_/2  - log(pw/(pw+nw)) + log(nw/(pw+nw));

	double norm = OLALinearAlgebra::Norm(beta_);
	beta_ /= norm;
	beta0_ /= norm;
}



