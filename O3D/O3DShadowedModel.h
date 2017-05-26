//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//

#ifndef _o3dshadowedmodel_h
#define _o3dshadowedmodel_h


#include "O3DModel.h"

class O3DShadowedModel : public O3DModel
{
public:
	O3DShadowedModel();
	virtual ~O3DShadowedModel();
	virtual void SafeRelease();

	//virtual void Read(const char* fileName);

	virtual void CastShadow(double *lp);
	virtual void ComputePlaneEquations();
	virtual void SetConnectivity();
	virtual void Center();

private:

	unsigned int nPlanes_;
	double *planeEqn_;
	unsigned int *visible_;
	unsigned int *neigh_;
};

#endif