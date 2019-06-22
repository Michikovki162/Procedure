#include "Fish.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
void OutFish(Fish *p, ofstream &ofst)
{
	string placeStrings[] = { "���� ","����� ","���� ","����� " };
	int x = (int)p->type;
	if (x < 1 || x > 4)
	{
		cout << "��������� ������ ��� ������ ����� �������� ����\n";
		system("pause");
		exit(1);
	}
	ofst << "����� ��������: " << placeStrings[x].data() << endl;
}
Fish* InFish(Fish * p, ifstream & ifst)
{
	int x;
	ifst >> x;
	if (x < 1 || x > 4)
	{
		cout << "��������� ������ ��� �������� ����� �������� ����\n";
		system("pause");
		exit(1);
	}
	p->type = (Fish::place)x;
	return p;
}