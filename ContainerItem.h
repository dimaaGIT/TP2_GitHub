#pragma once
#include "TRAIN.h"

struct ContainerItem {
	ContainerItem(TRAIN item, ContainerItem* next);
	void setItem(TRAIN item);
	TRAIN& getItem();
	void setNext(ContainerItem* next);
	ContainerItem* getNext();
private:
	TRAIN item;
	ContainerItem* next;
};