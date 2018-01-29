#pragma once
#include "zwierz.h"
#include <iostream>
using namespace std;

class Kot :
    public Zwierz
{
public:
    void daj_glos()
    {
        cout << "miau" << endl;
    }

    Kot(char *i, int w)
    {
        imie = i;
        wiek = w;
    }
    Kot(void);
    ~Kot(void);
};
