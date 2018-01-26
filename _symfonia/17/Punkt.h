#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "Prostokat.h"

class Prostokat;

class Punkt
{
private:
	float x;
	float y;
	string nazwa_punktu;

public:
	Punkt(string, float, float);
	Punkt();
	~Punkt();

	void wczytaj();

	friend void sedzia(Punkt&, Prostokat&);
};

