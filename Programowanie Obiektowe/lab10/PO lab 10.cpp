// PO lab 10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <fstream>
#include "Punkt_1D.h"
#include "Punkt_2D.h"
#include "Punkt_3D.h"
#include <string>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));

    cout << "kolejnosc wywolywania konstruktorow" << endl;
    cout << "OBIEKT 1d" << endl;
    Punkt_1D ob1;
    cout << "OBIEKT 2d" << endl;
    Punkt_2D ob2;
    cout << "OBIEKT 3d" << endl;
    Punkt_3D ob3;

	cout << endl << "kolejnosc wywolywania destruktorow" << endl;
    cout << "OBIEKT 1d" << endl;
    ob1.Punkt_1D::~Punkt_1D();
    cout << "OBIEKT 2d" << endl;
    ob2.Punkt_2D::~Punkt_2D();
    cout << "OBIEKT 3d" << endl;
    ob3.Punkt_3D::~Punkt_3D();
	cout << "KONIEC TESTOW" << endl << endl;

	// zapis/odczyt
	fstream plik;
	fstream plik2;

	//przykladowe obiekty
	Punkt_1D ob6;
	Punkt_2D ob5;
	Punkt_3D ob4;

	// zapis do pliku punkty.txt
	plik.open("punkty.txt", ios::out | ios::in);
	plik << ob4.x << "; " << "; " << ob4.y << "; " << ob4.z << endl;
	plik << ob5.x << "; " << "; " << ob5.y << endl;
	plik << ob6.x << "; " << endl;
	plik.close();

	// odczyt z pliku punkty2.txt
	plik2.open("punkty2.txt", ios::in);
	if(plik2.good() == false)
	{
		cout << "nie udalo sie otworzyc pliku/ plik nie istnieje" << endl;
		system("pause");
	}

	char znak;
	cout << endl << "dane z odczytanego pliku" << endl;
	while(!plik2.eof())
	{
		plik2.get(znak);
		cout << znak;
	}
	plik2.close();

	system("pause");
	return 0;
}

