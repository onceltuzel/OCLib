// Created by: Oncel Tuzel 
// Date: 01/12/2005

#ifndef _omllsvmlassifier_h
#define _omllsvmlassifier_h

#include "OML/OMLLinearClassifier.h"

class OMLLSVMClassifier : public OMLLinearClassifier{
public:
	virtual void	Train(OLAVector* data, double* weights, int pn, int nn, char* parameters = NULL);

};


//General options:
//-?          - this help
//-v [0..3]   - verbosity level (default 1)
//Learning options:
//-z {c,r,p}  - select between classification (c), regression (r), and 
//preference ranking (p) (see [Joachims, 2002c])
//(default classification)          
//-c float    - C: trade-off between training error
//and margin (default [avg. x*x]^-1)
//-w [0..]    - epsilon width of tube for regression
//(default 0.1)
//-j float    - Cost: cost-factor, by which training errors on
//positive examples outweight errors on negative
//examples (default 1) (see [Morik et al., 1999])
//-b [0,1]    - use biased hyperplane (i.e. x*w+b0) instead
//of unbiased hyperplane (i.e. x*w0) (default 1)
//-i [0,1]    - remove inconsistent training examples
//and retrain (default 0)
//Performance estimation options:
//-x [0,1]    - compute leave-one-out estimates (default 0)
//(see [5])
//-o ]0..2]   - value of rho for XiAlpha-estimator and for pruning
//leave-one-out computation (default 1.0) 
//(see [Joachims, 2002a])
//-k [0..100] - search depth for extended XiAlpha-estimator
//(default 0)
//Transduction options (see [Joachims, 1999c], [Joachims, 2002a]):
//-p [0..1]   - fraction of unlabeled examples to be classified
//into the positive class (default is the ratio of
//						 positive and negative examples in the training data)
//						 Kernel options:
//-t int      - type of kernel function:
//0: linear (default)
//1: polynomial (s a*b+c)^d
//2: radial basis function exp(-gamma ||a-b||^2)
//3: sigmoid tanh(s a*b + c)
//4: user defined kernel from kernel.h
//-d int      - parameter d in polynomial kernel
//-g float    - parameter gamma in rbf kernel
//-s float    - parameter s in sigmoid/poly kernel
//-r float    - parameter c in sigmoid/poly kernel
//-u string   - parameter of user defined kernel
//Optimization options (see [Joachims, 1999a], [Joachims, 2002a]):
//-q [2..]    - maximum size of QP-subproblems (default 10)
//-n [2..q]   - number of new variables entering the working set
//in each iteration (default n = q). Set n<q to prevent
//zig-zagging.
//-m [5..]    - size of cache for kernel evaluations in MB (default 40)
//The larger the faster...
//-e float    - eps: Allow that error for termination criterion
//[y [w*x+b] - 1] = eps (default 0.001) 
//-h [5..]    - number of iterations a variable needs to be
//optimal before considered for shrinking (default 100) 
//-f [0,1]    - do final optimality check for variables removed by
//shrinking. Although this test is usually positive, there
//is no guarantee that the optimum was found if the test is
//omitted. (default 1) 
//-y string   -> if option is given, reads alphas from file with given
//and uses them as starting point. (default 'disabled')
//-# int      -> terminate optimization, if no progress after this
//number of iterations. (default 100000)
//Output options: 
//-l char     - file to write predicted labels of unlabeled examples 
//into after transductive learning 
//-a char     - write all alphas to this file after learning (in the 
//															same order as in the training set)


#endif
