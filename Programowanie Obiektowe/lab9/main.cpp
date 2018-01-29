#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "punkt_1d.h"
#include "punkt_2d.h"
#include <iostream>

using namespace std;

/********************************************/
void wyswietl_punkt_2d(Punkt_2D obA)
{
    int a;
    int b;
    a = obA.x + 10;
    b = obA.y + 10;
    cout << "WYKRES 2D" << endl;
    for(int i = 20 ; i > 0 ; i--)
    {
        for(int j = 0 ; j < 20 ; j++)
        {   // wyswietlenie wykresu
           	if(j!=10 && i != 10)
                cout << " ";
            if(j == 10)
            	cout << "|";
            if(i==10)
                cout << "_";
            // wyswietlenie punktu 	    
        	if(i==b)
            {
                if(a==j)
                {
                    cout << "x";
                    j++;
            	}
            }          
        }
        cout << endl;
    }
}
/********************************************/
void wyswietl_punkt_1d(Punkt_1D obA)
{
	int a;
	a = obA.x + 10;
	cout << "WYKRES 1D" << endl;
	for(int i = 20 ; i > 0 ; i--)
    {
        for(int j = 0 ; j < 20 ; j++)
        {   // wyswietlenie wykresu
           	if(j!=10 && i != 10)
                cout << " ";
            if(j == 10)
            	cout << "|";
            if(i==10)
                cout << "_";
            // wyswietlenie punktu 	    
        	if(i==10)
            {
                if(a==j)
                {
                    cout << "x";
                    j++;
            	}
            }          
        }
        cout << endl;
    }
}

/********************************************/

int main(int argc, char** argv) 
{
	void wyswietl_punkt_2d(Punkt_2D);
	void wyswietl_punkt_1d(Punkt_1D);

	srand(time(NULL));

    Punkt_1D ob1;
    Punkt_2D ob2;

    ob2.wyswietl();
    wyswietl_punkt_2d(ob2);	
    
    cout << endl << endl;
    ob1.wyswietl();
    wyswietl_punkt_1d(ob1);

	return 0;
}
