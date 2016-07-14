#pragma once
#include "stdafx.h"

// abstract class
class Exercise
{
public:
	// virtual destructor, so overridden destructors are called correctly
	virtual ~Exercise() {};
	virtual void mySolution() = 0;
};
