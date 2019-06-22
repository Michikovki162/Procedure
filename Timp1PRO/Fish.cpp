#include "Fish.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
void OutFish(Fish *p, ofstream &ofst)
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
Fish* InFish(Fish * p, ifstream & ifst)
{
	int x;
	ifst >> x;
	if (x < 1 || x > 4)
	{
		cout << "Произошла ошибка при введении места обитания рыбы\n";
		system("pause");
		exit(1);
	}
	p->type = (Fish::place)x;
	return p;
}