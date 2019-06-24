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
	if (c.count != 0)
	{
		Sort(c);
	}
	Node* current = c.Top;
	ofst << " Container contains " << c.count
		<< " elements." << endl;
	for (int j = 0; j < c.count; j++)
	{
		ofst << j << ": ";
		Out(current->data, ofst);
		ofst << "����� ��������: " << namelength(*(current->data)) << endl;
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

void Sort(container & c)
{
	Node* current;
	current = c.Top;
	Node* currentnext = current->Next;
	for (int i = 1; i < c.count; i++)
	{
		for (int j = 1; j < c.count; j++)
		{
			if (Compare(current->data, current->Next->data)) 
			{
				Processsort(c.Top, current);
			}
			else
				current = current->Next;
		}
		current = c.Top;
	}
}
void Processsort(Node *& headt, Node *& current)
{
	Node* currentnext = current->Next;
	if (current == headt)
	{
		if (current->Next->Next == current)
		{
			headt = current->Next;
		}
		else
		{
			castl(current);
			headt = current;
		}
	}
	else
	{
		if (current->Next->Next == current)
		{
			headt = current->Next;
		}
		else
			castl(current);
	}
}
void castl(Node* &current)
{
	Node* currentnext = current->Next;
	Node* q1 = current;
	Node* q2 = currentnext;
	current = q2;
	currentnext = q1;
	currentnext->Next = current->Next;
	current->Next = currentnext;
	current->Prev = currentnext->Prev;
	currentnext->Prev = current;
	currentnext = current->Next;
	currentnext->Next->Prev = currentnext;
	current->Prev->Next = current;
}
void Out_only_Fish(container &c, ofstream &ofst)
{
	Node* current = c.Top;
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
		current = current->Next;

	}
}
void MultiMethod(container &c, ofstream &ofst)
{
	ofst << "����������� " << endl;
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
					ofst << "����� � �����" << endl;
					break;
				case FISH:
					ofst << "����� � ����" << endl;
					break;
				case BEAST:
					ofst << "����� � �����" << endl;
					break;
				default:
					ofst << "������������ ���" << endl;
				}
				break;
			case FISH:
				switch (current_j->data->key)
				{
				case BIRD:
					ofst << "���� � �����" << endl;
					break;
				case FISH:
					ofst << "���� � ����" << endl;
					break;
				case BEAST:
					ofst << "���� � �����" << endl;
					break;
				default:
					ofst << "������������ ���" << endl;
				}
				break;
			case BEAST:
				switch (current_j->data->key)
				{
				case BEAST:
					ofst << "����� � �����" << endl;
					break;
				case BIRD:
					ofst << "����� � �����" << endl;
					break;
				case FISH:
					ofst << "����� � ����" << endl;
					break;
				default:
					ofst << "������������ ���" << endl;
				}
				break;
			default:
				ofst << "������������ ���" << endl;
			}
			Out(current_i->data, ofst);
			Out(current_j->data, ofst);
			current_j = current_j->Next;
		}
		current_i = current_i->Next;
	}
}