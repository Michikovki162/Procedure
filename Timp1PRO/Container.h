#ifndef Container_H
#define Container_H
#include <fstream>
#include "Animal.h"
struct node 
{
	node() 
	{
		this->next = nullptr;
		this->prev = nullptr;
		this->data = nullptr;
	};
	node* next;
	node* prev;
	animal* data;
};
struct container 
{
	node* Top;
	int count;
};
void In(container &c, ifstream &ifst);
int Add_node(container &c, ifstream &ifst);
int Name_length(animal &s);
void Out_only_Fish(container &c, ofstream &ofst);
void Out(container & c, ofstream &ofst);
void Clear(container & c);
void Init(container & c);
void Sort(container &c);
void Process_sort(node*& headt, node*& current);
void castl(node* &current);
#endif
