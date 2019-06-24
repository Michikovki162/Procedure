// Timp1PRO.cpp: определяет точку входа для консольного приложения.
//

#include "Container.h"
#include "Bird.h"
#include "Fish.h"
#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char* argv[])
{
	int a;
	if (argc != 3) {
		cout << "incorrect command line! "
			"Waited: command in_file out_file"
			<< endl;
		system("pause");
		exit(1);
	}
	setlocale(LC_ALL, "Russian");
	ifstream ifst(argv[1]);
	if (!ifst)
	{
		cout << "Файл ввода не открыт!\n";
		system("pause");
		exit(1);
	}
	ofstream ofst(argv[2]);	if (!ofst)
	{
		cout << "Файл вывода не открыт!\n";
		system("pause");
		exit(1);
	}	cout << "Start" << endl;
	setlocale(LC_ALL, "Russian");
	container c;
	Init(c);
	In(c, ifst);
	ofst << "Filled container. " << endl;

	Out(c, ofst);
	MultiMethod(c, ofst);
	Clear(c);
	ofst << "Empty container. " << endl;
	Out(c, ofst);
	cout << "Stop" << endl;
	system("pause");
	cin >> a;
	return 0;
}

