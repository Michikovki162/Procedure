#include "Bird.h"
#include <iostream>
#include <fstream>
using namespace std;
void OutBird (Bird *t, ofstream &ofst)
{
	if (t->flying != false && t->flying != true)
	{
		cout << "��������� ������ ��� ������ ��������� ����� � ��������\n";
		system("pause");
		exit(1);
	}
	ofst << "��������� � ��������: "; 
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
	if (t->flying != false && t->flying != true)
	{
		cout << "��������� ������ ��� ����� ��������� ����� � ��������\n";
		system("pause");
		exit(1);
	}
	return t;
}