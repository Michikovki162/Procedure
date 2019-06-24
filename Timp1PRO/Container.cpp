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
void MultiMethod(container &c, ofstream &ofst)
{
	ofst << "\nМультиметод" << endl;
	Node* current_i = c.Top;
	for (int i = 0; i < c.count; i++)
	{
		Node* current_j = current_i->Next;
		for (int j = 0; j < c.count; j++)
		{
			switch (current_i->data->key) 
			{
			case BIRD:
				switch (current_j->data->key)
				{
				case BIRD:
					ofst << "Птица и птица" << endl;
					break;
				case FISH:
					ofst << "Птица и рыба" << endl;
					break;
				default:
					ofst << "НЕизвестный тип" << endl;
				}
				break;
			case FISH:
				switch (current_j->data->key)
				{
				case BIRD:
					ofst << "Рыба и птица." << endl;
					break;
				case FISH:
					ofst << "\nРыба и рыба" << endl;
					break;
				default:
					ofst << "Неизвестный тип" << endl;
				}
				break;
			default:
				ofst << "Неизвестный тип" << endl;
			}
			Out(current_i->data, ofst);
			Out(current_j->data, ofst);
			current_j = current_j->Next;
		}
		current_i = current_i->Next;
	}
}