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
	case 1:
		ofst << "���������� ";
		break;
	case 2:
		ofst << "������������� ";
		break;
	case 3:
		ofst << "������ ";
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