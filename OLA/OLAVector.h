//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//


#ifndef _olavector_h
#define _olavector_h

#include <stdlib.h>
#include <string.h>
#include <math.h>

class OLAVector {
public:
	OLAVector();
	OLAVector(int n);
	OLAVector(const OLAVector& vec);
	~OLAVector();

	void SafeRelease();
	void Resize(int n);
	
	inline void SetZero();

	inline void operator=(double val);
	inline void operator=(const OLAVector& vec);
	inline void operator=(const double* data);

	//One Element operations
	inline void operator-=(double val);
	inline void operator-=(OLAVector& vec);

	inline void operator+=(double val);
	inline void operator+=(OLAVector& vec);

	inline void operator*=(double val);
	inline void operator*=(OLAVector& vec);

	inline void operator/=(double val);
	inline void operator/=(OLAVector& vec);
/*
	//Two element operations
	inline void Subtract(OLAVector& vec1, OLAVector& vec2);
	inline void Add(OLAVector& vec1, OLAVector& vec2);
	inline void Multiply(OLAVector& vec1, OLAVector& vec2);
	inline void Divide(OLAVector& vec1, OLAVector& vec2);

	//Norms
	inline double Norm();  //L2 norm
	inline double Norm1(); //L1 norm
	inline double Norm2(); //Squared L2 norm

	inline double Dot(OLAVector& vec); //Dot product
*/
	inline int Size(); //Size

	inline void normalize();
	//
	// Element access
	//
	inline double operator()(int i = 0) const;
	inline double& operator()(int i = 0);

    // vector data
    double* data_;
    // size
    int n_;
};


inline int OLAVector::Size() 
{
   return n_;
}

inline void OLAVector::normalize()
{
	double sum = 0;
	for (int i=0; i<n_; ++i)
		sum += data_[i]*data_[i];

	const double norm = sqrt(sum);
	for (int i=0; i<n_; ++i)
		data_[i] /= norm;
}

inline double OLAVector::operator()(int i) const
{
   return data_[i];
}

inline double& OLAVector::operator()(int i)
{
   return data_[i];
}

inline void OLAVector::SetZero()
{
	memset(data_, 0, n_*sizeof(double));
}

inline void OLAVector::operator=(double val)
{
	int i;
	for (i=0 ; i<n_ ; i++)
		data_[i] = val;
}

inline void OLAVector::operator=(const double* data)
{
	memcpy(data_, data, n_*sizeof(double));
}

inline void OLAVector::operator=(const OLAVector& vec)
{
	if (n_ != vec.n_)
	{
		Resize(vec.n_);
	}
	
	memcpy(data_, vec.data_, n_*sizeof(double));
}

//One Element operations
inline void OLAVector::operator-=(double val)
{
	int i;
	for (i=0 ; i<n_ ; i++)
		data_[i] -= val;
}
inline void OLAVector::operator-=(OLAVector& vec)
{
	int i;
	double* data = vec.data_;
	for (i=0 ; i<n_ ; i++)
		data_[i] -= data[i];	
}

inline void OLAVector::operator+=(double val)
{
	int i;
	for (i=0 ; i<n_ ; i++)
		data_[i] += val;
}
inline void OLAVector::operator+=(OLAVector& vec)
{
	int i;
	double* data = vec.data_;
	for (i=0 ; i<n_ ; i++)
		data_[i] += data[i];	
}

inline void OLAVector::operator*=(double val)
{
	int i;
	for (i=0 ; i<n_ ; i++)
		data_[i] *= val;
}
inline void OLAVector::operator*=(OLAVector& vec)
{
	int i;
	double* data = vec.data_;
	for (i=0 ; i<n_ ; i++)
		data_[i] *= data[i];	
}

inline void OLAVector::operator/=(double val)
{
	int i;
	for (i=0 ; i<n_ ; i++)
		data_[i] /= val;
}
inline void OLAVector::operator/=(OLAVector& vec)
{
	int i;
	double* data = vec.data_;
	for (i=0 ; i<n_ ; i++)
		data_[i] /= data[i];	
}
/*
//Two element operations
inline void OLAVector::Subtract(OLAVector& vec1, OLAVector& vec2)
{
	int i;

	double* data1 = vec1.data_;
	double* data2 = vec2.data_;

	for (i=0 ; i<n_ ; i++)
		data_[i] = data1[i] - data2[i];	
}

inline void OLAVector::Add(OLAVector& vec1, OLAVector& vec2)
{
	int i;

	double* data1 = vec1.data_;
	double* data2 = vec2.data_;

	for (i=0 ; i<n_ ; i++)
		data_[i] = data1[i] + data2[i];	
}

inline void OLAVector::Multiply(OLAVector& vec1, OLAVector& vec2)
{
	int i;

	double* data1 = vec1.data_;
	double* data2 = vec2.data_;

	for (i=0 ; i<n_ ; i++)
		data_[i] = data1[i] * data2[i];	
}

inline void OLAVector::Divide(OLAVector& vec1, OLAVector& vec2)
{
	int i;

	double* data1 = vec1.data_;
	double* data2 = vec2.data_;

	for (i=0 ; i<n_ ; i++)
		data_[i] = data1[i] / data2[i];	
}

inline double OLAVector::Norm()
{
	return (double) sqrt(Norm2());
}

inline double OLAVector::Norm1()
{
	int i;
	double val = 0;
	for (i=0 ; i<n_ ; i++)
		val += (double)fabs(data_[i]);

	return val;
}

inline double OLAVector::Norm2()
{
	int i;
	double val = 0;
	for (i=0 ; i<n_ ; i++)
		val += data_[i]*data_[i];

	return val;
}


inline double OLAVector::Dot(OLAVector& vec)
{
	int i;
	double val = 0;
	double* data = vec.data_;
	for (i=0 ; i<n_ ; i++)
		val += data_[i]*data[i];	

	return val;
}
*/
#endif