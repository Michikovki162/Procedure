#include "Bird.h"
#include <iostream>
#include <fstream>
using namespace std;
void OutBird (Bird *t, ofstream &ofst)
{
	ofst << "��������� � ��������: "; //<< t->flying << endl;
	if (t->flying == false)
	{
		ofst << "������������ ";
	}
	else
	{
		ofst << "���������� ";
	}
}
Bird * InBird(Bird * t, ifstream &ifst)
{
	ifst >> t->flying;
	return t;
}