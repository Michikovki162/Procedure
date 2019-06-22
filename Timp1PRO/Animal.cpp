#include "Animal.h"
#include "Fish.h"
#include "Bird.h"
#include "Container.h"
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
		s->key = FISH;
		s->obj = (void*)InFish(p, ifst);
		ifst >> s->name;
		ifst >> s->age;
		return s;
	}
	else if (key == 2)
	{
		Bird* t = new Bird;
		s->obj = (void*)InBird(t, ifst);
		s->key = BIRD;
		ifst >> s->name;
		ifst >> s->age;
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
		ofst << "�������: " << s->age << endl;
		OutFish((Fish*)s->obj, ofst);
		break;
	case BIRD:
		ofst << "��� �����. ��������: " << s->name << endl;
		ofst << "�������: " << s->age << endl;
		OutBird((Bird*)s->obj, ofst);
		break;
	case BEAST:
		ofst << "��� �����. ��������: " << s->name << endl;
		ofst << "�������: " << s->age << endl;
		OutBeast((Beast*)s->obj, ofst);
		break;
	default:
		cout << "������������ �������� " << endl;
	}
}
bool Compare(Animal * first, Animal *second)
{
	if (namelength(*first) < namelength(*second) != true && namelength(*first) < namelength(*second) != false)
	{
		cout << "��������� ������ ��� ��������� ���� ��������\n";
		system("pause");
		exit(1);
	}
	return namelength(*first) < namelength(*second);
}