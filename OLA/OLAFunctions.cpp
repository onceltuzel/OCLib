//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//


#include "OLAFunctions.h"

#include "clapack.h"

#define OLAEPSILON 0.000000001
#define OLATHRESHOLD 10e-30



double OLAFunctions::CovarianceDistance(OLAMatrix& mat1, OLAMatrix& mat2)
{

	integer itype = 1;
	char jobz = 'N';
	char uplo = 'L';
	integer n = mat1.nRows_;
	integer lda = n;
	integer ldb = n;
	double* w = new double[n]; 
	double* work = new double[(n+2)*n];
	integer lwork = (n+2)*n;
	integer info;

	double* data1 = new double[n*n];
	double* data2 = new double[n*n];

	memcpy(data1, mat1.data_, sizeof(double)*n*n);
	memcpy(data2, mat2.data_, sizeof(double)*n*n);

	int i; 
	double dist = 0;
	double logscore;

	for (i=0 ; i<n ; i++)
	{
		data1[i*n+i] += OLAEPSILON;
		data2[i*n+i] += OLAEPSILON;
	}

	/*
	OLAMatrix tMatrix;
	tMatrix.Resize(n,n);
	OLALinearAlgebra::Identity(tMatrix);
	tMatrix *= OLAEPSILON;
	for (i=0 ; i<n*n ; i++)
	{
		data1[i] += tMatrix.data_[i];
		data2[i] += tMatrix.data_[i];
	}
	*/

	dsygv_(&itype, &jobz, &uplo, &n, data1, &lda, data2, &ldb, w, work, &lwork, &info);

	for (i=0 ; i<n ; i++)
	{
		w[i]+= OLATHRESHOLD;
		if (w[i])
		{
			logscore = log(w[i]);
			dist += logscore*logscore;
		}
	}

	dist = sqrt(dist);

	delete[] w;
	delete[] work;
	delete[] data1;
	delete[] data2;

	return dist;


}




void OLAFunctions::Mean(OLAMatrix& data, OLAVector& mean, int order, int nMax)
{
	int i, j;
	int count;
	OLALinearAlgebra::Zero(mean);


	switch (order)
	{
		case 0:
			count = (data.nCols_ < nMax) ?  data.nCols_ : nMax;
			for (i=0 ; i<count ; i++)
			{
				for (j=0 ; j<data.nRows_ ;j++)
				{
					mean(j) += data(j, i);
				}
			}
			mean /= count;
			break;
		case 1:
			count = (data.nRows_ < nMax) ?  data.nCols_ : nMax;
			for (i=0 ; i<count ; i++)
			{
				for (j=0 ; j<data.nCols_ ;j++)
				{
					mean(j) += data(i, j);
				}
			}
			mean /= count;
			break;
	}
}


void OLAFunctions::Mean(OLAVector* data, int n, OLAVector& mean)
{
	int i;
	OLALinearAlgebra::Zero(mean);
	
	for (i=0 ; i<n ; i++)
		mean += data[i];

	mean /= n;
}

void OLAFunctions::Mean(OLAVector* data, double* weights, int n, OLAVector& mean)
{
	int i, m;
	double sum;
	OLAVector vec;

	m = data[0].n_;

	vec.Resize(m);

	sum = 0;
	OLALinearAlgebra::Zero(mean);

	for (i=0 ; i<n ; i++)
	{
		sum += weights[i];
		vec = data[i];
		vec *= weights[i];
		mean += vec;
	}

	mean /= sum;
}

void OLAFunctions::Variance(OLAVector* data, int n, OLAVector& variance)
{
	int i, m;
	OLAVector mean;
	OLAVector dist;

	m = data[0].n_;
	mean.Resize(m);
	dist.Resize(m);

	Mean(data, n, mean);
	OLALinearAlgebra::Zero(variance);
	for (i=0 ; i<n ; i++)
	{
		OLALinearAlgebra::Subtract(mean, data[i], dist);
		dist *= dist;
		variance += dist;
	}
	variance /= n;
}

void OLAFunctions::Covariance(OLAVector* data, int n, OLAMatrix& covariance)
{
	int i, m;
	OLAVector mean;
	OLAVector dist;
	OLAMatrix cross;
	
	m = data[0].n_;
	mean.Resize(m);
	dist.Resize(m);
	cross.Resize(m, m);

	Mean(data, n, mean);
	OLALinearAlgebra::Zero(covariance);

	for (i=0 ; i<n ; i++)
	{
		OLALinearAlgebra::Subtract(mean, data[i], dist);
		OLALinearAlgebra::OuterProduct(dist, dist, cross);
		covariance += cross;
	}

	covariance /= n;
}

void OLAFunctions::Covariance(OLAVector* data, double* weights, int n, OLAMatrix& covariance)
{
	int i, m;
	OLAVector mean;
	OLAVector dist;
	OLAMatrix cross;
	double sum;

	m = data[0].n_;
	mean.Resize(m);
	dist.Resize(m);
	cross.Resize(m, m);

	Mean(data, weights, n, mean);

	sum = 0;
	OLALinearAlgebra::Zero(covariance);

	for (i=0 ; i<n ; i++)
	{
		sum += weights[i];
		OLALinearAlgebra::Subtract(mean, data[i], dist);
		OLALinearAlgebra::OuterProduct(dist, dist, cross);
		cross *= weights[i];
		covariance += cross;
	}

	covariance /= sum;
}

void OLAFunctions::SPDWeightedMean(OLAMatrix* data, double* weights, int n, OLAMatrix& initial, OLAMatrix& mean)
{
	int i, c;
	int d;

	OLAMatrix	sqrtmean;
	OLAMatrix	isqrtmean;
	OLAMatrix	cmean;

	OLAMatrix	tmatrix;
	OLAMatrix	tmatrix2;
	OLAMatrix	lmatrix;

	double weight;
	OLAMatrix	wmatrix;


	d = data[0].nRows_;

	isqrtmean.Resize(d, d);
	sqrtmean.Resize(d, d);
	tmatrix.Resize(d, d);
	tmatrix2.Resize(d, d);
	lmatrix.Resize(d, d);
	wmatrix.Resize(d, d);
	cmean.Resize(d, d);

	mean = initial;
	OLALinearAlgebra::Zero(cmean);
	//OLALinearAlgebra::Write(mean);

	c = 0;
	while(c < 10)
	{
		cmean = mean;
		OLALinearAlgebra::SPDSqrt(cmean, sqrtmean);
		OLALinearAlgebra::Inverse(sqrtmean, isqrtmean);
		//OLALinearAlgebra::Write(isqrtmean);

		OLALinearAlgebra::Zero(mean);
		weight = 0;
		for (i=0 ; i<n ; i++)
		{
			OLALinearAlgebra::Multiply(isqrtmean, data[i], tmatrix);
			OLALinearAlgebra::Multiply(tmatrix, isqrtmean, tmatrix2);
			//OLALinearAlgebra::Write(tmatrix2);
			OLALinearAlgebra::SPDLog(tmatrix2, lmatrix);
			//OLALinearAlgebra::Write(lmatrix);
			wmatrix = lmatrix;
			wmatrix *= weights[i];
			mean += wmatrix;
			weight += weights[i];
		}
		mean /= weight;
		//OLALinearAlgebra::Write(mean);

		OLALinearAlgebra::Exp(mean, tmatrix);
		OLALinearAlgebra::Multiply(sqrtmean, tmatrix, tmatrix2);
		OLALinearAlgebra::Multiply(tmatrix2, sqrtmean, mean);
		c++;
	}
}


void OLAFunctions::SPDMean(OLAMatrix* data, int n, OLAMatrix& initial, OLAMatrix& mean)
{
	int i, c;
	int d;

	OLAMatrix	sqrtmean;
	OLAMatrix	isqrtmean;
	OLAMatrix	cmean;

	OLAMatrix	tmatrix;
	OLAMatrix	tmatrix2;
	OLAMatrix	lmatrix;

	d = data[0].nRows_;

	isqrtmean.Resize(d, d);
	sqrtmean.Resize(d, d);
	tmatrix.Resize(d, d);
	tmatrix2.Resize(d, d);
	lmatrix.Resize(d, d);
	cmean.Resize(d, d);

	mean = initial;
	OLALinearAlgebra::Zero(cmean);
	//OLALinearAlgebra::Write(mean);

	c = 0;
	while(c < 10)
	{
		cmean = mean;
		OLALinearAlgebra::SPDSqrt(cmean, sqrtmean);
		OLALinearAlgebra::Inverse(sqrtmean, isqrtmean);
		//OLALinearAlgebra::Write(isqrtmean);

		OLALinearAlgebra::Zero(mean);
		for (i=0 ; i<n ; i++)
		{
			OLALinearAlgebra::Multiply(isqrtmean, data[i], tmatrix);
			OLALinearAlgebra::Multiply(tmatrix, isqrtmean, tmatrix2);
			//OLALinearAlgebra::Write(tmatrix2);
			OLALinearAlgebra::SPDLog(tmatrix2, lmatrix);
			//OLALinearAlgebra::Write(lmatrix);
			mean += lmatrix;
		}
		mean /= n;
		//OLALinearAlgebra::Write(mean);

		OLALinearAlgebra::Exp(mean, tmatrix);
		OLALinearAlgebra::Multiply(sqrtmean, tmatrix, tmatrix2);
		OLALinearAlgebra::Multiply(tmatrix2, sqrtmean, mean);
		c++;
	}
}
