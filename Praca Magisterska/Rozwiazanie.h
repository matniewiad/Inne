#pragma once
#include "Zadanie.h"
#include <string>
//to mozna byloby zrobic ladniej dziedziczeniem, ale mi sie nie chce
class Rozwiazanie
{
public:
	Zadanie zad;					//ktore zadanie
	int S;							//kiedy sie zaczyna
	int C;							//kiedy sie konczy
	string start_time;				//konwerscja S -> hh:mm
	string end_time;				//konwersja C -> hh:mm
	int day;						//dzien, w ktorym ma sie wykonac
	int ktora_maszyna;
	Rozwiazanie(Zadanie zad_i, int Ci, int maszyna);
	Rozwiazanie();
	~Rozwiazanie();

	void wyswietl_rozwiazanie();
//private:
	void set_time_format();
};

