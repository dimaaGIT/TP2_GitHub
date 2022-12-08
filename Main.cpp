#include <iostream>

#include <fstream>
#include <Windows.h>
#include "Container.h"
using namespace std;

void openFileToRead(ifstream& in) {
	in.open("words.txt");
	if (!in.is_open()) {
		throw exception("�� ������� ������� ���� ��� ������!");
	}
}


size_t countOfWords() {
	ifstream file;
	string data;
	size_t counter = 0;
	bool flag;
	try {
		openFileToRead(file);
		while (!file.eof()) {
			flag = true;
			file >> data;
			for (auto& c : data) {
				if (!(c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z')) {
					flag = false;
					break;
				}
			}
			if (flag && data.length() <= 4) {
				++counter;
			}
		}
		file.close();
	}
	catch (const exception& ex) {
		cout << "�������� ������!\n ���������� �� ������: " << ex.what() << endl;
	}
	return counter;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Container massive;
	int mode = 0;
	while (mode < 1 || mode > 2) {
		system("cls");
		cout << "����� ���������� � ���� ������������ ������ �2!" << endl << endl
			 << "��� ������, ������� �������, ����� �������:" << endl
			 << "1. ����������� ������;" << endl
			 << "2. �������� � ��������� ������;" << endl
			 << "3. �����." << endl << endl
			 << "��� �����: ";
		cin >> mode;
		system("cls");
		switch (mode) {
		default: {
			cout << "������ ������ ���!" << endl;
			system("pause");
		}
			   break;

		case(1): {
			while (true) {
				int modeFor1;
				system("cls");
				cout << "������ �� ������ � ���� ��� �������� � �������� �1!" << endl << endl
					 << "��������� ��������:" << endl
					 << "1. ���������� ������;" << endl
					 << "2. �������� ������;" << endl
					 << "3. �������������� ������;" << endl
					 << "4. ������� �� ����� ���������� � �������, �������������� ����� ��������� �������;" << endl
					 << "5. ������� �� ����� ��;" << endl
					 << "6. �����." << endl << endl
					 << "��� �����: ";
				cin >> modeFor1;
				system("cls");
				switch (modeFor1) {
				default: {
					cout << "������ ������ ���!" << endl;
					system("pause");
				}
					   break;
				case(1): {
					cin.get();
					TRAIN newTrain;
					cin >> newTrain;
					massive.add(newTrain);
					system("cls");
					cout << "�� �������� �����!" << endl;
					system("pause");
				}
					   break;
				case(2): {
					size_t num;
					cout << "����������, ������� ����� ������ ��� ��������: ";
					cin >> num;
					massive.deleteTrain(num);
					system("cls");
					cout << "�� ������� �����!" << endl;
					system("pause");
				}
					   break;
				case(3): {
					size_t num;
					string param;
					string new_value;
					cout << "����������, ������� ����� ������ ��� ��������������: ";
					cin >> num;
					system("cls");
					cout << "����������, ������� �������� ��������� ��� ���������." << endl
						 << "��������� �������� : \"�����\" ��� \"destination\", \"�����\" ��� \"number\", \"�����\" ��� \"time\"." << endl
						 << "����: ";
					cin >> param;
					system("cls");
					cout << "����������, ������� ����� �������� ���������: ";
					cin >> new_value;
					massive.editTrain(num, param, new_value);
					system("cls");
					cout << "�� �������� ������!" << endl;
					system("pause");
				}
					   break;
				case(4): {
					string time;
					cout << "����������, ������� �����: ";
					cin >> time;
					system("cls");
					massive.departureAfter(time);
					system("pause");
				}
					   break;
				case(5): {
					massive.show();
					system("pause");
				}
					   break;
				case(6): {
					cout << "�� ����� �������! =)" << endl;
					system("pause");
				}
					   break;
				}
				if (modeFor1 == 6) {
					break;
				}
			}
		}
			   break;

		case(2): {
			cout << "���������� ���� � �����: " << countOfWords() << endl;
			system("pause");
		}
			   break;
		case(3): {
			cout << "�� ����� �������! =)" << endl;
			system("pause");
		}
			   break;
		}
	}
}