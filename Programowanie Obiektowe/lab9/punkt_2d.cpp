#include "punkt_2d.h"
#include <stdlib.h>

Punkt_2D::Punkt_2D(void)
{
    y = (rand()%2001-1000)/100.00;
}

Punkt_2D::Punkt_2D(double a, double b)
{
}

Punkt_2D::~Punkt_2D(void)
{
}
