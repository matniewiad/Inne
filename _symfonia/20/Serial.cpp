#include "Serial.h"


int Serial::ilosc_seriali = 0;

Serial::Serial()
{
	tytul = "brak";
	sezon = 0;
	odcinek = 0;
}


Serial::Serial(string t, int s, int e)
{
	tytul = t;
	sezon = s;
	odcinek = e;
}



Serial::~Serial()
{
}


void Serial::dodaj_serial()
{
	cout << "Podaj tytul: ";
	getline(cin, tytul);
	//cin >> tytul;
	sezon = 1;
	odcinek = 1;
	ilosc_seriali += 1;
}


void Serial::wyswietl()
{
	cout << tytul << "		s" << sezon << "e" << odcinek << endl;
}

void Serial::dodaj_odcinek()
{
	odcinek += 1;
}


void Serial::koniec_sezonu()
{
	sezon += 1;
	odcinek = 0;
}

string Serial::get_tytul()
{
	return tytul;
}

int Serial::get_sezon()
{
	return sezon;
}

int Serial::get_odcinek()
{
	return odcinek;
}
