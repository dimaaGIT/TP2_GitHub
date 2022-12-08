#include <iostream>

#include <fstream>
#include <Windows.h>
#include "Container.h"
using namespace std;

void openFileToRead(ifstream& in) {
	in.open("words.txt");
	if (!in.is_open()) {
		throw exception("Не удалось открыть файл для чтения!");
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
		cout << "Возникла ошибка!\n Информация об ошибке: " << ex.what() << endl;
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
		cout << "Добро пожаловать в меню Лабораторной работы №2!" << endl << endl
			 << "Для начала, давайте выберем, номер задания:" << endl
			 << "1. Стандартные потоки;" << endl
			 << "2. Файловые и строковые потоки;" << endl
			 << "3. Выход." << endl << endl
			 << "Ваш выбор: ";
		cin >> mode;
		system("cls");
		switch (mode) {
		default: {
			cout << "Такого пункта нет!" << endl;
			system("pause");
		}
			   break;

		case(1): {
			while (true) {
				int modeFor1;
				system("cls");
				cout << "Теперь вы попали в меню для действий с заданием №1!" << endl << endl
					 << "Возможные действия:" << endl
					 << "1. Добавление поезда;" << endl
					 << "2. Удаление поезда;" << endl
					 << "3. Редактирование поезда;" << endl
					 << "4. Вывести на экран информацию о поездах, отправляющихся после заданного времени;" << endl
					 << "5. Вывести на экран всё;" << endl
					 << "6. Выход." << endl << endl
					 << "Ваш выбор: ";
				cin >> modeFor1;
				system("cls");
				switch (modeFor1) {
				default: {
					cout << "Такого пункта нет!" << endl;
					system("pause");
				}
					   break;
				case(1): {
					cin.get();
					TRAIN newTrain;
					cin >> newTrain;
					massive.add(newTrain);
					system("cls");
					cout << "Вы добавили поезд!" << endl;
					system("pause");
				}
					   break;
				case(2): {
					size_t num;
					cout << "Пожалуйста, введите номер поезда для удаления: ";
					cin >> num;
					massive.deleteTrain(num);
					system("cls");
					cout << "Вы удалили поезд!" << endl;
					system("pause");
				}
					   break;
				case(3): {
					size_t num;
					string param;
					string new_value;
					cout << "Пожалуйста, введите номер поезда для редактирования: ";
					cin >> num;
					system("cls");
					cout << "Пожалуйста, введите название параметра для изменения." << endl
						 << "Доступные названия : \"пункт\" или \"destination\", \"номер\" или \"number\", \"время\" или \"time\"." << endl
						 << "Ввод: ";
					cin >> param;
					system("cls");
					cout << "Пожалуйста, введите новое значение параметра: ";
					cin >> new_value;
					massive.editTrain(num, param, new_value);
					system("cls");
					cout << "Вы изменили данные!" << endl;
					system("pause");
				}
					   break;
				case(4): {
					string time;
					cout << "Пожалуйста, введите время: ";
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
					cout << "До новых встречь! =)" << endl;
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
			cout << "Количество слов в файле: " << countOfWords() << endl;
			system("pause");
		}
			   break;
		case(3): {
			cout << "До новых встречь! =)" << endl;
			system("pause");
		}
			   break;
		}
	}
}