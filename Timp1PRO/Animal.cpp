#include "Animal.h"
#include "Fish.h"
#include "Bird.h"
#include <iostream>
#include <fstream>
#include "string"
using namespace std;
Animal * In(ifstream &ifst)
{
	Animal *s = new Animal;
	int key;
	ifst >> key;
	if (key == 1)
	{
		Fish* p = new Fish;
		//s.obj = (void*)InFish(*p, ifst);
		s->key = FISH;
		s->obj = (void*)InFish(p, ifst);
		ifst >> s->name;
		return s;
	}
	else if (key == 2)
	{
		Bird* t = new Bird;
		s->obj = (void*)InBird(t, ifst);
		s->key = BIRD;
		ifst >> s->name;
		return s;
	}
	else
	{
		return 0;
	}
}
void Out(Animal *s, ofstream &ofst)
{
	switch (s->key)
	{
	case FISH:
		ofst << "Это рыба. Название: " << s->name << endl;
		OutFish((Fish*)s, ofst);
		break;
	case BIRD:
		ofst << "Это птица. Название: " << s->name << endl;
		OutBird((Bird*)s, ofst);
		break;
	default:
		cout << "Некорректное животное " << endl;
	}
}