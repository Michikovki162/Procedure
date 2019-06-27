#include "Animal.h"
#include "Fish.h"
#include "Bird.h"
#include "Container.h"
#include "Beast.h"
#include <iostream>
#include <fstream>
#include "string"
using namespace std;
animal * In(ifstream &ifst)
{
	animal *s = new animal;
	int key;
	ifst >> key;
	if (key == 1)
	{
		fish* p = new fish;
		s->key = FISH;
		s->obj = (void*)In_Fish(p, ifst);
		ifst >> s->name;
		ifst >> s->age;
		return s;
	}
	else if (key == 2)
	{
		bird* t = new bird;
		s->obj = (void*)In_Bird(t, ifst);
		s->key = BIRD;
		ifst >> s->name;
		ifst >> s->age;
		return s;
	}
	else if (key == 3)
	{
		beast* b = new beast;
		s->obj = (void*)In_Beast(b, ifst);
		s->key = BEAST;
		ifst >> s->name;
		return s;
	}
	else
	{
		return 0;
	}
}
void Out(animal *s, ofstream &ofst)
{
	switch (s->key)
	{
	case FISH:
		ofst << "Это рыба. Название: " << s->name << endl;
		ofst << "Возраст: " << s->age << endl;
		Out_Fish((fish*)s->obj, ofst);
		break;
	case BIRD:
		ofst << "Это птица. Название: " << s->name << endl;
		ofst << "Возраст: " << s->age << endl;
		Out_Bird((bird*)s->obj, ofst);
		break;
	case BEAST:
		ofst << "Это зверь. Название: " << s->name << endl;
		ofst << "Возраст: " << s->age << endl;
		Out_Beast((beast*)s->obj, ofst);
		break;
	default:
		cout << "Некорректное животное " << endl;
	}
}
bool Compare(animal * first, animal *second)
{
	if (Name_length(*first) < Name_length(*second) != true && Name_length(*first) < Name_length(*second) != false)
	{
		cout << "Произошла ошибка при сравнении длин названий\n";
		system("pause");
		exit(1);
	}
	return Name_length(*first) < Name_length(*second);
}