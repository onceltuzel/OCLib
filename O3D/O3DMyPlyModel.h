//
//  Created by Oncel Tuzel.
//  Copyright © 2005 Oncel Tuzel. All rights reserved.
//



#ifndef _o3dmyplymodel_h
#define _o3dmyplymodel_h

#include "O3DModel.h"

class O3DMyPlyModel : public O3DModel{

public:
	O3DMyPlyModel();
	virtual ~O3DMyPlyModel();
	virtual void Read(char* fileName);

private:

};

#endif