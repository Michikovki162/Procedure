#include "Beast.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
void OutBeast(Beast *b, ofstream &ofst)
{
	ofst << "��� �������: "; //<< t->flying << endl;
	switch (b->type)
	{
	case 0:
		ofst << "���������� " << endl;
		break;
	case 1:
		ofst << "������������� " << endl;
		break;
	case 2:
		ofst << "������ " << endl;
		break;
	default:
		break;
	}
}
Beast* InBeast(Beast * b, ifstream & ifst)
{
	int food;
	ifst >> food;
	switch (food)
	{
	case 1:
		b->type = Beast::food::herbal;
		break;
	case 2:
		b->type = Beast::food::insects;
		break;
	case 3:
		b->type = Beast::food::meat;
		break;
	default:
		break;
	}
	return b;
}