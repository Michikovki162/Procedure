#include "Bird.h"
#include <iostream>
#include <fstream>
using namespace std;
void Out_Bird (bird *t, ofstream &ofst)
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
bird * In_Bird(bird * t, ifstream &ifst)
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