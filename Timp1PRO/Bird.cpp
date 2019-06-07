#include "Bird.h"
#include <iostream>
#include <fstream>
using namespace std;
void OutBird (Bird *t, ofstream &ofst)
{
	ofst << "Отношение к перелету: "; //<< t->flying << endl;
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
	return t;
}