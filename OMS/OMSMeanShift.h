//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//


#ifndef _OMSMeanShift_h
#define _OMSMeanShift_h
#include <stdio.h>

#define COMSEpanechnikovKernel
#undef  COMSGaussianKernel

#define COMSIterateEpsilon 0.000001
#define COMSMaxIteration 200


class OMSMeanShift{
public:
	OMSMeanShift();
	virtual ~OMSMeanShift();

	enum EKernelType {
		EEpanechnikovKernel = 0,
		EGaussianKernel
	};

	virtual void Read(char* filename);
	virtual void SetPoints(int n, double** points, double** bandwidths = NULL);

	virtual void Run();
	virtual void PruneModes(double *h, int minSize);
	virtual void Set(int d, double *h, int jump=1, EKernelType kernel = EEpanechnikovKernel);
	virtual void SaveLocalModes(char* filename);
	virtual void SavePrunedModes(char* filename);

	virtual void Sort();
public:

	virtual void Initialize();
	virtual void Iterate(double* point, double* modifiedPoint);
	virtual void RunSinglePoint(double* point);
	
	virtual inline double Probability(double* point, int d, double* h);
	virtual inline double KernelDiff(double* point1, double* point2, int d, double* h);
	virtual inline double Kernel(double* point1, double* point2, int d, double* h);
	virtual inline double DistanceSqr(double* point1, double* point2, int d, double* h);

	
	void Sort(double* ra, int nVec, int* ira);
	void Sort(double* points, double* probs, int n, int d);

	int d_;
	int n_;
	int nxd_;

	//Bandwidth
	double* h_;
	//Data reduction
	int jump_;


	//Input Points
	double* points_;
	double* bandwidths_;

	//Local Modes
	int	  nLocalModes_;
	double* localModes_;
	double* localModeProbs_;
	int* basinOfAttraction_;

	//Modes
	int	  nPrunedModes_;
	double* prunedModes_;
	double* prunedModeProbs_;

	EKernelType kernel_;

	int iterationCount_;
};

#endif