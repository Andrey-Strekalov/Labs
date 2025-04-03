#include <iostream>
#include <string>
#include <cctype>    // Для использования isupper
#include <algorithm> // Для функции sort
#include <Windows.h> // Для изменения кодировки консоли (Windows)

// Функция проверяет, все ли символы str1 есть в str2
bool allCharsExist(std::string str1, std::string str2) {
	for (char s : str1) {           // Проходим по каждому символу первой строки
		bool flag = false;          // Флаг: найден ли символ
		for (char t : str2) {       // Проверяем символы второй строки
			if (s == t) {           // Если символ совпадает
				flag = true;        // Отмечаем, что нашли
				break;              // Выходим из внутреннего цикла
			}
		}
		if (!flag) {                // Если символ не найден
			return false;           // Возвращаем false
		}
	}
	return true;                    // Все символы найдены
}

// Функция удаляет все вхождения заданного слова из строки
std::string deleteWord(std::string text, std::string word) {
	bool flag = true;               // Флаг для продолжения цикла
	while (flag) {
		std::size_t pos = text.find(word); // Ищем позицию слова
		int len = word.length();           // Длина удаляемого слова
		if (pos != std::string::npos) {    // Если слово найдено
			text.erase(pos, len);          // Удаляем его
		}
		else {                           // Если слова больше нет
			flag = false;                  // Завершаем цикл
		}
	}
	return text;                       // Возвращаем обработанную строку
}

int main() {
	setlocale(LC_ALL, "ru");           // Устанавливаем локаль для русского языка
	SetConsoleCP(1251);				   // Меняем кодировку консоли для возможности русскоязычного ввода и вывода
	SetConsoleOutputCP(1251);

	std::string str1 = "", str2 = "";  // Объявляем пустые строки

	std::cout << "Введите строку #1: ";
	std::getline(std::cin, str1);      // Считываем первую строку
	std::cout << "Введите строку #2: ";
	std::getline(std::cin, str2);      // Считываем вторую строку

	// Проверяем наличие символов и выводим результат
	if (allCharsExist(str1, str2)) {
		std::cout << "Каждый символ первой строки встречается во второй строке\n";
	}
	else {
		std::cout << "Не каждый символ первой строки встречается во второй строке\n";
	}

	str1 = deleteWord(str1, "разрушение"); // Удаляем слово "разрушение" из str1

	std::cout << "Строка #1 после обработки: " << str1 << std::endl; // Выводим результат

	return 0;
}