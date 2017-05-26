//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//


#ifndef _o3dfunctions_h
#define _o3dfunctions_h

#include "O3DModel.h"

class O3DFunctions {
public:

	static void RecomputeTriangularMesh(O3DModel& model);
	static void SmoothNormals(O3DModel& model);
	static void ReadPlyModel(const char* fileName, O3DModel& model);

	static void Center(O3DModel& model);
	static void Scale(O3DModel& model, double scaleX, double scaleY, double scaleZ);
	static void SetXYZOrder(O3DModel& model, const char* xyzOrder);

	static double GetRadius(O3DModel& model);
private:
	static void	GetCoordinateSwitch(const char* xyzOrder, double& sign, int& index);

};

#endif