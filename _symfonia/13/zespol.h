#pragma once
class zespol
{
private:
	float Rz;
	float Im;
public:
	zespol();
	zespol(float, float);
	~zespol();

	//funkcje skladowe
	void wprowadz(float, float);
	void wprowadz();
	void wyswietl();

	//przeladowanie operatorow
	zespol operator+(zespol);
	zespol operator-(zespol);
	zespol operator++();
	zespol operator++(int);
	zespol operator--();
	zespol operator--(int);
	zespol operator*(zespol);
};

