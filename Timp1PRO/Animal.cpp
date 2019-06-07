#include "Animal.h"
#include "Fish.h"
#include "Bird.h"
#include "Beast.h"
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
	else if (key == 3)
	{
		Beast* b = new Beast;
		s->obj = (void*)InBeast(b, ifst);
		s->key = BEAST;
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
		ofst << "��� ����. ��������: " << s->name << endl;
		OutFish((Fish*)s->obj, ofst);
		break;
	case BIRD:
		ofst << "��� �����. ��������: " << s->name << endl;
		OutBird((Bird*)s->obj, ofst);
		break;
	case BEAST:
		ofst << "��� �����. ��������: " << s->name << endl;
		OutBeast((Beast*)s->obj, ofst);
		break;
	default:
		cout << "������������ �������� " << endl;
	}
}