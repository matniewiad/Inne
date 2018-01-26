#include <iostream>
using namespace std;
#include "Punkt1D.h"
#include "Punkt2D.h"

int main()
{
	Punkt1D A(6);
	Punkt2D B(5,50);
	
	//cout << A.x_pub;
	cout << B.x_pub << " ," << B.y_pub << endl;


	cout << endl << endl << "dziala" << endl;
	system("pause");
	return 0;
}