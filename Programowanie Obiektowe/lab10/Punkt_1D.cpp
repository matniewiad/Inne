#include "StdAfx.h"
#include "Punkt_1D.h"


Punkt_1D::Punkt_1D(void)
{
	x = (rand()%2001-1000)/100.00;
    cout << "pracuje konstruktor 1D" << endl;
}


Punkt_1D::~Punkt_1D(void)
{
	cout << "pracuje destruktor 1D" << endl;
}
