#include "Header.h"
// подключение заголовочного файла с объявлением класса realNum

#include <iostream>

// реализация конструктора класса realNum 
realNum::realNum() {

	a = 0;
	b = 0;
}

// реализация метода inputNumbers
void realNum::inputNumbers() {
	std::cout << "a = ";
	std::cin >> a;
	// Вводим значение для переменной a
	std::cout << "b = ";
	std::cin >> b;
	// Вводим значение для переменной b
}

// реализация метода printNumbers
void realNum::printNumbers() {
	std::cout << " Объект вещественных чисел a = " << a << " " << "b = " << b << std::endl;
	// Выводим значения переменных a и b
}

// реализация метода procNum
void realNum::procNum() {
	float diff = (a - b) / 2.0;
	// Вычисляем полуразность чисел a и b
	std::cout << "Полуразность чисел: " << diff;
}
