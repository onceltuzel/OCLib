//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//

#ifndef _olafunctions_h
#define _olafunctions_h

#include "OLAVector.h"
#include "OLAMatrix.h"
#include "OLALinearAlgebra.h"


class OLAFunctions {
public:
	//Distances

	inline static double Chi2(OLAVector& vec1, OLAVector& vec2); //L2 distance

	inline static double Dist(OLAMatrix& mat1, OLAMatrix& mat2); //L2 distance
	inline static double Dist2(OLAMatrix& mat1, OLAMatrix& mat2); //L2 distance

	inline static double Dist(OLAVector& vec1, OLAVector& vec2); //L2 distance
	inline static double Dist1(OLAVector& vec1, OLAVector& vec2); //L1 distance
	inline static double Dist2(OLAVector& vec1, OLAVector& vec2); //Squared L2 distance
	inline static double ScaledDistance(OLAVector& vec1, OLAVector& vec2, OLAVector& scale); //Scaled distance
	inline static double ScaledDistance2(OLAVector& vec1, OLAVector& vec2, OLAVector& scale); //Squared scaled distance
	inline static double MahalanobisDistance(OLAVector& vec1, OLAVector& vec2, OLAMatrix& covariance); //Scaled distance
	inline static double MahalanobisDistance2(OLAVector& vec1, OLAVector& vec2, OLAMatrix& covariance); //Squared scaled distance

	static double CovarianceDistance(OLAMatrix& mat1, OLAMatrix& mat2); //Covariance distance

	static void SPDMean(OLAMatrix* data, int n, OLAMatrix& initial, OLAMatrix& mean);
	static void SPDWeightedMean(OLAMatrix* data, double* weights, int n, OLAMatrix& initial, OLAMatrix& mean);

	static void Mean(OLAVector* data, int n, OLAVector& mean);
	static void Variance(OLAVector* data, int n, OLAVector& variance);
	static void Mean(OLAVector* data, double* weights, int n, OLAVector& mean);
	static void Covariance(OLAVector* data, int n, OLAMatrix& covariance);
	static void Covariance(OLAVector* data, double* weights, int n, OLAMatrix& covariance);

	static void Mean(OLAMatrix& data, OLAVector& mean, int order = 0, int nMax = 1e+10);

	inline static double Sum(double* data, int n);
	inline static double Sum(OLAVector& vec);

};

inline double OLAFunctions::Sum(OLAVector& vec)
{
	int i;
	double sum = 0;
	for (i=0 ; i<vec.n_ ; i++)
		sum += vec(i);

	return sum;
}

 
inline double OLAFunctions::Sum(double* data, int n)
{
	int i;
	double sum = 0;
	for (i=0 ; i<n ; i++)
		sum += data[i];

	return sum;
}

inline double OLAFunctions::Dist(OLAMatrix& mat1, OLAMatrix& mat2)
{
	return (double) sqrt(Dist2(mat1, mat2));
}


inline double OLAFunctions::Dist(OLAVector& vec1, OLAVector& vec2)
{
	return (double) sqrt(Dist2(vec1, vec2));
}

inline double OLAFunctions::Chi2(OLAVector& vec1, OLAVector& vec2)
{
	int i;
	double dis;
	double sum;
	double dist = 0;
	double* data1 = vec1.data_;
	double* data2 = vec2.data_;

	for (i=0 ; i<vec1.n_ ; i++)
	{
		dis = (data1[i] - data2[i]);
		sum = (data1[i] + data2[i]);
		if (dis > 0.0000001)
		{
			dist += (dis*dis)/sum;
		}
	}

	return dist;
}


inline double OLAFunctions::Dist1(OLAVector& vec1, OLAVector& vec2)
{
	int i;
	double val;
	double dist = 0;
	double* data1 = vec1.data_;
	double* data2 = vec2.data_;

	for (i=0 ; i<vec1.n_ ; i++)
	{
		val = (data1[i] - data2[i]);
		dist += (double) fabs(val);
	}

	return dist;
}

inline double OLAFunctions::Dist2(OLAMatrix& mat1, OLAMatrix& mat2)
{
	int i;
	double val;
	double dist = 0;
	double* data1 = mat1.data_;
	double* data2 = mat2.data_;

	for (i=0 ; i<mat1.n_ ; i++)
	{
		val = (data1[i] - data2[i]);
		dist += val*val;
	}

	return dist;
}


inline double OLAFunctions::Dist2(OLAVector& vec1, OLAVector& vec2)
{
	int i;
	double val;
	double dist = 0;
	double* data1 = vec1.data_;
	double* data2 = vec2.data_;

	for (i=0 ; i<vec1.n_ ; i++)
	{
		val = (data1[i] - data2[i]);
		dist += val*val;
	}

	return dist;
}

inline double OLAFunctions::ScaledDistance(OLAVector& vec1, OLAVector& vec2, OLAVector& scale)
{
	return (double) sqrt(ScaledDistance2(vec1, vec2, scale));
}

inline double OLAFunctions::ScaledDistance2(OLAVector& vec1, OLAVector& vec2, OLAVector& scale)
{
	OLAVector dist(vec1.n_);
	OLALinearAlgebra::Subtract(vec1, vec2, dist);
	dist /= scale;

	return OLALinearAlgebra::Norm2(dist);
}

inline double OLAFunctions::MahalanobisDistance(OLAVector& vec1, OLAVector& vec2, OLAMatrix& covariance)
{
	return (double)sqrt(MahalanobisDistance2(vec1, vec2, covariance));
}

inline double OLAFunctions::MahalanobisDistance2(OLAVector& vec1, OLAVector& vec2, OLAMatrix& covariance)
{
	OLAMatrix icovariance(covariance.nRows_, covariance.nCols_);
	OLAVector tvec(vec1.n_), dist(vec1.n_);

	OLALinearAlgebra::Inverse(covariance, icovariance);
	OLALinearAlgebra::Subtract(vec1, vec2, dist);
	
	OLALinearAlgebra::Multiply(icovariance, dist, tvec);
	
	return OLALinearAlgebra::Dot(dist,tvec);
}


#endif