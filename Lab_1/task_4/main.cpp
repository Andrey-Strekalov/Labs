#include <iostream>   // Подключение библиотеки для ввода-вывода
#include <fstream>    // Подключение библиотеки для работы с файлами

bool isProperty(int num) { // функция проверки числа на свойство (кратность трем)

	if (num % 3 == 0)
	{
		return true;
	}
	else {
		return false;
	}
}

int main()
{
	setlocale(LC_ALL, "ru"); // Установка русской локали для корректного вывода текста

	// Открытие файла a.txt для чтения
	std::fstream file_a("C:/Users/andre/source/repos/CODESRUN/text/a.txt");
	if (!file_a.is_open()) // Проверка, удалось ли открыть файл
	{
		std::cout << "Не удалось открыть файл a.txt";
	}

	int num;
	int summ = 0;

	while (file_a >> num) { // считываем файл посимвольно

		if (isProperty(num)) // если число обладает свойством
		{
			summ += num; // добавляем к сумме
		}
	}

	std::cout << " Сумма чисел кратных 3: " << summ;

	file_a.close();
	return 0; // Завершение программы
}