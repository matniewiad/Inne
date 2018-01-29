#include "StdAfx.h"
#include "Punkt_3D.h"


Punkt_3D::Punkt_3D(void)
{
	z = (rand()%2001-1000)/100.00;
    cout << "pracuje konstruktor 3D" << endl;
}


Punkt_3D::~Punkt_3D(void)
{
	cout << "pracuje destruktor 3D" << endl;
}
