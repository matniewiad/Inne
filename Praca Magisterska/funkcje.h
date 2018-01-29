#pragma once
#include <iostream>
#include "Modul.h"
#include "Zadanie.h"
#include "Rozwiazanie.h"
#include <string>
#include <vector>
#include <list>
#include <fstream>
#include <sstream>

//wczytywanie
void wczytaj_dane_modul(vector<Modul>&moduly);
void wczytaj_dane_zadanie(vector<Zadanie>&zadania);
void wczytaj_wydajnosc_maszyn(vector<vector<int>> &wydajnosc, int*maszyn, int*programow);
void wczytaj_przezbrojenia(vector<vector<int>> &tabela_przezbrojen, int programow);

//wyswietlanie
void wyswietl_moduly(vector<Modul>moduly);
void wyswietl_zadania_vec_more(vector<Zadanie>zadania);
void wyswietl_zadania_vec_less(vector<Zadanie>zadania);
void wyswietl_zadania_vec_tab(vector<Zadanie>zadania);
void wyswietl_zadania_list_more(list<Zadanie>zadania);
void wyswietl_zadania_list_less(list<Zadanie>zadania);
void wyswietl_zadania_list_tab(list<Zadanie>zadania);
void wyswietl_wydajnosc(vector<vector<int>> &wydajnosc, int maszyn, int programow);
void wyswietl_przezbrojenia(vector<vector<int>> tabela_przezbrojen, int programow);
void wyswietl_linie(vector<list<Zadanie>>linie, int maszyn);
void wyswietl_zapelnienie_wszstkich_linii(vector<list<Zadanie>>linie);							//zajetosc linii
void wyswietl_zapelnienie_wszstkich_linii_z_przezbrojeniami(vector<list<Zadanie>>linie, vector<list<int>>przezbrojenia);
void wyswietl_czasy_przezbrojen(vector<list<int>>przezbrojenia);								//wyswietlanie czasu przezbrojen pomiedzy zadaniami													
void wyswietl_rozwiazania(vector<list<Rozwiazanie>>rozwiazania);										//wyswietla kolejne rozwiazania -> ktore zadanie, na ktorej maszynie, kiedy sie zaczyna, kiedy sie konczy


//comparatory do sortowania
struct sort_zadanie_ilosc_malejaco
{
	inline bool operator() (const Zadanie& struct1, const Zadanie& struct2)
	{
		return (struct1.ilosc > struct2.ilosc);
	}
};
struct sort_zadanie_q_rosnaco
{
	inline bool operator() (const Zadanie& struct1, const Zadanie& struct2)
	{
		return (struct1.q < struct2.q);
	}
};

//INNE
void vec_to_list(vector<Zadanie> wek, list<Zadanie>&lista);

//**********************************************************************************
//FUNKCJE GLOWNE

//zwraca zapelnienie 1 linii - sprawdza wszystkie zadania i sumuje ich calkowite czasy wykonania
int zapelnienie_linii(list<Zadanie>lista);
int zapelnienie_linii_z_przezbrojeniami(list<Zadanie>lista, list<int>przezbrojenia_tej_linii);

//rozklada zadania na linie bez uwzgledniania przezbrojen i 'q' | praca na kopii
void proste_rozlozenie(list<Zadanie>lista_zadan, vector<list<Zadanie>>&linie, vector<vector<int>>wydajnosc, int maszyn, list<Zadanie>& nieprzetworzone);

//zwraca numer linii, na ktora ma zostac wrzucone zadanie. Bierze pod uwage mozliwosci linii i ich zapelnienie
int na_ktora_linie_wrzucic(Zadanie zadanie, vector<vector<int>>wydajnosc, vector<list<Zadanie>> linie);

//dodanie przezbrojen - rozepchniecie harmonogramu na kazdej linii
void wyznacz_przezbrojenia_w_prostym_harmonogramie(vector<vector<int>>tabela_przezbrojen, vector<list<Zadanie>>&linie, vector<list<int>>&przezbrojenia);

//znajaz czas zakonczenia poprzedniego zadania wyznacza 'C' dla zadania 'zad'
//int wyznacz_C(int C, Zadanie zad);		//jednak niepotrzebne, bo to 1 linijka

//wypelnienie rozwiazan -> dopisanie S i C do zadan.
void wypelnij_rozwiazania(vector<list<Rozwiazanie>>&rozwiazania, vector<list<Zadanie>>linie, vector<list<int>> przezbrojenia);

//zapisywanie rozwiazan do pliku (kazda linia do oddzielnego pliku)
void zapisz_rozwiazanie_do_pliku(vector<list<Rozwiazanie>>rozwiazania, vector<list<int>> przezbrojenia);

string int_to_string(int n);		//c++11 string s = to_string(n);

//zapisywanie zadan nieprzetworzonych do pliku
void zapisz_nieprzetworzone_do_pliku(list<Zadanie> nieprzetworzone);
