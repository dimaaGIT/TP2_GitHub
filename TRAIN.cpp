#include "TRAIN.h"

void TRAIN::setDestination(string newDestination) {
	this->destination = newDestination;
}

string TRAIN::getDestination() {
	return this->destination;
}

void TRAIN::setNumber(string newNumber) {
	this->number = newNumber;
}

string TRAIN::getNumber() {
	return this->number;
}

void TRAIN::setTime(string newTime) {
	this->time = newTime;
}

string TRAIN::getTime() {
	return this->time;
}

istream& operator>>(istream& is, TRAIN& train) {
	cout << "������� ����� ����������: ";
	getline(is, train.destination);
	cout << "������� ����� ������: ";
	getline(is, train.number);
	cout << "������� ����� �����������: ";
	getline(is, train.time);
	return is;
}

ostream& operator<<(ostream& os, TRAIN const& train) {
	os << "����� ����������: " << train.destination << endl 
	   << "����� ������: " << train.number << endl
	   << "����� �����������: " << train.time << endl;
	return os;
}