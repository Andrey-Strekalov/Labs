#include <iostream>
#include <string>

#include <Windows.h> // для использования SetConsoleCP и SetConsoleOutputCP

using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	// меняем кодировку консоли для возможности рускоязычного ввода
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string text;
	cout << "Введите текст: ";
	getline(cin, text); // Считываем строку целиком

	string result = ""; // Результирующая строка

	// Проходим по тексту посимвольно
	for (int i = 0; i < text.length(); i++) {
		// Проверяем, не является ли текущий символ '$'
		if (text[i] != '$') {
			// Проверяем, есть ли пробел перед запятой
			if (text[i] == ' ' && i + 1 < text.length() && text[i + 1] == ',') {
				continue; // Пропускаем пробел перед запятой
			}
			result += text[i]; // Добавляем символ в результат
		}
	}

	cout << "Исправленный текст: " << result << endl;
	return 0;
}

