#include <iostream>
#include <Windows.h> // Подключение библиотеки для использования функций SetConsoleCP и SetConsoleOutputCP
#include "Header.h" // Подключение заголовочного файла с объявлением класса book

int main() {
	setlocale(LC_ALL, "ru");

	// Изменение кодировки консоли для поддержки русскоязычного ввода и вывода
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// Создание объекта класса book с помощью динамического выделения памяти (используется конструктор по умолчанию)
	book* myBook_1 = new book;

	myBook_1->calcPriceOfpage(); // Вычисление средней стоимости одной страницы
	myBook_1->printInfo();       // Вывод информации о книге

	// Создание объекта класса book с помощью динамического выделения памяти (используется конструктор с параметрами)
	book* myBook_2 = new book("Садоводство", 300, 900);

	myBook_2->calcPriceOfpage(); // Вычисление средней стоимости одной страницы
	myBook_2->printInfo();		 // Вывод информации о книге

	delete myBook_1; // Освобождение памяти
	delete myBook_2; // Освобождение памяти
	return 0;
}
