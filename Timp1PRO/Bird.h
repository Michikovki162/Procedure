#ifndef Bird_H
#define Bird_H
#include <fstream>
#include "Animal.h"
using namespace std;
struct Bird 
{
	bool flying;
};
void OutBird(Bird *t, ofstream &ofst);
Bird * InBird(Bird *t, ifstream &ifst);
#endif
