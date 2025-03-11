#include <iostream>
#include <Windows.h> // для использования SetConsoleCP и SetConsoleOutputCP
#include "Header.h"

int main() {
	setlocale(LC_ALL, "ru");
	// меняем кодировку консоли для возможности рускоязычного ввода
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	book* myBook = new book;


	myBook->calcPriceOfpage();
	myBook->printInfo();


	delete myBook;
	return 0;
}
