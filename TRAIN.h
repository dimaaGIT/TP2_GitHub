#pragma once
#include <iostream>
#include <string>
using namespace std;

class TRAIN {
public:
	void setDestination(string newDestination);
	string getDestination();
	void setNumber(string newNumber);
	string getNumber();
	void setTime(string newTime);
	string getTime();
	friend istream& operator>>(istream& is, TRAIN& train);
	friend ostream& operator<<(ostream& os, TRAIN const& train);
private:
	string destination;
	string number;
	string time;
};