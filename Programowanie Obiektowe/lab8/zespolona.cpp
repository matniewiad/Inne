#include "zespolona.h"
#include <stdlib.h>


Zespolona::Zespolona(void)
{
    r = rand()%21-10;
    i = rand()%21-10;
}


Zespolona::~Zespolona(void)
{
}

Zespolona Zespolona :: operator+(Zespolona ob1)  //uzycie wskaznika this
{
    Zespolona suma;
    suma.r = this->r+ob1.r;
    suma.i = this->i+ob1.i;
    return suma;
}

Zespolona Zespolona :: operator*(Zespolona ob1)
{
    Zespolona iloczyn;
    iloczyn.r = r*ob1.r - i*ob1.i;
    iloczyn.i = r*ob1.i + i*ob1.r;
    return iloczyn;
}

void Zespolona :: operator+=(Zespolona ob1)
{
	r=r+ob1.r;
	i=i+ob1.i;
}

void Zespolona :: operator*=(Zespolona ob1)
{
	r=r*ob1.r - i*ob1.i;
	i=r*ob1.i + i*ob1.r;
}

bool Zespolona :: operator<(Zespolona ob1)
{
	if(modul() < ob1.modul())
	return true;
	else
	return false;
}

bool Zespolona :: operator>(Zespolona ob1)
{
	if(modul() > ob1.modul())
	return true;
	else
	return false;
}

bool Zespolona :: operator==(Zespolona ob1)
{
	if(modul() == ob1.modul())
	return true;
	else
	return false;	
}

