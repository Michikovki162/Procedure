#ifndef Beast_H
#define Beast_H
#include <fstream>
#include "Animal.h"
using namespace std;
struct Beast
{
	enum food
	{
		herbal,
		insects,
		meat
	}type;
};

void OutBeast(Beast *b, ofstream &ofst);
Beast* InBeast(Beast * b, ifstream & ifst);
#endif