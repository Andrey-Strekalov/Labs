#include <iostream>
#include <string>


int main() {
	setlocale(LC_ALL, "ru");

	std::string names[10] = { // создаем массив из 20 строк 
	"Санкт - Петербург",
	"Гамбург",
	"Екатеринбург",
	"Сальск",
	"Orenburg",
	"Люксембург",
	"Ростов - на - Дону",
	"Ставрполь",
	"Москва",
	"Magderburg"

	};

	std::cout << "Порядковые номера городов с *burg/бург* ";
	for (int i = 0; i < names->size(); i++) // перебираем массив
	{
		std::string s = names[i]; // очередная строка
		size_t pos_1 = s.find("burg");
		size_t pos_2 = s.find("бург"); // ищем подстроку
		if (pos_1 != std::string::npos || pos_2 != std::string::npos) // если найдена
		{
			std::cout << i + 1 << " "; // выводим порядковый номер
		}
	}


	return 0;
}