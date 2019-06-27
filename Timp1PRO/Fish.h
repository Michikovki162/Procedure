#ifndef Fish_H
#define Fish_H
#include <fstream>
#include "Animal.h"
using namespace std;
struct fish 
{
	enum place
	{
		river,
		lake,
		sea,
		ocean
	}type;
};

void Out_Fish(fish *p, ofstream &ofst);
fish* In_Fish(fish * p, ifstream & ifst);
#endif
