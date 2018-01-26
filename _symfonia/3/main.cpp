#include <iostream>
#include <iomanip>
using namespace std;
#define N 5

int main()
{
	float tab[N];
	for (int i = 0 ; i<N ; i++)
	{
		tab[i] = sqrt(i+1);
	}

	float *wsk = &tab[0];
	//int *wsk = tab;

	cout << *wsk << endl;

	//for (int i = 0; i < N; i++)
	//{
	//	cout << i << "	wsk: " << fixed << setprecision(5) << *(wsk+i) << "		tab: " << *(&tab[i]) << endl;
	//	wsk++;
	//}

	/*
	int a = 5;
	int *wsk = &a;
	//wsk = &a;

	cout << "wks: " << wsk << endl;
	cout << "*wsk: " << *wsk << endl;
	cout << "&wsk: " << &wsk << endl;*/
	
	
	cout << "dziala" << endl;
	system("pause");
	return 0;
}