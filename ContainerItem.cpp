#include "ContainerItem.h"

ContainerItem::ContainerItem(TRAIN item, ContainerItem* next) {
	this->item = item;
	this->next = next;
	cout << "Вызван конструктор с параметрами для класса ContainerItem" << endl;
}

void ContainerItem::setItem(TRAIN item) {
	this->item = item;
}

TRAIN ContainerItem::getItem() {
	return this->item;
}

void ContainerItem::setNext(ContainerItem* next) {
	this->next = next;
}

ContainerItem* ContainerItem::getNext() {
	return this->next;
}