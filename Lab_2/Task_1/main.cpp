#include <iostream>
#include "Header.h"
// Подключаем пользовательский заголовочный файл

int main() {
	setlocale(LC_ALL, "ru");

	realNum* realNumbers = new realNum;
	// Создание объекта класса realNumbers с помощью динамического выделения памяти

	realNumbers->inputNumbers();
	// Вызываем метод для ввода чисел

	realNumbers->printNumbers();
	// Вызываем метод для вывода чисел

	realNumbers->procNum();
	// Вызываем метод для обработки чисел

	delete realNumbers;

	return 0;
	// Возвращаем 0, указывая на успешное завершение программ
}
