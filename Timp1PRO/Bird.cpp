#include "Bird.h"
#include <iostream>
#include <fstream>
using namespace std;
void OutBird (Bird *t, ofstream &ofst)
{
	ofst << "��������� � ��������: "; //<< t->flying << endl;
	if (t->flying == false)
	{
		ofst << "������������ " << endl;
	}
	else
	{
		ofst << "���������� " << endl;
	}
}
Bird * InBird(Bird * t, ifstream &ifst)
{
	ifst >> t->flying;
	return t;
}