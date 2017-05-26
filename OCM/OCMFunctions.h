//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//

#ifndef _ocmfunctions_h
#define _ocmfunctions_h
#include <math.h>

class OCMFunctions {
public:
	//Round
	static inline int Round(float val); 
	static inline int Round(double val); 

	//Min & Max
	static inline int Min(int val1, int val2); 
	static inline int Max(int val1, int val2); 
	static inline float Min(float val1, float val2); 
	static inline float Max(float val1, float val2); 
	static inline double Min(double val1, double val2); 
	static inline double Max(double val1, double val2); 

	static inline double Max(double* list, int size); 
	static inline int MaxIndex(double* list, int size); 
	static inline int MinIndex(double* list, int size); 
	static inline int Max(int* list, int size); 
	static inline int MaxIndex(int* list, int size); 

	//Sorting
	static void Sort(double* ra, int nVec);
	static void ISort(double* ra, int nVec, int* ira);
	static void Sort(float* ra, int nVec);
	static void ISort(float* ra, int nVec, int* ira);
};


inline double OCMFunctions::Max(double* list, int size)
{
	int i;

	double maximum = list[0];

	for (i=1 ; i<size ; i++)
	{
		if (list[i] > maximum)
		{
			maximum = list[i];
		}
	}

	return maximum;
}

inline int OCMFunctions::MinIndex(double* list, int size)
{
	int i;

	int index = 0;
	double minimum = list[0];

	for (i=1 ; i<size ; i++)
	{
		if (list[i] < minimum)
		{
			minimum = list[i];
			index = i;
		}
	}

	return index;
}


inline int OCMFunctions::MaxIndex(double* list, int size)
{
	int i;

	int index = 0;
	double maximum = list[0];

	for (i=1 ; i<size ; i++)
	{
		if (list[i] > maximum)
		{
			maximum = list[i];
			index = i;
		}
	}

	return index;
}

inline int OCMFunctions::Max(int* list, int size)
{
	int i;

	int maximum = list[0];

	for (i=1 ; i<size ; i++)
	{
		if (list[i] > maximum)
		{
			maximum = list[i];
		}
	}

	return maximum;
}

inline int OCMFunctions::MaxIndex(int* list, int size)
{
	int i;

	int index = 0;
	int maximum = list[0];

	for (i=1 ; i<size ; i++)
	{
		if (list[i] > maximum)
		{
			maximum = list[i];
			index = i;
		}
	}

	return index;
}

inline int OCMFunctions::Min(int val1, int val2)
{
	return (val1 < val2) ? val1 : val2;
}

inline int OCMFunctions::Max(int val1, int val2)
{
	return (val1 > val2) ? val1 : val2;
}



inline float OCMFunctions::Min(float val1, float val2)
{
	return (val1 < val2) ? val1 : val2;
}

inline float OCMFunctions::Max(float val1, float val2)
{
	return (val1 > val2) ? val1 : val2;
}

inline double OCMFunctions::Min(double val1, double val2)
{
	return (val1 < val2) ? val1 : val2;
}

inline double OCMFunctions::Max(double val1, double val2)
{
	return (val1 > val2) ? val1 : val2;
}

inline int OCMFunctions::Round(float val)
{
	return (int) floor(val + 0.5f);
}

inline int OCMFunctions::Round(double val)
{
	return (int) floor(val + 0.5);
}


#endif