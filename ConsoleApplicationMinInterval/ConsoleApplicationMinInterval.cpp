// ConsoleApplicationMinInterval.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "MinIntervalDLL.h"

using namespace std;

int main()
{
	vector<point> vect(5);
	for (int i = 0; i < 5; i++) 
		cin >> vect[i].x >> vect[i].y;

	cout << MinInterval(vect);
	return 0;
}
