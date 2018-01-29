#include "punkt_1d.h"
#include <stdlib.h>

Punkt_1D::Punkt_1D(void)
{
  	x = (rand()%2001-1000)/100.00;
}

Punkt_1D::~Punkt_1D(void)
{
}

Punkt_1D::Punkt_1D(double a)
{
    x = a;
}
