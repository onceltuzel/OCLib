// Created by: Oncel Tuzel 
// Date: 01/12/2005

#include "OML/OMLLSVMClassifier.h"
#include "OLA/OLAFunctions.h"
#include "SVM/svm_learner.h"


void OMLLSVMClassifier::Train(OLAVector* data, double* weights, int pn, int nn, char* parameters)
{
	int i;
	int n, d;
	double**	infeatures;
	double*		inlabels;

	n = pn + nn;
	d = data[0].n_;
	beta_.Resize(d);

	infeatures = new double*[n];
	inlabels = new double[n];

	for (i=0 ; i<n ; i++)
		infeatures[i] = data[i].data_;
	for (i=0 ; i<pn ; i++)
		inlabels[i] = 1.0;
	for (i=pn ; i<n ; i++)
		inlabels[i] = -1.0;

	SVMLearner::learnLinearSVM(parameters, infeatures, inlabels, weights, pn, nn, d, beta_.data_, &beta0_);

	double norm = OLALinearAlgebra::Norm(beta_);
	beta_ /= norm;
	beta0_ /= norm;

	delete[] inlabels;
	delete[] infeatures;
}



