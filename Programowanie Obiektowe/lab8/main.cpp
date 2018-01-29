#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "zespolona.h"
using namespace std;

ostream &operator<<(ostream &ekran, Zespolona &ob1) // przeciazenie operatora <<
{
	if(ob1.i<0)
    ekran << "liczba: " << ob1.r << ob1.i << "j" << endl;
    else
    ekran << "liczba: " << ob1.r << "+" << ob1.i << "j" << endl;
}

/********************************************************/
/*********************MAIN*******************************/
/********************************************************/

int main(int argc, char** argv) 
{
    srand(time(NULL));

    Zespolona tab[10]; // tablica 10 obiektow

while(1)
    {
    for(int i=0; i<10; i++) // wyswietlanie listy liczb
    {
    	cout << i+1 << ". " << tab[i];
    }
    
    cout << endl << "KALKULATOR LICZB ZESPOLONYCH" << endl << "1. dodawanie" << endl << "2. mnozenie" << endl <<"3. czy wieksza (>)" << endl;
	cout << "4. czy mniejsza (<)" << endl << "5. czy rowna (==)" << endl << "6. modyfikacja elementu (kopiowanie)" << endl;
	
	int wybor;
	int temp1, temp2; // zmienne pomocnicze
	Zespolona ob2;    // zmienne pomocnicze
	cout << "podaj wybor" << endl;
    cin >> wybor;
    switch(wybor)
    {
    	case 1:
    		cout << "podaj lp. liczb, ktore chcesz dodac" << endl;
    		cin >> temp1;
    		cin >> temp2;
    		ob2 = tab[temp1-1]+tab[temp2-1];
    		cout << ob2 << endl;
    		break;
    		 	
    	case 2:
    		cout << "podaj lp. liczb, ktore chcesz pomnozyc" << endl;
    		cin >> temp1;
    		cin >> temp2;
    		ob2 = tab[temp1-1]*tab[temp2-1];
    		cout << ob2 << endl;
			break;
    		
    	case 3:
    		cout << "podaj lp. liczb, ktore chcesz porownac" << endl;
    		cin >> temp1;
    		cin >> temp2;
    		if(tab[temp1-1] > tab[temp2-1])
    		cout << "liczba 1. jest wieksza niz liczba 2." << endl;
    		else
    		cout << "liczba 1. nie jest wieksza niz liczba 2." << endl;
    		break;
    		
    	case 4:
    		cout << "podaj lp. liczb, ktore chcesz porownac" << endl;
    		cin >> temp1;
    		cin >> temp2;
    		if(tab[temp1-1] < tab[temp2-1])
    		cout << "liczba 1. jest mniejsza niz liczba 2." << endl;
    		else
    		cout << "liczba 1. nie jest mniejsza niz liczba 2." << endl;
    		break;
    		
    	case 5:
    		cout << "podaj lp. liczb, ktore chcesz porownac" << endl;
    		cin >> temp1;
    		cin >> temp2;
    		if(tab[temp1-1] == tab[temp2-1])
    		cout << "liczba 1. jest rowna liczbie 2." << endl;
    		else
    		cout << "liczba 1. nie jest rowna liczbie 2." << endl;
    		break;
    		
    	case 6:
    		cout << "ktory element tablicy zmodyfikowac?" << endl;
    		cin >> temp1;
    		cout << "ktory element tablicy chcesz zapisac do elementu tab[" << temp1-1 << "]?" << endl;
    		cin >> temp2;
    		tab[temp1-1] = tab[temp2-1];
    		break;
    		
    	default:
    		cout << "zly wybor, podaj inny" << endl;
    		break;
	}
	}
    return 0;
}
