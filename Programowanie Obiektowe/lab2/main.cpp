#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class trojkat
{
	public:
		int pole_a;
		int pole_b;
		int pole_c;
		
		void czy_prostokatny();
		void obwod();
};

int main(int argc, char** argv) 
{
	int koniec = 0;
	while(koniec == 0)
	{
		int wybor;
		cout << "menu:" << endl << "1." << endl << "2." << endl;
		cin >> wybor;
		switch(wybor)
		{
			case 1:
				break;
			
			case 2:
				break;
				
			default:
				break;
		}
	}
	return 0;
}
