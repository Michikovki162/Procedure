#ifndef Bird_H
#define Bird_H
#include <fstream>
#include "Animal.h"
using namespace std;
struct bird 
{
	bool flying;
};
void Out_Bird(bird *t, ofstream &ofst);
bird * In_Bird(bird *t, ifstream &ifst);
#endif
