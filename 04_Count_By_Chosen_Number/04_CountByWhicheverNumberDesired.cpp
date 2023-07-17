//// 04_CountByWhicheverNumberDesired.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

string endStr;
string numberChosen;
string usrAnswer;
int incremented;
int answer;

int incrementFunc(string numberChosen) {
	incremented = stoi(numberChosen);
	for (int i = 0; i < 12; i++) {
		answer = stoi(numberChosen) + incremented;
		cout << numberChosen << " + " << incremented << " = ? " << endl;
		cin >> usrAnswer;
		if (stoi(usrAnswer) != answer) {
			cout << "Incorrect, Close program";
			cin >> endStr;
			return 0;
		}
		incremented = answer;
	}
}

int main()
{

    cout << "Pick a Number:\n";
	cin >> numberChosen;
	incrementFunc(numberChosen);
	cout << "All correct! Good Job, close program"; 
	cin >> endStr;

	return 0;
}

