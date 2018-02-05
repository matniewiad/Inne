#include <iostream>
#include "sort.h"
#include <vector>

int main()
{
	std::vector<int> vecINT{ 2,1,3,4,8,5,8 };
	std::vector<char> vecCHAR{ 'a','h','b','u','z','f' };
	std::vector<std::string> vecSTRING{ "Ala", "ma", "kota", "o", "imieniu", "Filemon" };

	show_vec(vecINT);
	show_vec(vecCHAR);
	show_vec(vecSTRING);

	MergeSort(vecINT, 0, 6);
	MergeSort(vecCHAR, 0, 5);
	MergeSort(vecSTRING, 0, 5);

	show_vec(vecINT);
	show_vec(vecCHAR);
	show_vec(vecSTRING);

	getchar();
	return 0;
}

