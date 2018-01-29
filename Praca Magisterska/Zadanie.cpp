#include "Zadanie.h"

int Zadanie::licznik_zadan = 0;

Zadanie::Zadanie(int numer_porzadkowy, long int inx, int prog, int na_kiedy, int ile, int czas_wykonania)
{
	lp = numer_porzadkowy;
	ilosc = ile;
	index = inx;
	program = prog;
	q = na_kiedy;
	p = czas_wykonania;
	p_calkowite = p*ilosc;
	licznik_zadan++;
}

Zadanie::Zadanie()
{
	lp = 0;
	ilosc = 0;
	index = 0;
	program = 0;
	q = 0;
	p = 0;
	p_calkowite = 0;
}

Zadanie::~Zadanie()
{
}

void Zadanie::wyswietl_zadanie()
{
	cout << "INFO O ZADANIU " << lp << "\n";
	cout << setw(11) << "lp:" << setw(9) << lp << endl;
	cout << setw(11) << "index:" << setw(9) << index << endl;
	cout << setw(11) << "ilosc:" << setw(9) << ilosc << endl;
	cout << setw(11) << "p:" << setw(9) << p << endl;
	cout << setw(11) << "q:" << setw(9) << q << endl;
	cout << setw(11) << "czas calk:" << setw(9) << p_calkowite << endl;
	cout << setw(11) << "program:" << setw(9) << program << endl << endl;
}

void Zadanie::wyswietl_zadanie_less()
{
	cout << setw(7) << "index:" << setw(9) << index << endl;
	cout << setw(7) << "ilosc:" << setw(9) << ilosc << endl;
	cout << setw(7) << "q:" << setw(9) << q << endl << endl;
}

void Zadanie::wyswietl_zadanie_tab()
{
	cout << setw(9) << index << setw(9) << ilosc << setw(9) << program << setw(9) << q << endl;
}
