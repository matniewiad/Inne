#pragma once
#include <iostream>
using namespace std;

#include "punkt_2d.h"
class Punkt_3D :
	public Punkt_2D
{
public:
	double z;

    void wyswietl()
    {
        cout << "x: " << x << "        y: " << y << "        z: " << z << endl;
    }

	Punkt_3D(void);
	~Punkt_3D(void);
};

