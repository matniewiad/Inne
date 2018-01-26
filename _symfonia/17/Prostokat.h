#pragma once
#include <iostream>
#include <string>
#include "Punkt.h"
using namespace std;

class Punkt;

class Prostokat
{
private:
	float szerokosc;
	float wysokosc;
	float x_w;
	float y_w;
	string nazwa_prostokata;

public:
	Prostokat(string, float, float, float, float);
	Prostokat();
	~Prostokat();

	void wczytaj();

	friend void sedzia(Punkt&, Prostokat&);
};

