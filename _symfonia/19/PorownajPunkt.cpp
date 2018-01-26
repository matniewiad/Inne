#include "PorownajPunkt.h"



CPorownajPunkt::CPorownajPunkt()
{
}


CPorownajPunkt::~CPorownajPunkt()
{
}

bool CPorownajPunkt::operator()(Punkt const & p1, Punkt const & p2)
{
	return p1.x < p2.x;
}
