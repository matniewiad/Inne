#include "StdAfx.h"
#include "Punkt_2D.h"


Punkt_2D::Punkt_2D(void)
{
	y = (rand()%2001-1000)/100.00;
    cout << "pracuje konstruktor 2D" << endl;
}


Punkt_2D::~Punkt_2D(void)
{
	cout << "pracuje destruktor 2D" << endl;
}
