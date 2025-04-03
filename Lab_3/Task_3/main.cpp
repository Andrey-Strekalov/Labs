#include <iostream>
#include <string>
#include <cctype>    // Для использования isupper
#include <algorithm> // Для функции sort
#include <Windows.h> // Для изменения кодировки консоли (Windows)

// Функция разделяет строку на заглавные и строчные символы
void filtSymbols(std::string* text, std::string* A_line, std::string* a_line) {
	for (char s : *text) {           // Проходим по каждому символу строки
		if (isupper(s)) {            // Если символ заглавный
			*A_line += s;            // Добавляем в строку заглавных букв
		}
		else {                     // Если символ строчный
			*a_line += s;            // Добавляем в строку строчных букв
		}
	}
}

int main() {
	setlocale(LC_ALL, "ru");


	std::string text = "";           // Исходная строка
	std::string* txt_ptr = &text;    // Указатель на исходную строку

	std::cout << "Введите текст: ";
	std::getline(std::cin, text);    // Считываем строку от пользователя

	std::string string_cptl = "", string_lwc = ""; // Строки для заглавных и строчных символов
	std::string* cptl_ptr = &string_cptl;          // Указатель на строку заглавных
	std::string* lwc_ptr = &string_lwc;            // Указатель на строку строчных

	filtSymbols(txt_ptr, cptl_ptr, lwc_ptr);      // Вызываем функцию для разделения символов

	sort(string_cptl.begin(), string_cptl.end()); // Сортируем заглавные символы по алфавиту
	std::cout << string_cptl << std::endl;        // Выводим отсортированные заглавные символы

	return 0;
}