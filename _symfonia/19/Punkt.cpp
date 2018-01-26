#include "Punkt.h"



void Punkt::wczytaj()
{
	cout << "podaj nazwe i wspolrzedne: " << endl;
	cin >> nazwa >> x >> y;
}

void Punkt::wyswietl()
{
	cout << "nazwa: " << nazwa << "	x: " << x << "	y: " << y << endl;
}

float Punkt::get_x()
{
	return x;
}

float Punkt::get_y()
{
	return y;
}

Punkt::Punkt()
{
	nazwa = "brak";
	x = 0;
	y = 0;
}


Punkt::Punkt(string n, float xx, float yy)
{
	nazwa = n;
	x = xx;
	y = yy;
}


Punkt::~Punkt()
{
}

