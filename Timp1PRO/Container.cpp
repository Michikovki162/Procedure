#include "Container.h"
#include <iostream>
#include <fstream>


using namespace std;
void In(container &c, ifstream &ifst)

{
	while (!ifst.eof())
	{
		if (Add_node(c, ifst) != 0)
			c.count++;
	}
}
int Add_node(container &c, ifstream &ifst)
{
	if (c.count == 0)
	{
		c.Top = new node;
		c.Top->next = c.Top;
		c.Top->prev = c.Top;
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
		node *current = c.Top;
		for (int j = 1; j < c.count; j++)
		{
			current = current->next;
		}
		current->next = new node;
		if ((current->next->data = In(ifst)) != 0)
		{
			c.Top->prev = current->next;
			current->next->prev = current;
			current->next->next = c.Top;
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
	if (c.count != 0)
	{
		Sort(c);
	}
	node* current = c.Top;
	ofst << " Container contains " << c.count
		<< " elements." << endl;
	for (int j = 0; j < c.count; j++)
	{
		ofst << j << ": ";
		Out(current->data, ofst);
		ofst << "Длина названия: " << Name_length(*(current->data)) << endl;
		current = current->next;
	}
}
void Clear(container & c)
{
	node* current = c.Top;
	int i = 1;
	while (i < c.count)
	{
		current = current->next;
		delete current->prev;
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
int Name_length(animal &s)
{
	int length = s.name.length();
	return length;
}

void Sort(container & c)
{
	node* current;
	current = c.Top;
	node* currentnext = current->next;
	for (int i = 1; i < c.count; i++)
	{
		for (int j = 1; j < c.count; j++)
		{
			if (Compare(current->data, current->next->data)) 
			{
				Process_sort(c.Top, current);
			}
			else
				current = current->next;
		}
		current = c.Top;
	}
}
void Process_sort(node *& headt, node *& current)
{
	node* currentnext = current->next;
	if (current == headt)
	{
		if (current->next->next == current)
		{
			headt = current->next;
		}
		else
		{
			castl(current);
			headt = current;
		}
	}
	else
	{
		if (current->next->next == current)
		{
			headt = current->next;
		}
		else
			castl(current);
	}
}
void castl(node* &current)
{
	node* currentnext = current->next;
	node* q1 = current;
	node* q2 = currentnext;
	current = q2;
	currentnext = q1;
	currentnext->next = current->next;
	current->next = currentnext;
	current->prev = currentnext->prev;
	currentnext->prev = current;
	currentnext = current->next;
	currentnext->next->prev = currentnext;
	current->prev->next = current;
}
void Out_only_Fish(container &c, ofstream &ofst)
{
	node* current = c.Top;
	for (int i = 0; i < c.count; i++)
	{
		ofst << i << ": ";
		if (current->data->key == FISH)
		{
			Out(current->data, ofst);
		}
		else
		{
			ofst << endl;
		}
		current = current->next;

	}
}