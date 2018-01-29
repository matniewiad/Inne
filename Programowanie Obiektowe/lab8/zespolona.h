#ifndef ZESPOLONA_H
#define ZESPOLONA_H

#pragma once
#include <iostream>
#include <math.h>
using namespace std;

class Zespolona
{
    float r;
    float i;
public:
    float modul()
    {
        float M; // modul
        M = sqrt(r*r+i*i);
        return M;
    }

    void wyswietl()
    {
        if(i<0)
        cout << "liczba: " << r << i << "j" << endl;
        else
        cout << "liczba: " << r << "+" << i << "j" << endl;
    }
    
    friend ostream &operator<<(ostream&, Zespolona&);
    
    Zespolona operator+(Zespolona);
    Zespolona operator*(Zespolona);
    void operator+=(Zespolona);
    void operator*=(Zespolona);
    bool operator<(Zespolona);
    bool operator>(Zespolona);
    bool operator==(Zespolona);
    Zespolona(void);
    ~Zespolona(void);
};

#endif
