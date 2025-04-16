#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // для max_element


int main() {
	setlocale(LC_ALL, "ru");

	std::string names[20] = { // создаем массив из 20 строк 
	"Журавлев",
	"Иваненко",
	"Иванов",
	"Петров",
	"Сидоров",
	"Кузнецов",
	"Смирнов",
	"Попов",
	"Лебедев",
	"Козлов",
	"Новиков",
	"Морозов",
	"Павлов",
	"Волков",
	"Соловьёв",
	"Васильев",
	"Зайцев",
	"Белов",
	"Комаров",
	"Гусев"
	};

	std::vector<int> counts; // вектор длинн строк
	std::string s; // для хранения очередной строки
	for (int i = 0; i < names->size(); i++) // перебор массива построчно
	{
		int count = 0; // количество букв в слове
		s = names[i];
		for (int j : s) // посимвольный перебор строки
		{
			count++; // увеличиваем счетчик 
		}
		counts.push_back(count); // пушим длину очередного слова в вектор
	}

	// находим и выводим наибольшее число 
	std::cout << "Количество букв в самом длинном слове: " << *std::max_element(begin(counts), end(counts));


	return 0;
}