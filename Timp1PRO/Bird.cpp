#include "Bird.h"
#include <iostream>
#include <fstream>
using namespace std;
void OutBird (Bird *t, ofstream &ofst)
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
Bird * InBird(Bird * t, ifstream &ifst)
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