#pragma once
#include <iostream>
using namespace std;

#include "punkt_1d.h"
class Punkt_2D :
	public Punkt_1D
{
public:
	double y;

    void wyswietl()
    {
        cout << "x: " << x << "        y: " << y << endl;
    }

	Punkt_2D(void);
	~Punkt_2D(void);
};

