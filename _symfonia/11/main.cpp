#include <iostream>
using namespace std;
#include "osoba.h"

int main()
{
	//****************1***********************
	////zwykly wskaznik na skladnik obiektu
	//osoba ktos;
	//int *wsk_int;
	//wsk_int = &(ktos.numer_porzadkowy);
	//cout << "adr: " << wsk_int << "	*wsk: " << *wsk_int << endl;

	//****************2***********************
	osoba A, B, C;

	A.kolor_wlosow = 31;
	A.wzrost = 100;

	B.kolor_wlosow = 2;
	B.wzrost = 200;

	C.kolor_wlosow = 3;
	C.wzrost = 300;

	int osoba::*wskaz=&osoba::kolor_wlosow;
	cout << A.*wskaz << endl;

	osoba *wsk2;
	wsk2 = &B;
	//wsk2->wsk_kl;
	cout << "adr: " << wsk2 << "aa" << endl << wsk2->*wskaz << endl;

	cout << endl << endl << "dziala" << endl;
	system("pause");
	return 0;
}