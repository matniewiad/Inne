#include <iostream>
#include "Modul.h"
#include "Zadanie.h"
#include "funkcje.h"
#include <functional>
#include <algorithm>
#include <vector>
#include <list>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	vector<Modul> moduly;																		//wektor wszystkich odczytanych z pliku modulow
	vector<Zadanie> zadania;																	//wektor zadan niezerowych
	list<Zadanie> lista_zadan;																	//j.w. ale na liscie
	vector<vector<int>> wydajnosc;																//tabela mowiaca ktory program mozna wykonac na ktorej linii. 0 kolumna-program, 1-4 wartosci '0-1' (0-nie mozna wykonac zadania na tej maszynie, 1-mozna)
	int maszyn = 0, programow = 0;																//liczba maszyn i programow (zczytywana razem w wydajnoscia z pliku 'wydajnosc')
	vector<vector<int>> tabela_przezbrojen;														//wartosci w minutach
	vector<list<Zadanie>>linie;																	//wektor o rozmiarze takim, jak liczba maszyn/linii. Kazdy element wektora jest lista zadan rozmieszczonych na danej linii
	vector<list<int>> przezbrojenia;															//-||-. Kazde pole to czasy przezbrojenia miedzy kolejnymi zadaniami na linii
	vector<list<Rozwiazanie>> rozwiazania;														//rozwiazania -> ktore zadanie, na ktorej maszynie, kiedy sie zaczyna, kiedy sie konczy
	list<Zadanie> nieprzetworzone;																//zadania, ktore nie zostaly wrzucone na zadna maszyne, bo nigdzie nie moga zostac wykonane

	cout << "wczytaj moduly\n";
	wczytaj_dane_modul(moduly);																	//wczytywanie danych z plikow
	cout << "wczytaj zadanie\n";
	wczytaj_dane_zadanie(zadania);
	cout << "wczytaj wydajnosc\n";
	wczytaj_wydajnosc_maszyn(wydajnosc, &maszyn, &programow);
	cout << "wczytaj przezbrojenia\n";
	wczytaj_przezbrojenia(tabela_przezbrojen, programow);
	vec_to_list(zadania, lista_zadan);															//przepisanie wektora zadan na liste
	
	lista_zadan.sort(sort_zadanie_ilosc_malejaco());											//sortowanie zadan po czasie wykonania

	//wyswietl_wydajnosc(wydajnosc, maszyn, programow);
	
	wyswietl_zadania_list_tab(lista_zadan);
	
	proste_rozlozenie(lista_zadan, linie, wydajnosc, maszyn, nieprzetworzone);					//rozlozenie zadan bez uwzglednienia przezbrojen i terminow dostarczenia
	zapisz_nieprzetworzone_do_pliku(nieprzetworzone);											//zadania, ktore nie moga zostac wykonane na zadnej linii
	cout << "************************\n\n\n";
	cout << "Po rozlorzeniu \n";
	wyswietl_linie(linie, maszyn);																//zadania rozlozone na poszczegolne linie
	
	cout << "************************\n\n\n";
	wyswietl_zapelnienie_wszstkich_linii(linie);												//Cmax na kazdej linii bez przezbrojen
	
	wyznacz_przezbrojenia_w_prostym_harmonogramie(tabela_przezbrojen, linie, przezbrojenia);	//liczenie przezbrojen pomiedzy zadaniami na wszystkich liniach
	wyswietl_zapelnienie_wszstkich_linii_z_przezbrojeniami(linie, przezbrojenia);				//Cmax z uwzglednieniem przezbrojen
	
	wyswietl_czasy_przezbrojen(przezbrojenia);													//wartosci przezbrojen pomiedzy kolejnymi zadaniami
	
	//12.08
	wypelnij_rozwiazania(rozwiazania, linie, przezbrojenia);
	wyswietl_rozwiazania(rozwiazania);
	zapisz_rozwiazanie_do_pliku(rozwiazania, przezbrojenia);

	cout << "\n*****DONE*****\n" << endl;
	getchar();
	return 0;
}
