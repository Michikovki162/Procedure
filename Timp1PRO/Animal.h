#ifndef Animal_H
#define Animal_H
#include <fstream>
using namespace std;
enum opt { FISH, BIRD, BEAST };
struct animal 
{
	opt key;
	void* obj;
	string name;
	int age;
};

animal * In(ifstream &ifst);
void Out(animal *s, ofstream &ofst);
bool Compare(animal * first, animal * second);
#endif