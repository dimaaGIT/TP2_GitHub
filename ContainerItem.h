#pragma once
#include "TRAIN.h"

struct ContainerItem {
	ContainerItem(TRAIN item, ContainerItem* next);
	setItem(TRAIN item);
	getItem();
	setNext(ContainerItem* next);
	getNext();
private:
	TRAIN item;
	ContainerItem* next;
};