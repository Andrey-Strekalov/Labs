#include <iostream>
#include <fstream>



int main()
{
	setlocale(LC_ALL, "ru");

	std::ifstream file("a.txt"); // открываем файл a.txt для чтения
	if (!file.is_open())
	{
		std::cout << "Не удалось открыть файл a.txt";
	}

	double num; // переменная для хранения числа
	int posCount = 0; // счетчик положительных чисел
	double product = 1.0; // произведение положительных чисел
	bool hasProduct = false; // флаг для проверки на существование во входном файле положительных чисел

	while (file >> num) { // читаем файл посимвольно 
		if (num > 0)
		{
			posCount++; // если число положительное, увеличиваем счетчик
		}
		if (num > 0 && num < 1)
		{
			product *= num; // если число от 0 до 1, добавляем в произведение 
			hasProduct = true;
		}
	};

	// вывод результатов
	std::cout << "Количество положительных элементов: " << posCount << std::endl;

	if (hasProduct)
	{
		std::cout << "Произведение чисел в диапазоне от 0 до 1: " << product << std::endl;
	}
	else {
		std::cout << " " << "Чисел в диапазоне от 0 до 1 не найдено" << std::endl;
	}

	file.close(); // закрываем файл
	return 0;
}