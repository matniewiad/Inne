#include <iostream>
using namespace std;
#include <string>
#pragma once

class Punkt
{
private:
	//float x, y;
public:
	float x, y;
	string nazwa;

	void wczytaj();
	void wyswietl();
	float get_x();
	float get_y();

	Punkt();
	Punkt(string, float=0, float=0);
	~Punkt();

};

