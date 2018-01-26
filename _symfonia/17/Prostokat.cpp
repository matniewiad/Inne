#include "Prostokat.h"
#include <iostream>
using namespace std;


Prostokat::Prostokat(string nazwa = "brak nazwy", float szer = 1, float wys = 1, float x = 0, float y = 0)
{
	nazwa_prostokata = nazwa;
	szerokosc = szer;
	wysokosc = wys;
	x_w = x;
	y_w = y;
}

Prostokat::Prostokat()
{
	nazwa_prostokata = "brak nazwy";
	szerokosc = 1;
	wysokosc = 1;
	x_w = 0;
	y_w = 0;
}


Prostokat::~Prostokat()
{
}

void Prostokat::wczytaj()
{
	cout << "wczytywanie danych prostokata:" << endl;

	cout << "podaj nazwe: ";
	cin >> nazwa_prostokata;

	cout << "podaj szerokosc: ";
	cin >> szerokosc;

	cout << "podaj wysokosc: ";
	cin >> wysokosc;

	cout << "podaj wspolrzedna x lewego dolnego naroznika: ";
	cin >> x_w;

	cout << "podaj wspolrzedna y lewego dolnego naroznika: ";
	cin >> y_w;
}
