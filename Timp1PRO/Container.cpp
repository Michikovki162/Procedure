#include "Container.h"
#include <iostream>
#include <fstream>


using namespace std;
void In(container &c, ifstream &ifst)

{
	while (!ifst.eof())
	{
		if (addnode(c, ifst) != 0)
			c.count++;
	}
}
int addnode(container &c, ifstream &ifst)
{
	if (c.count == 0)
	{
		c.Top = new Node;
		c.Top->Next = c.Top;
		c.Top->Prev = c.Top;
		if ((c.Top->data = In(ifst)) != 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}

	}
	else
	{
		Node *current = c.Top;
		for (int j = 1; j < c.count; j++)
		{
			current = current->Next;
		}
		current->Next = new Node;
		if ((current->Next->data = In(ifst)) != 0)
		{
			c.Top->Prev = current->Next;
			current->Next->Prev = current;
			current->Next->Next = c.Top;
			return 1;
		}
		else
		{
			return 0;
		}
	}
}
void Out(container & c, ofstream &ofst)
{
	Node* current = c.Top;
	ofst << " Container contains " << c.count
		<< " elements." << endl;
	for (int j = 0; j < c.count; j++)
	{
		ofst << j << ": ";
		Out(current->data, ofst);
		ofst << "Длина названия: " << namelength(*(current->data))<< endl;
		current = current->Next;
	}
}
void Clear(container & c)
{
	Node* current = c.Top;
	int i = 1;
	while (i < c.count)
	{
		current = current->Next;
		delete current->Prev;
		i++;
	}
	delete current;
	c.count = 0;
}
void Init(container & c)
{
	c.Top = nullptr;
	c.count = 0;
}
int namelength(Animal &s)
{
	int length = s.name.length();
	return length;
}