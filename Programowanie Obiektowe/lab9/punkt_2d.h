#ifndef PUNKT_2D_H
#define PUNKT_2D_H

#include "punkt_1d.h"
#include <iostream>
using namespace std;

class Punkt_2D : public Punkt_1D
{
	public:
		double y;

   		void wyswietl()
   		{
        	cout << "x: " << x << "    y: " << y << endl;
    	}

    friend void wyswietl_punkt_2d(Punkt_2D);
    
    Punkt_2D(double, double);
    Punkt_2D(void);
    ~Punkt_2D(void);
    
	protected:
};

#endif
