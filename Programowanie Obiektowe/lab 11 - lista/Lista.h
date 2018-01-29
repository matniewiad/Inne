#pragma once
#include "Element.h"
#include <iostream>
using namespace std;

class Lista : public Element
{
public:
	Element *pierwszy;
	void push(int liczba); // dodawanie elementu na koniec listy
	void pop(int ktory);   // usuwanie wybranego elementu
	void wyswietl();

	Lista(void);
	~Lista(void);
};

