#include "Punkt2D.h"



Punkt2D::Punkt2D()
{
	x_pub = 11;
	y_pub = 21;
}

Punkt2D::Punkt2D(int b)
{
	//x_pub = 44;
	y_pub = b;
}


Punkt2D::Punkt2D(int a, int b):y_pub(b),Punkt1D(a)
{
	//x_pub = a;
	//y_pub = b;
}


Punkt2D::~Punkt2D()
{
}
