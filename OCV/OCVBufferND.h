//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//


#ifndef _ocvbuffernd_h
#define _ocvbuffernd_h


class OCVBufferND{
public:
	OCVBufferND();
	OCVBufferND(int width, int height, int dim);
	OCVBufferND(const OCVBufferND& image);
	~OCVBufferND();

	void	Resize(int width, int height, int dim);

	inline double&	operator()(int x, int y, int d);
	inline double*	operator()(int x, int y);

	inline int GetWidth() const;
	inline int GetHeight() const;
	inline int GetDim() const;

	//Object Access
	inline operator	const double*() const;

	void	operator=(const OCVBufferND& image);

private:
	int width_;
	int height_;
	int dim_;
	double* buffer_;
	
	void	SafeRelease();
};

inline  OCVBufferND::operator const double*() const
{
	return buffer_;
}

inline int OCVBufferND::GetWidth() const
{
	return width_;
}

inline int OCVBufferND::GetHeight() const
{
	return height_;
}

inline int OCVBufferND::GetDim() const
{
	return dim_;
}

inline double*	OCVBufferND::operator()(int x, int y)
{
	return &(buffer_[(y*width_ + x)*dim_]);
}

inline double&	OCVBufferND::operator()(int x, int y, int d)
{
	return buffer_[(y*width_ + x)*dim_ + d];
}

/*
inline double*	OCVBufferND::operator()(int x, int y)
{
	return buffer_[(y*width_ + x)];
}

inline double&	OCVBufferND::operator()(int x, int y, int d)
{
	return buffer_[(y*width_ + x)][d];
}
*/

#endif