#pragma once
#include <iostream>
using namespace std;
#include <string>

class Serial
{
private:
	string tytul;
	int sezon;
	int odcinek;
	

public:
	static int ilosc_seriali;

	Serial();
	Serial(string, int=1, int=1);
	~Serial();

	void dodaj_serial();	//nieuzywane
	void wyswietl();
	void dodaj_odcinek();
	void koniec_sezonu();

	string get_tytul();
	int get_sezon();
	int get_odcinek();
};




