// ConsoleApplicationMinInterval.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "MinIntervalDLL.h"

using namespace std;

int InputCheck() {
	int value;
	char remains;
	do {
		cin >> value;
		remains = cin.peek();
		if (remains != '\n' && remains != ' ') {
			cout << "Error! Invalid value was entered, enter it again: ";
			cin.clear();
			cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		}
	} while (remains != '\n' && remains != ' ');
	cin.clear();
	cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
	return value;
}

bool ContinueFunc() {
	cout << "Enter Y if you want to continue and N to exit: ";
	char ans;
	cin >> ans;
	while (ans != 'Y' && ans != 'N') {
		cout << "Error! Invalid value was entered, enter it again:  ";
		cin.clear();
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		cin >> ans;
	}
	if (ans == 'Y') {
		return true;
	}
	else {
		return false;
	}
}

int main()
{
	bool contin = true;
	while (contin)
	{
		int count;
		cout << "Enter the count of points: ";
		do {
			count = InputCheck();
			if (count < 0) cout << "Error! The count of points should be more than 0" << endl;
		} while (count < 0);
		vector<point> vect(count);
		for (int i = 0; i < count; i++) {
			cout << "Enter the x coordinate of element number " << i << ": ";
			vect[i].x = InputCheck();
			cout << "Enter the y coordinate of element number " << i << ": ";
			vect[i].y = InputCheck();
		}
		cout << "Received points: ";
		for (int i = 0; i < count; i++) {
			cout << "(" << vect[i].x << "," << vect[i].y << "); ";
		}
		cout << endl << "Result: " << MinInterval(vect);
		cout << endl << "Do you want to continue? ";
		contin = ContinueFunc();
	}
	return 0;
}