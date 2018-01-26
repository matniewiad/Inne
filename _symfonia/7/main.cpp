#include <iostream>
using namespace std;
#include "osoba.h"

//deklaracje funkcji z argumentami typu obiekt - przez wartosc, wskaznik, referencje
void fun(osoba);
void fun_wsk(osoba*);
void fun_ref(osoba&);
void funkcja_zaprzyjazniona(osoba*);

int main()
{
	//funkcja zaprzyjazniona
	//osoba przyjaciel(10, "mlody");
	//przyjaciel.wypisz();
	//osoba *wsk;
	//wsk = &przyjaciel;
	//funkcja_zaprzyjazniona(wsk);
	//przyjaciel.wypisz();

	////////////////////////////////////////////////////////////////////////////////////////
	////obiekty const, volatile, volatile const
	//const osoba jakis_wazniak(15, "kowalski");		//nie moze korzystac z funkcji, ktore nie sa const
	//jakis_wazniak.spiew();
	//jakis_wazniak.funkcja_const();
	//jakis_wazniak.funkcja_VC();
	////jakis_wazniak.zapamietaj();					//nie da rady

	//volatile osoba obiekt_V;
	//obiekt_V.spiew();
	//obiekt_V.funkcja_volatile();
	//obiekt_V.funkcja_VC();
	////obiekt_V.zapamietaj();						//nie da rady

	//volatile const osoba VC;
	//VC.funkcja_VC();
	////VC.funkcja_const();	//nope
	////VC.funkcja_volatile();	//nope
	////VC.zapamietaj();		/tym bardziej nope

	//const volatile osoba CV;
	//CV.funkcja_VC();


	////wywolanie funkcji statycznej
	//cout << "spiewa klasa: ";
	//osoba::spiew();
	//osoba spiewak;
	//cout << "spiewa spiewak (obiekt): ";
	//spiewak.spiew();
	//cout << endl;

	////tworzenie obiektow z konstruktorem przeladowanym
	//osoba ja;
	//osoba ty(15, "abcd");

	//ja.wypisz();
	//ty.wypisz();
	//ja.funkcja_const();		//funkcje const moga dzialac z obiektami, ktore nie sa const
	/////////////////////////////////////////////////////////////////////////////////////


	////wywolanie destruktora
	//osoba ja;
	//ja.~osoba();

	////obiekt na wskazniku
	//osoba *wsk;

	////skladniki statyczne klasy
	//int a,b;
	//a = wsk->skladnik_statyczny_pub;
	//b = ja.skladnik_statyczny_pub;

	//wywolywanie funkcji skladowych i o argumentach typu obiekt
	//cout << "ja" << endl;
	//osoba ja;
	////ja.zapamietaj();
	////ja.wypisz();
	//fun(ja);

	//cout << "ty" << endl;
	//osoba *ty;
	//ty = &ja;
	
	//*ty->zapamietaj();

	//ty->wypisz();
	//ty->~osoba();*/

	//fun_wsk(ty);

	//cout << "ktos" << endl;
	//osoba &ktos = ja;
	////ktos.wypisz();
	//fun_ref(ktos);

	cout << endl << endl << "dziala" << endl;
	system("pause");
	return 0;
}


/////////////////////////////////////////////////////////////////////////////////////
//definicje funkcji z argumentami typu obiekt
void fun(osoba A)
{
	cout << "poczatek funkcji fun" << endl;
	A.zapamietaj();
	A.wypisz();
	//A.~osoba();
	cout << "koniec funkcji fun" << endl;
}

void fun_wsk(osoba*A)
{
	cout << "poczatek funkcji wsk" << endl;
	A->zapamietaj();
	A->wypisz();
	//A->~osoba();
	cout << "koniec funkcji wsk" << endl;
}

void fun_ref(osoba& A)
{
	cout << "poczatek funkcji fun_ref" << endl;
	A.zapamietaj();
	A.wypisz();
	//A.~osoba();
	cout << "koniec funkcji fun_ref" << endl;
}

//funkcja zaprzyjazniona
void funkcja_zaprzyjazniona(osoba*A)
{
	cout << "spiewa funkcja zaprzyjazniona" << endl;
	A->spiew();
	A->wiek += 5;
	char temp[] = "nazwisko zaprzyjaznione";
	strcpy_s(A->nazwisko, temp);
}