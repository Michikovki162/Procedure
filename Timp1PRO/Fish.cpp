#include "Fish.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
void OutFish(Fish *p, ofstream &ofst)
{
	string placeStrings[] = { "���� ","����� ","���� ","����� " };
	int x = (int)p->type;
	ofst << "����� ��������: " << placeStrings[x].data() << endl;
}
Fish* InFish(Fish * p, ifstream & ifst)
{
	int x;
	ifst >> x;
	p->type = (Fish::place)x;
	return p;
}