#include "Bird.h"
#include <iostream>
#include <fstream>
using namespace std;
void OutBird (Bird *t, ofstream &ofst)
{
	ofst << "Отношение к перелету: "; //<< t->flying << endl;
	if (t->flying == false)
	{
		ofst << "Неперелетная ";
	}
	else
	{
		ofst << "Перелетная ";
	}
}
Bird * InBird(Bird * t, ifstream &ifst)
{
	ifst >> t->flying;
	return t;
}