#include <iostream>
#include <Windows.h> // Подключение библиотеки для работы с кодировкой консоли в Windows
#include <string>    // Подключение библиотеки для работы со строками
#include <vector>    // Для разделения строки на слова
#include <sstream>   // Для работы с stringstream
#include <algorithm> // Для функции isspace

// Функция для ввода текста с консоли
std::string inputText() {
	std::string text;  // Создаем переменную для хранения текста
	std::cout << "Введите текст: ";
	std::getline(std::cin, text);  // Считываем всю строку ввода (включая пробелы)
	return text;  // Возвращаем введенный текст
}

// Функция для поиска подстроки в тексте
std::size_t search(std::string text, std::string substr) {
	return text.find(substr);  // Используем метод find для поиска подстроки
	// Возвращает позицию подстроки или string::npos, если подстрока не найдена
}

// Функция для обработки текста (замена всех вхождений подстроки)
std::string procText(std::string text, std::string substr, std::string subSubstr) {
	bool temp = true;  // Флаг для продолжения цикла
	int len = substr.length();  // Длина подстроки, которую нужно заменить

	while (temp) {  // Цикл выполняется, пока находятся вхождения подстроки
		std::size_t position = search(text, substr);  // Ищем подстроку в тексте

		if (position != std::string::npos) {  // Если подстрока найдена
			// Заменяем подстроку на новую подстроку
			text.replace(position, len, subSubstr);
		}
		else {
			temp = false;  // Если подстрока не найдена, выходим из цикла
		}
	}

	return text;  // Возвращаем обработанный текст
}

std::string cleanText(const std::string& text) {
	std::string result;
	for (char c : text) {
		// Заменяем знаки препинания на пробелы, остальное оставляем как есть
		if (std::ispunct(static_cast<unsigned char>(c))) {
			result += ' ';
		}
		else {
			result += c;
		}
	}
	return result;
}


int countWords(const std::string& text) {
	std::string cleaned = cleanText(text);  // Очищаем текст перед подсчётом
	std::stringstream ss(cleaned); // создаем объект stringstream чтобы читать строку как поток данных
	std::string word; // переменная для записи текущего слова
	int count = 0;

	while (ss >> word) {  // если слово успешно прочитанно (пока оно есть) цикл выполняется
		count++; // увеличиваем счетчик
	}

	return count;
}

// Функция для подсчета предложений в тексте
int countSentences(const std::string& text) {
	int count = 0;
	for (char c : text) { // проходим по каждому символу в тексте
		if (c == '.' || c == '!' || c == '?') { // ищем концы предложений по знакам препинания
			count++;
		}
	}
	// Если текст не заканчивается на знак препинания, но не пустой
	if (!text.empty() && count == 0 && !std::all_of(text.begin(), text.end(), isspace)) {
		count = 1;
	}
	return count;
}

int main() {
	// Устанавливаем локаль для корректной работы с русским языком
	setlocale(LC_ALL, "ru");

	// Меняем кодировку консоли на Windows-1251 для правильного отображения русского текста
	SetConsoleCP(1251);         // Устанавливаем кодировку ввода
	SetConsoleOutputCP(1251);   // Устанавливаем кодировку вывода

	// Получаем текст от пользователя
	std::string p = inputText();

	// Выводим статистику до обработки
	std::cout << "\nСтатистика текста:\n";
	std::cout << "Количество слов: " << countWords(p) << "\n";
	std::cout << "Количество предложений: " << countSentences(p) << "\n\n";

	// Обрабатываем текст:
	// 1. Заменяем все вхождения "четыре" на "хорошо"
	// 2. Заменяем все скобки на пробелы
	p = procText(p, "четыре", "хорошо");
	p = procText(p, "Четыре", "Хорошо");
	p = procText(p, ")", " ");
	p = procText(p, "(", " ");

	// Выводим результат обработки
	std::cout << "Отформатированный текст: " << p << "\n";

	// Выводим статистику после обработки
	std::cout << "\nСтатистика после обработки:\n";
	std::cout << "Количество слов: " << countWords(p) << "\n";
	std::cout << "Количество предложений: " << countSentences(p) << "\n";

	return 0;
}