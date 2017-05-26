//
//  Created by Oncel Tuzel.
//  Copyright © 2006 Oncel Tuzel. All rights reserved.
//


#include "OFIImageFilter.h"
#include <highgui.h>

void OFIImageFilter::ColorGradientsXY(OCVImage& image, OCVImageND& featureImage)
{
	CvMat kernel;
	OCVImage gImage;	
	int featureCount;

	OCVImage ogImage;	
	featureCount = 9;

	float kf1[] = { -1, 0, 1};
	float kf2[] = { -1, 2, -1};


	gImage.Resize(image.GetWidth(), image.GetHeight(), 1, IPL_DEPTH_8U);
	ogImage.Resize(image.GetWidth(), image.GetHeight(), 1, IPL_DEPTH_32F);
	featureImage.Resize(featureCount, image.GetWidth(), image.GetHeight(), 1, IPL_DEPTH_32F);


	// Color
	cvSetImageCOI(image, 1);
	cvCopy(image, gImage);
	cvConvertScale(gImage, *featureImage(0));
	cvSetImageCOI(image, 2);
	cvCopy(image, gImage);
	cvConvertScale(gImage, *featureImage(1));
	cvSetImageCOI(image, 3);
	cvCopy(image, gImage);
	cvConvertScale(gImage, *featureImage(2));
	cvSetImageCOI(image, 0);

	cvCvtColor(image, gImage, CV_RGB2GRAY);
	cvConvertScale(gImage, ogImage);

	// X Gradient
	cvInitMatHeader( &kernel, 1, 3, CV_32FC1, kf1 );
	cvFilter2D(ogImage, *featureImage(3), &kernel);
	//cvAbs(*featureImage(3), *featureImage(3));

	// Y Gradient
	cvInitMatHeader( &kernel, 3, 1, CV_32FC1, kf1 ); 
	cvFilter2D(ogImage, *featureImage(4), &kernel);
	//cvAbs(*featureImage(4), *featureImage(4)); 

	// XX Gradient
	cvInitMatHeader( &kernel, 1, 3, CV_32FC1, kf2 );
	cvFilter2D(ogImage, *featureImage(5), &kernel);
	//cvAbs(*featureImage(5), *featureImage(5));

	// YY Gradient
	cvInitMatHeader( &kernel, 3, 1, CV_32FC1, kf2 );
	cvFilter2D(ogImage, *featureImage(6), &kernel);
	//cvAbs(*featureImage(6), *featureImage(6));	

	for (int x = 0 ; x<image.GetWidth(); x++)
	{
		for (int y = 0 ; y<image.GetHeight(); y++)
		{
			featureImage.F(7,x,y) = x;
			featureImage.F(8,x,y) = y;
		}
	}



	OCVImage display;
	display.Resize(image.GetWidth(), image.GetHeight());
	cvNamedWindow( "Features", 1 );

	for (int k=0; k<featureCount ; k++)
	{
		cvConvertScaleAbs(*featureImage(k), display, 1);
		cvShowImage( "Features", display );
		cvWaitKey();
	}

}



void OFIImageFilter::ColorGradients(OCVImage& image, OCVImageND& featureImage)
{
	CvMat kernel;
	OCVImage gImage;	
	int featureCount;

	OCVImage ogImage;	
	featureCount = 7;

	float kf1[] = { -1, 0, 1};
	float kf2[] = { -1, 2, -1};

	
	gImage.Resize(image.GetWidth(), image.GetHeight(), 1, IPL_DEPTH_8U);
	ogImage.Resize(image.GetWidth(), image.GetHeight(), 1, IPL_DEPTH_32F);
	featureImage.Resize(featureCount, image.GetWidth(), image.GetHeight(), 1, IPL_DEPTH_32F);


	// Color
	cvSetImageCOI(image, 1);
	cvCopy(image, gImage);
	cvConvertScale(gImage, *featureImage(0));
	cvSetImageCOI(image, 2);
	cvCopy(image, gImage);
	cvConvertScale(gImage, *featureImage(1));
	cvSetImageCOI(image, 3);
	cvCopy(image, gImage);
	cvConvertScale(gImage, *featureImage(2));
	cvSetImageCOI(image, 0);

	cvCvtColor(image, gImage, CV_RGB2GRAY);
	cvConvertScale(gImage, ogImage);

	// X Gradient
	cvInitMatHeader( &kernel, 1, 3, CV_32FC1, kf1 );
	cvFilter2D(ogImage, *featureImage(3), &kernel);
	//cvAbs(*featureImage(3), *featureImage(3));

	// Y Gradient
	cvInitMatHeader( &kernel, 3, 1, CV_32FC1, kf1 ); 
	cvFilter2D(ogImage, *featureImage(4), &kernel);
	//cvAbs(*featureImage(4), *featureImage(4)); 

	// XX Gradient
	cvInitMatHeader( &kernel, 1, 3, CV_32FC1, kf2 );
	cvFilter2D(ogImage, *featureImage(5), &kernel);
	//cvAbs(*featureImage(5), *featureImage(5));

	// YY Gradient
	cvInitMatHeader( &kernel, 3, 1, CV_32FC1, kf2 );
	cvFilter2D(ogImage, *featureImage(6), &kernel);
	//cvAbs(*featureImage(6), *featureImage(6));	

	
	OCVImage display;
	display.Resize(image.GetWidth(), image.GetHeight());
	cvNamedWindow( "Features", 1 );

	for (int k=0; k<featureCount ; k++)
	{
		cvConvertScaleAbs(*featureImage(k), display, 1);
		cvShowImage( "Features", display );
		cvWaitKey();
	}
	
}


void OFIImageFilter::Gradients(OCVImage& image, OCVImageND& featureImage)
{
	CvMat kernel;
	OCVImage gImage;	
	int featureCount;

	OCVImage ogImage;	
	featureCount = 5;

	float kf1[] = { -1, 0, 1};
	float kf2[] = { -1, 2, -1};

//	image = cvLoadImage(imageName, 1);
	gImage.Resize(image.GetWidth(), image.GetHeight(), 1, IPL_DEPTH_8U);
	ogImage.Resize(image.GetWidth(), image.GetHeight(), 1, IPL_DEPTH_32F);

//	NormalizeImage(image, oImage);

	cvCvtColor(image, gImage, CV_RGB2GRAY);
	cvConvertScale(gImage, ogImage);
	
	featureImage.Resize(featureCount, image.GetWidth(), image.GetHeight(), 1, IPL_DEPTH_32F);

	// Color
	cvCopy(ogImage, *featureImage(0));

	// X Gradient
	cvInitMatHeader( &kernel, 1, 3, CV_32FC1, kf1 );
	cvFilter2D(ogImage, *featureImage(1), &kernel);
	cvAbs(*featureImage(1), *featureImage(1));

	// Y Gradient
	cvInitMatHeader( &kernel, 3, 1, CV_32FC1, kf1 ); 
	cvFilter2D(ogImage, *featureImage(2), &kernel);
	cvAbs(*featureImage(2), *featureImage(2)); 

	// XX Gradient
	cvInitMatHeader( &kernel, 1, 3, CV_32FC1, kf2 );
	cvFilter2D(ogImage, *featureImage(3), &kernel);
	cvAbs(*featureImage(3), *featureImage(3));

	// YY Gradient
	cvInitMatHeader( &kernel, 3, 1, CV_32FC1, kf2 );
	cvFilter2D(ogImage, *featureImage(4), &kernel);
	cvAbs(*featureImage(4), *featureImage(4));	

	/*
	OCVImage display;
	display.Resize(image.GetWidth(), image.GetHeight());
	cvNamedWindow( "src", 1 );

	for (int k=0; k<featureCount ; k++)
	{
		cvConvertScaleAbs(*featureImage(k), display, 1);
		cvShowImage( "src", display );
		cvWaitKey();
	}
	*/
}


void OFIImageFilter::GradientsWThresholds(OCVImage& image, OCVImageND& featureImage)
{
	int x;
	CvMat kernel;
	OCVImage gImage;	

	OCVImage ogImage;	
	OCVImage oImage;

	int featureCount = 4;

	float kf1[] = { -4, 0, 4};
	float kf2[] = { -1, 2, -1};

//	image = cvLoadImage(imageName, 1);

	gImage.Resize(image.GetWidth(), image.GetHeight(), 1, IPL_DEPTH_8U);
	ogImage.Resize(image.GetWidth(), image.GetHeight(), 1, IPL_DEPTH_32F);
	oImage.Resize(image.GetWidth(), image.GetHeight(), 3, IPL_DEPTH_32F);

	cvCvtColor(image, gImage, CV_RGB2GRAY);

	featureImage.Resize(featureCount, image.GetWidth(), image.GetHeight(), 1, IPL_DEPTH_32F);

	for (int x = 0 ; x<gImage.GetWidth(); x++)
	{
		for (int y = 0 ; y<gImage.GetHeight(); y++)
		{
			
			if (gImage(x,y)<180)
			{
				gImage(x,y) = 180;
			}
			else if (gImage(x,y) > 230)
			{
				gImage(x,y) = 230;
			}
			
			//featureImage_(0)->F(x,y) = x;
			//featureImage_(1)->F(x,y) = y;
		}
	}

	cvConvertScale(gImage, ogImage);	
	cvConvertScale(image, oImage);	

	// Color
	cvCopy(ogImage, *featureImage(0));

	// X Gradient
	cvInitMatHeader( &kernel, 1, 3, CV_32FC1, kf1 );
	cvFilter2D(ogImage, *featureImage(1), &kernel);
	cvAbs(*featureImage(1), *featureImage(1));

	// Y Gradient
	cvInitMatHeader( &kernel, 3, 1, CV_32FC1, kf1 ); 
	cvFilter2D(ogImage, *featureImage(2), &kernel);
	cvAbs(*featureImage(2), *featureImage(2));

	for (x = 0 ; x<gImage.GetWidth(); x++)
	{
		for (int y = 0 ; y<gImage.GetHeight(); y++)
		{
			featureImage(3)->F(x,y) = (float) sqrt(featureImage(1)->F(x,y)*featureImage(1)->F(x,y) +
													  featureImage(2)->F(x,y)*featureImage(2)->F(x,y));
		}
	}

	OCVImage display;
	display.Resize(image.GetWidth(), image.GetHeight());
	cvNamedWindow( "src", 1 );
	for (int k=0; k<featureCount ; k++)
	{
		cvConvertScaleAbs(*featureImage(k), display, 1);
		cvShowImage( "src", display );
		cvWaitKey();
	}
}


void OFIImageFilter::Schmidt(OCVImage& image, OCVImageND& featureImage)
{
	int f, w, h, i, j;
	char dummy[256];
	FILE* ffilter;
	int width, height;
	OCVImage oImage;

	int featureCount = 13;

//	image = cvLoadImage(imageName, 0);
	width = image.GetWidth();
	height = image.GetHeight();


	for (int x = 0 ; x<image.GetWidth(); x++)
	{
		for (int y = 0 ; y<image.GetHeight(); y++)
		{
			
			if (image(x,y)<180)
			{
				image(x,y) = 180;
			}
			else if (image(x,y) > 230)
			{
				image(x,y) = 230;
			}			
		}
	}


	oImage.Resize(image.GetWidth(), image.GetHeight(), 1, IPL_DEPTH_32F);
	NormalizeImage(image, oImage);



	featureImage.Resize(featureCount, width, height, 1, IPL_DEPTH_32F);

	ffilter = fopen("filters/S_filt.dat", "r");
	for (f=0 ; f< featureCount ; f++)
	{
		printf("Filter %d\n", f);

		CvMat* kernel;
		float value;

		fscanf(ffilter, "%s", dummy);
		fscanf(ffilter, "%d %d", &w, &h);
		fscanf(ffilter, "%s", dummy);

		kernel = cvCreateMat( w, h, CV_32FC1);

		for (i=0 ; i<w ; i++)
		{
			for (j=0 ; j<h ; j++)
			{
				fscanf(ffilter, "%f", &value);
				cvSetReal2D(kernel, i, j, value);
			}
		}

		cvFilter2D(oImage, *featureImage(f), kernel);		
		cvReleaseMat(&kernel);
	}
	fclose(ffilter);

	OCVImage display;
	display.Resize(image.GetWidth(), image.GetHeight());
	cvNamedWindow( "src", 1 );
	for (int k=0; k<featureCount ; k++)
	{
		cvConvertScaleAbs(*featureImage(k), display, 1000);
		cvShowImage( "src", display );
		cvWaitKey(); 
	}
	
}


void OFIImageFilter::M8(OCVImage& image, OCVImageND& featureImage)
{
	int f, w, h, i, j;
	char dummy[256];
	FILE* ffilter;

	int width, height;
	OCVImage oImage;

	int tFeatureCount;
	OCVImageND tFeatureImage;

	int featureCount = 8;

	tFeatureCount = 38;

//	image = cvLoadImage(imageName, 0);
/*

	for (int x = 0 ; x<image.GetWidth(); x++)
	{
		for (int y = 0 ; y<image.GetHeight(); y++)
		{
			
			if (image(x,y)<180)
			{
				image(x,y) = 180;
			}
			else if (image(x,y) > 230)
			{
				image(x,y) = 230;
			}
			
		}
	}

	cvNamedWindow( "src", 1 );
	cvShowImage( "src", image );
	cvWaitKey();
*/

	width = image.GetWidth();
	height = image.GetHeight();

	oImage.Resize(image.GetWidth(), image.GetHeight(), 1, IPL_DEPTH_32F);
	NormalizeImage(image, oImage);

	featureImage.Resize(featureCount, width, height, 1, IPL_DEPTH_32F);
	tFeatureImage.Resize(tFeatureCount, width, height, 1, IPL_DEPTH_32F);


	ffilter = fopen("filters/M8_filt.dat", "r");
	for (f=0 ; f< tFeatureCount ; f++)
	{
		printf("Filter %d\n", f);
		
		CvMat* kernel;
		float value;

		fscanf(ffilter, "%s", dummy);
		fscanf(ffilter, "%d %d", &w, &h);
		fscanf(ffilter, "%s", dummy);

		kernel = cvCreateMat( w, h, CV_32FC1);

		for (i=0 ; i<w ; i++)
		{
			for (j=0 ; j<h ; j++)
			{
				fscanf(ffilter, "%f", &value);
				cvSetReal2D(kernel, i, j, value);
			}
		}

		cvFilter2D(oImage, *tFeatureImage(f), kernel);		
		cvReleaseMat(&kernel);
	}
	fclose(ffilter);

	//First two unchanged
	cvCopy(*tFeatureImage(0), *featureImage(0));
	cvCopy(*tFeatureImage(1), *featureImage(1));

	int jump;
	float max1, max2;
	float v1, v2;

	for (f=0 ; f<3 ; f++)
	{
		for (i=0 ; i<width ; i++)
		{
			for (j=0 ; j<height ; j++)
			{
				max1 = (float) fabs(tFeatureImage.F(2 + f*12, i, j));
				max2 = (float) fabs(tFeatureImage.F(2 + f*12 + 1, i, j));

				for (jump=1 ; jump<6 ; jump++)
				{
					v1 = (float) fabs(tFeatureImage.F(2 + f*12 + jump*2, i, j));
					v2 = (float) fabs(tFeatureImage.F(2 + f*12 + jump*2 + 1, i, j));

					if (max1 < v1)
						max1 = v1;

					if (max2 < v2)
						max2 = v2;					
				}

				featureImage.F(2 + f*2, i, j) = max1;
				featureImage.F(2 + f*2 + 1, i, j) = max2;

			}
		}
	}
	
	/*
	OCVImage display;
	display.Resize(image.GetWidth(), image.GetHeight());
	cvNamedWindow( "src", 1 );
	for (int k=0; k<featureCount ; k++)
	{
		cvConvertScaleAbs(*featureImage(k), display, 100);
		cvShowImage( "src", display );
		cvWaitKey();
	}
	*/
	
}



void OFIImageFilter::NormalizeImage(OCVImage& image, OCVImage& oImage)
{
	int i, j;
	double mean = 0;
	double var = 0;

	for (i=0 ; i<image.GetWidth() ; i++)
	{
		for (j=0 ; j<image.GetHeight() ; j++)
		{
			mean += image(i, j);
		}
	}
	mean /= image.GetWidth()*image.GetHeight();

	for (i=0 ; i<image.GetWidth() ; i++)
	{
		for (j=0 ; j<image.GetHeight() ; j++)
		{
			var += (image(i, j)-mean)*(image(i, j)-mean);
		}
	}
	var /= image.GetWidth()*image.GetHeight();
	cvConvertScale(image, oImage, 1, -mean);
	cvConvertScale(oImage, oImage, 1/sqrt(var), 0);
}