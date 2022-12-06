#pragma once
#include "ContainerItem.h"

class Container {
public:
	Container();
	Container(TRAIN train);
	void add(TRAIN train);
	void editTrain(size_t num, string param, string new_value);
	void deleteTrain(size_t num);
	bool departureAfter(string time);
	void show();
	~Container();
private:
	Container(const Container& other);
	Container& operator=(const Container& other);
	ContainerItem* first;
};