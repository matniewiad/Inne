#pragma once
#include <iostream>
using namespace std;
class Zwierz
{
public:
    char *imie;
    int wiek;
    virtual void daj_glos()=0;
    //{
      //  cout << "daje glos" << endl;
    //}

    /*Zwierz(char *i, int w)
    {
        imie = i;
        wiek = w;
    }*/
    Zwierz(void);
    ~Zwierz(void);
};
