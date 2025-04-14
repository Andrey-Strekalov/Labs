#include <iostream>   // Подключение библиотеки для ввода-вывода
#include <fstream>    // Подключение библиотеки для работы с файлами
#include <cctype>     // для isupper() и isalpha()

int main()
{
	setlocale(LC_ALL, "ru"); // Установка русской локали для корректного вывода текста

	// Открытие файла a.txt для чтения
	std::fstream file_a("C:/Users/andre/source/repos/CODESRUN/text/a.txt");
	if (!file_a.is_open()) // Проверка, удалось ли открыть файл
	{
		std::cout << "Не удалось открыть файл a.txt";
	}
	// .... b.txt для чтения 
	std::ofstream file_b("output.txt"); // Проверка, удалось ли открыть файл
	if (!file_b.is_open()) {
		std::cout << "Не удалось открыть файл a.txt";

	}

	char symbol; // переменная для записи очередного символа

	while (file_a.get(symbol)) { // читаем файл посимвольно

		if (isupper(symbol) && isalpha(symbol)) // если символ в верхнем регистре и является латинской буквой
		{
			file_b << symbol; // записываем в новый файл
		}
	}

	std::cout << "**Символы успешно перезаписаны**";

	file_a.close(); // закрываем файлы
	file_b.close();
	return 0; // Завершение программы
}