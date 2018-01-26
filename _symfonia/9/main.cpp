#include <iostream>
using namespace std;

int main()
{
	int *tab_wsk[10];
	int tab[10] = {0,1,2,3,4,5,6,7,8,9};

	for (int i = 0 ; i < 10 ; i++)
	{
		tab_wsk[i] = &tab[i];		//przypisanie wskazniki
		cout << i << "	adr: " << tab_wsk[i] << endl;
		cout << "	"<< "wsk: " << *tab_wsk[i] << endl;
	}

	char *tab_wsk_string[3];

	tab_wsk_string[0] = "llalal";

	cout << "z gwazdka: " << *tab_wsk_string[0] << endl;		//tylko jedna litera
	cout << "bez gwazdki: " << tab_wsk_string[0];		//caly tekst



	cout << endl << endl << "dziala" << endl;
	system("pause");
	return 0;
}