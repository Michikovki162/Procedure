#ifndef Animal_H
#define Animal_H
#include <fstream>
using namespace std;
enum opt { FISH, BIRD };
struct Animal 
{
	opt key;
	void* obj;
	string name;
	int length;
};

Animal * In(ifstream &ifst);
void Out(Animal *s, ofstream &ofst);
#endif