#pragma once
#include <iostream>
using namespace std;
#include <string>

class Stos
{
private:
	int n;

public:
	string tab[100];

	void push()
    {
        string i;
        cin >> i;
        tab[n] = i;
        n++;
    }

	void pop()
	{
		cout << tab[n-1] << endl;
		n--;
	}

	Stos(void);
	~Stos(void);
};

