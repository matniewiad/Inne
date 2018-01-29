#ifndef PUNKT_1D_H
#define PUNKT_1D_H

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
	
    friend void wyswietl_punkt_1d(Punkt_1D);
    
    Punkt_1D(double);
    Punkt_1D(void);
    ~Punkt_1D(void);
	protected:
};

#endif
