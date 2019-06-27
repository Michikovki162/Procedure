#include "Fish.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
void Out_Fish(fish *p, ofstream &ofst)
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
fish* In_Fish(fish * p, ifstream & ifst)
{
	int x;
	ifst >> x;
	if (x < 1 || x > 4)
	{
		cout << "��������� ������ ��� �������� ����� �������� ����\n";
		system("pause");
		exit(1);
	}
	p->type = (fish::place)x;
	return p;
}