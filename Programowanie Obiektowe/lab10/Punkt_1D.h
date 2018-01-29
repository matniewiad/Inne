#pragma once
#include <iostream>
using namespace std;

class Punkt_1D
{
public:
	double x;

    void wyswietl()
    {
        cout << "x: " << x << endl;
    }

	Punkt_1D(void);
	~Punkt_1D(void);
};

