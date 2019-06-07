#ifndef Fish_H
#define Fish_H
#include <fstream>
#include "Animal.h"
using namespace std;
struct Fish 
{
	enum place
	{
		river,
		lake,
		sea,
		ocean
	}type;
};

void OutFish(Fish *p, ofstream &ofst);
Fish* InFish(Fish * p, ifstream & ifst);
#endif
