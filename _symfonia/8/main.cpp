#include <iostream>
using namespace std;
#include "osoba.h"

int main()
{
	osoba A, B, C;
	cout << "licznik osob: " << osoba::licznik_pub << endl;

	A.zapamietaj();
	B.zapamietaj();
	A.wypisz();
	B.wypisz();

	cout << "kopiowanie: " << endl;
	//osoba D = osoba(A);
	osoba D(A);
	D.wypisz();
	A.wypisz();

	cout << "licznik osob: " << osoba::licznik_pub << endl;
	
	//blok
	{
		osoba E, F;
		cout << "licznik osob w bloku: " << osoba::licznik_pub << endl;
	}

	cout << "licznik osob za blokiem: " << osoba::licznik_pub << endl;

	cout << endl << endl << "dziala" << endl;
	system("pause");
	return 0;
}