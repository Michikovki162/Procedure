#include "Fish.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
void Out_Fish(fish *p, ofstream &ofst)
{
	string placeStrings[] = { "Река ","Озеро ","Море ","Океан " };
	int x = (int)p->type;
	if (x < 1 || x > 4)
	{
		cout << "Произошла ошибка при выводе места обитания рыбы\n";
		system("pause");
		exit(1);
	}
	ofst << "Место обитания: " << placeStrings[x].data() << endl;
}
fish* In_Fish(fish * p, ifstream & ifst)
{
	int x;
	ifst >> x;
	if (x < 1 || x > 4)
	{
		cout << "Произошла ошибка при введении места обитания рыбы\n";
		system("pause");
		exit(1);
	}
	p->type = (fish::place)x;
	return p;
}