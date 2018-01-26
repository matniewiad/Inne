#include <iostream>
using namespace std;
#include "osoba.h"

int main()
{
	const int ile = 5;

	// *****************1*****************************

	//osoba tablica_osob[ile];
	////wywolanie funkcji
	//tablica_osob[3].spiew();
	////testowanie wskaznika
	//cout << "WSKAZNIK" << endl;
	//osoba *wsk;
	//wsk = &tablica_osob[0];
	//wsk = tablica_osob;
	//wsk->spiew();

	////wskaznik ustawiony na poczatek
	//cout << "zapamietujemy " << ile << " osob" << endl;
	//for (int i = 0; i < ile; i++)
	//{
	//	cout << "podaj dane " << i + 1 << " osoby:" << endl;
	//	wsk->zapamietaj();
	//	wsk++;
	//}
	//wsk = tablica_osob;

	//cout << "wypisujemy " << ile << " osob (od poczatku)" << endl;
	//for (int i = 0; i < ile; i++)
	//{
	//	wsk->wypisz();
	//	wsk++;
	//}


	//******************************2*******************************************

	//osoba *wsk = new osoba[ile];
	//osoba *const wsk_pocz = wsk;		//zeby zawsze miec zapamietany poczatek
	////wsk->zapamietaj();
	////wsk->wypisz();
	//cout << wsk->numer_porzadkowy << endl;			//albo wsk[0].numer_porzadkowy, albo (*wsk).numer_porzadkowy
	//wsk = wsk + 3;
	//cout << wsk->numer_porzadkowy << endl;

	//cout << wsk_pocz->numer_porzadkowy << endl;
	////wsk_pocz += 3;			//blad, bo const

	//cout << osoba::licznik_pub << endl;

	////przed deletem ustawic wskaznik spowrotem na poczatek!
	//wsk = wsk_pocz;
	//delete[]wsk;

	//osoba *wsk2 = new osoba;
	//delete wsk2;

	//**********************************3***************************************
	osoba tab_osob[ile] = { osoba(13, "kowalski"),osoba(tab_osob[0]), osoba(), osoba(), osoba() };

	//cout << endl << endl << "dziala" << endl;
	cout << endl;
	system("pause");
	return 0;
}