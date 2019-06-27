#include "Beast.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
void Out_Beast(beast *b, ofstream &ofst)
{
	ofst << "Тип питания: "; 
	if (b->type < 0 || b->type > 2)
	{
		cout << "Произошла ошибка при введении типа питания животного\n";
		system("pause");
		exit(1);
	}
	switch (b->type)
	{
	case 0:
		ofst << "Травоядный " << endl;
		break;
	case 1:
		ofst << "Насекомоядный " << endl;
		break;
	case 2:
		ofst << "Хищник " << endl;
		break;
	default:
		break;
	}
}
beast* In_Beast(beast * b, ifstream & ifst)
{
	int food;
	ifst >> food;
	if (food < 0 || food > 2)
	{
		cout << "Произошла ошибка при введении типа питания животного\n";
		system("pause");
		exit(1);
	}
	switch (food)
	{
	case 1:
		b->type = beast::food::herbal;
		break;
	case 2:
		b->type = beast::food::insects;
		break;
	case 3:
		b->type = beast::food::meat;
		break;
	default:
		break;
	}
	return b;
}