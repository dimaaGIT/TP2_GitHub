#include "Container.h"

Container::Container() {
	first = nullptr;
	cout << "������ ����������� �� ��������� ��� ������ Container" << endl;
}

Container::Container(TRAIN train) {
	first = new ContainerItem(train, nullptr);
	cout << "������ ����������� � ����������� ��� ������ Container" << endl;
}

void Container::add(TRAIN train) {
	if (first != nullptr) {
		ContainerItem* now = first;
		if ((now->getItem()).getDestination() > train.getDestination()) {
			first = new ContainerItem(train, now);
		}
		else if (first->getNext() == nullptr) {
			first->setNext(new ContainerItem(train, nullptr));
		}
		else {
			while ((now->getNext() != nullptr) && (((now->getNext())->getItem()).getDestination() < train.getDestination())) {
				now = now->getNext();
			}
			if (now->getNext() == nullptr) {
				now->setNext(new ContainerItem(train, nullptr));
			}
			else {
				ContainerItem* contin = now->getNext();
				now->setNext(new ContainerItem(train, contin));
			}
		}
	}
}

void Container::editTrain(size_t num, string param, string new_value) {
	ContainerItem* now = first;

	for (size_t i = 1; i < num; ++i) {
		now = now->getNext();
	}

	if (param == "�����" || param == "destination") {
		(now->getItem()).setDestination(new_value);
	}
	else if (param == "�����" || param == "number") {
		(now->getItem()).setNumber(new_value);
	}
	else if (param == "�����" || param == "time") {
		(now->getItem()).setTime(new_value);
	}
}

void Container::deleteTrain(size_t num) {
	if (first != nullptr) {
		ContainerItem* now = first;
		ContainerItem* del_item = first->getNext();
		
	}
}