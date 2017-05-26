//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//



#ifndef _o3dplymodel_h
#define _o3dplymodel_h

#include "O3DModel.h"

class O3DPlyModel : public O3DModel{

public:
	O3DPlyModel();
	virtual ~O3DPlyModel();
	virtual void Read(char* fileName);

private:

};

#endif