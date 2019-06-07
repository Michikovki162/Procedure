#ifndef Container_H
#define Container_H
#include <fstream>
#include "Animal.h"
struct Node 
{
	Node() 
	{
		this->Next = nullptr;
		this->Prev = nullptr;
		this->data = nullptr;
	};
	Node* Next;
	Node* Prev;
	Animal* data;
};
struct container 
{
	Node* Top;
	int count;
};
void In(container &c, ifstream &ifst);
int addnode(container &c, ifstream &ifst);
void Out(container & c, ofstream &ofst);
void Clear(container & c);
void Init(container & c);
#endif
