#pragma once
#include <iostream>
#include <string>
using namespace std;

class TRAIN {
public:
	setDestination(string newDestination);
	getDestination();
	setNumber(string newNumber);
	getNumber();
	setTime(string newTime);
	getTime();
	istream& operator>>(istream& is, TRAIN& train);
	ostream& operator<<(istream& os, TRAIN const& train);
private:
	string destination;
	string number;
	string time;
};