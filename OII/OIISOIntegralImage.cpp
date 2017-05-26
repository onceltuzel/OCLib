//
//  Created by Oncel Tuzel.
//  Copyright © 2006 Oncel Tuzel. All rights reserved.
//

#include "OIISOIntegralImage.h"
#include <highgui.h>

void OIISOIntegralImage::Resize(int width, int height, int dim)
{
	iimage_.Resize(width+1, height+1, dim*dim);
}

void OIISOIntegralImage::Construct(OCVImageND& image)
{
	int x, y, d1, d2;

	int width;
	int height;
	int dim;
	OCVImage* image1;
	OCVImage* image2;
	int d;
	double* data_0_0;
	double* data_1_0;
	double* data_0_1;
	double* data_1_1;

	width = image.GetWidth();
	height = image.GetHeight();
	dim = image.GetTime();
	
//	if (width!= iimage_.GetWidth() || height!= iimage_.GetHeight() || dim*dim != iimage_.GetDim())
//		iimage_.Resize(width, height, dim*dim);


	for (d1=0 ; d1<dim ; d1++)
	{
		for (d2=d1 ; d2<dim ; d2++)
		{

			for (x = 0 ; x <= width ; x++)
			{
				iimage_(x, 0, d1*dim+d2) = 0;
			}

			for (y = 0 ; y <= height ; y++)
			{
				iimage_(0, y, d1*dim+d2) = 0;
			}					
		}
	}

	for (y = 0 ; y < height ; y++)
	{
		for (x = 0 ; x < width ; x++)
		{
			for (d1=0 ; d1<dim ; d1++)
			{
				image1 = image(d1);
				data_0_0 = iimage_(x+1, y+1);
				data_1_0 = iimage_(x, y+1);
				data_0_1 = iimage_(x+1, y);
				data_1_1 = iimage_(x, y);

				for (d2=d1 ; d2<dim ; d2++)
				{
					image2 = image(d2);
					d = d1*dim+d2;
					data_0_0[d] = data_1_0[d] + data_0_1[d] - data_1_1[d] + (*image1).F(x, y) * (*image2).F(x, y);											   
				}
			}
		}
	} 

	for (y = 0 ; y <= height ; y++)
	{
		for (x = 0 ; x <= width ; x++)
		{
			data_0_0 = iimage_(x, y); 

			for (d1=0 ; d1<dim ; d1++)
			{
				for (d2=d1+1 ; d2<dim ; d2++)
				{
					data_0_0[d2*dim+d1] = data_0_0[d1*dim+d2];
				}
			}
		}
	}




/*
	for (d1=0 ; d1<dim ; d1++)
	{
		image1 = image(d1);

		for (d2=d1 ; d2<dim ; d2++)
		{
			image2 = image(d2);

			iimage_(0, 0, d1*dim+d2) = (*image1).F(0, 0) * (*image2).F(0, 0);

			for (x = 1 ; x < width ; x++)
			{
				iimage_(x, 0, d1*dim+d2) = (*image1).F(x, 0) * (*image2).F(x, 0) + iimage_(x-1, 0, d1*dim+d2);
			}

			for (y = 1 ; y < height ; y++)
			{
				iimage_(0, y, d1*dim+d2) = (*image1).F(0, y) * (*image2).F(0, y) + iimage_(0, y-1, d1*dim+d2);
			}					
		}
	}

	for (y = 1 ; y < height ; y++)
	{
		for (x = 1 ; x < width ; x++)
		{
			for (d1=0 ; d1<dim ; d1++)
			{
				image1 = image(d1);
				data_0_0 = iimage_(x, y);
				data_1_0 = iimage_(x-1, y);
				data_0_1 = iimage_(x, y-1);
				data_1_1 = iimage_(x-1, y-1);

				for (d2=d1 ; d2<dim ; d2++)
				{
					image2 = image(d2);
					d = d1*dim+d2;
					data_0_0[d] = data_1_0[d] + data_0_1[d] - data_1_1[d] + (*image1).F(x, y) * (*image2).F(x, y);											   
				}
			}
		}
	} 

	for (y = 0 ; y < height ; y++)
	{
		for (x = 0 ; x < width ; x++)
		{
			data_0_0 = iimage_(x, y); 

			for (d1=0 ; d1<dim ; d1++)
			{
				for (d2=d1+1 ; d2<dim ; d2++)
				{
					data_0_0[d2*dim+d1] = data_0_0[d1*dim+d2];
				}
			}
		}
	}
*/
	
/*
	OCVImage display;
	display.Resize(width, height);
	cvNamedWindow( "src", 1 );
	cvConvertScaleAbs(iimage_, display, 1.0/1000000.0);
	cvShowImage( "src", display ); 
	cvWaitKey();
*/
}

