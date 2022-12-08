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
	cout << "Введите пункт назначения: ";
	getline(is, train.destination);
	cout << "Введите номер поезда: ";
	getline(is, train.number);
	cout << "Введите время отправления: ";
	getline(is, train.time);
	return is;
}

ostream& operator<<(ostream& os, TRAIN const& train) {
	os << "Пункт назначения: " << train.destination << endl 
	   << "Номер поезда: " << train.number << endl
	   << "Время отправления: " << train.time << endl;
	return os;
}