#ifndef Animal_H
#define Animal_H
#include <fstream>
using namespace std;
enum opt { FISH, BIRD, BEAST };
struct Animal 
{
	opt key;
	void* obj;
	string name;
};

Animal * In(ifstream &ifst);
void Out(Animal *s, ofstream &ofst);
bool Compare(Animal * first, Animal * second);
#endif