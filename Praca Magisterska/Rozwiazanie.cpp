#include "Rozwiazanie.h"



Rozwiazanie::Rozwiazanie(Zadanie zad_i, int Ci, int maszyna)
{
	zad = zad_i;
	C = Ci;
	S = C - zad.p_calkowite;
	ktora_maszyna = maszyna;
	set_time_format();
}

Rozwiazanie::Rozwiazanie()
{
}


Rozwiazanie::~Rozwiazanie()
{
}

void Rozwiazanie::wyswietl_rozwiazanie()
{
	cout << setw(9) << zad.index << setw(9) << ktora_maszyna << setw(9) << S << setw(9) << C << endl;
}

void Rozwiazanie::set_time_format()
{
	day = 1;
	const unsigned min_per_h = 60;
	const unsigned min_per_day = 1440;
	const unsigned h_per_day = 24;
	const unsigned start_h = 14;
	unsigned hS, mS, hC, mC;

	hS = S / min_per_h + start_h;
	while (hS > h_per_day)
	{
		hS -= h_per_day;
		day++;
	}
	hC = C / min_per_h + start_h;
	while (hC > h_per_day)
		hC -= h_per_day;

	mS = S % min_per_h;
	mC = C % min_per_h;

	string h, m;
	//start
	h = to_string(hS);
	m = to_string(mS);
	if (mS < 10)
		start_time = h + ":0" + m;
	else
		start_time = h + ":" + m;
	//end
	h = to_string(hC);
	m = to_string(mC);
	if (mC < 10)
		end_time = h + ":0" + m;
	else
		end_time = h + ":" + m;
}
