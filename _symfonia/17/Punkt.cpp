#include "Punkt.h"
#include <iostream>
using namespace std;


Punkt::Punkt(string nazwa = "brak nazwy", float xx = 0, float yy = 0)
{
	nazwa_punktu = nazwa;
	x = xx;
	y = yy;
}


Punkt::Punkt()
{
	nazwa_punktu = "brak nazwy";
	x = 0;
	y = 0;
}


Punkt::~Punkt()
{
}

void Punkt::wczytaj()
{
	cout << "wczytywanie danych punktu:" << endl;
	cout << "podaj nazwe: ";
	cin >> nazwa_punktu;

	cout << "podaj x: ";
	cin >> x;

	cout << "podaj y: ";
	cin >> y;
}
