#include <iostream>
#include <fstream>

bool isProperty(int num) { // проверка на свойство (четность) 

	if (num % 2 == 0)
	{
		return true;
	}
	else {
		return false;
	}
}

int main() {
	setlocale(LC_ALL, "ru");

	std::fstream file_f("f.txt"); // открытие файлов для чтения и записи
	if (!file_f.is_open())
	{
		std::cout << "* Не удалось открыть файл *" << std::endl;
	}
	std::fstream file_g("g.txt");
	if (!file_g.is_open())
	{
		std::cout << "* Не удалось открыть файл *" << std::endl;
	}


	int num;

	while (file_f >> num) { // читаем посимвольно

		if (isProperty(num)) // если число обладает свойством
		{
			file_g << num << " "; // записываем его в файл g
		}

	}

	file_f.close(); // закрываем файлы
	file_g.close();
	
	std::cout << "* Успешно *";
	return 0;
}