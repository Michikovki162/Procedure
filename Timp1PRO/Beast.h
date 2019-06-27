#ifndef Beast_H
#define Beast_H
#include <fstream>
#include "Animal.h"
using namespace std;
struct beast
{
	enum food
	{
		herbal,
		insects,
		meat
	}type;
};

void Out_Beast(beast *b, ofstream &ofst);
beast* In_Beast(beast * b, ifstream & ifst);
#endif