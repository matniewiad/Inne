#pragma once
#include "Punkt.h"
class CPorownajPunkt
{
public:
	CPorownajPunkt();
	~CPorownajPunkt();

	bool operator()(Punkt const & p1, Punkt const & p2);
};

