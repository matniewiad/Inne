#pragma once
#include "zwierz.h"
#include <iostream>
using namespace std;

class Pies :
    public Zwierz
{
public:
    void daj_glos()
    {
        cout << "hau hau!" << endl;
    }
    Pies(char *i, int w)
    {
        imie = i;
        wiek = w;
    }
    Pies(void);
    ~Pies(void);
};