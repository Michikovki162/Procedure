#include "Bird.h"
#include <iostream>
#include <fstream>
using namespace std;
void Out_Bird (bird *t, ofstream &ofst)
{
	if (t->flying != false && t->flying != true)
	{
		cout << "Произошла ошибка при выводе отношения птицы к перелету\n";
		system("pause");
		exit(1);
	}
	ofst << "Отношение к перелету: "; 
	if (t->flying == false)
	{
		ofst << "Неперелетная " << endl;
	}
	else
	{
		ofst << "Перелетная " << endl;
	}
}
bird * In_Bird(bird * t, ifstream &ifst)
{
	ifst >> t->flying;
	if (t->flying != false && t->flying != true)
	{
		cout << "Произошла ошибка при вводе отношения птицы к перелету\n";
		system("pause");
		exit(1);
	}
	return t;
}