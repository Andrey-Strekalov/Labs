#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip> // для left и setw()


struct Product { // стуктцра содрежащая иннформацию о товаре
	std::string name;
	double price;
	std::string storage_conditions;
	std::string grade;
	std::string production_date;
	std::string expiration_date;
};

// Создание файла с информацией
void createSampleFile(const std::string& filename) {
	std::ofstream out(filename); // открываем файл (имя передается в параметре) для записи
	if (out.is_open()) { // заполняем данными о товарах
		out << "Молоко;89.90;холодильник;высший;15.02.2025;15.03.2025\n"
			<< "Хлеб;45.50;сухое место;первый;20.02.2024;28.02.2024\n"
			<< "Сыр;320.00;холодильник;высший;10.03.2025;10.04.2025\n"
			<< "Яблоки;120.00;прохладное место;второй;05.04.2023;05.07.2023\n"
			<< "Колбаса;280.00;холодильник;высший;01.03.2025;01.05.2025\n";
		out.close();
		std::cout << "Тестовый файл создан: " << filename << std::endl;
	}
	else {
		//std::cerr << "Ошибка создания файла!" << std::endl; 
	}
}

// Чтение товаров из файла. Фунцкия возвращает вектор структур, принимает ссылку на название входного файла 
std::vector<Product> readProducts(const std::string& filename) {
	std::vector<Product> products; // вектор для записи структур
	std::ifstream read_in(filename); // открываем файл для чтения
	if (!read_in.is_open()) {
		std::cout << "Ошибка открытия файла!" << std::endl;
		return products;
	}

	std::string line;
	while (getline(read_in, line)) { // чтение файла построчно
		Product p;
		size_t pos = 0; // начальная позиция для поиска границы информации
		std::string border = ";";


		pos = line.find(border); // ищем границу
		p.name = line.substr(0, pos); // присваиваем имя 
		line.erase(0, pos + border.length()); // удаляем уже записанную информацию
		// остальные данные записываем таким же образом
		pos = line.find(border);
		p.price = stod(line.substr(0, pos));
		line.erase(0, pos + border.length());

		pos = line.find(border);
		p.storage_conditions = line.substr(0, pos);
		line.erase(0, pos + border.length());

		pos = line.find(border);
		p.grade = line.substr(0, pos);
		line.erase(0, pos + border.length());

		pos = line.find(border);
		p.production_date = line.substr(0, pos);
		line.erase(0, pos + border.length());

		pos = line.find(border);
		p.expiration_date = line.substr(0, pos);
		line.erase(0, pos + border.length());

		products.push_back(p); // пушим составленную структуру товара в вектор товаров
	}

	read_in.close();
	return products;
}

// Проверка истечения срока в указанном году. Функция принимает ссылку на срок годности и год для проверки (текущий год) 
bool expiresInYear(const std::string& expiration_date, int year_to_check) {
	// Извлекаем год из даты (формат дд.мм.гггг)
	int year = std::stoi(expiration_date.substr(6, 4));
	return year == year_to_check; // возвращается результат выражения, true/false
}

// Сохранение результатов. Функция принимает ссылку на название выходного файла, ссылку на вектор товаров и год проверки 
void saveExpiringProducts(const std::string& filename,
	const std::vector<Product>& products,
	int year_to_check) {
	std::ofstream out(filename); // открываем файл для записи
	if (!out.is_open()) {
		std::cout << "Ошибка создания файла результатов!" << std::endl;
		return;
	}
	// формироуем таблицу данных с помощью setw()
	out << "Товары с истекающим сроком годности в " << year_to_check << " году:\n";
	out << "========================================\n";
	out << std::left << std::setw(20) << "Наименование"
		<< std::setw(15) << "Цена"
		<< std::setw(15) << "Срок годности" << std::endl;

	for (const auto& p : products) { // перебор вектора товаров и вывод информации
		if (expiresInYear(p.expiration_date, year_to_check)) {
			out << std::left << std::setw(20) << p.name
				<< std::setw(15) << p.price
				<< std::setw(15) << p.expiration_date << std::endl;
		}
	}

	out.close();
	std::cout << "Результаты сохранены в файл: " << filename << std::endl;
}

int main() {
	setlocale(LC_ALL, "ru");

	const std::string input_file = "products.txt"; // имена входного и выходного файлов
	const std::string output_file = "expiring_products.txt";

	// Создаем тестовый файл 
	createSampleFile(input_file);

	// Читаем данные о товарах
	std::vector<Product> products = readProducts(input_file);
	if (products.empty()) {
		std::cout << "Нет данных для обработки!" << std::endl;
		return 1;
	}

	// Запрашиваем год для проверки
	int year_to_check;
	std::cout << "Введите год для проверки срока годности: ";
	std::cin >> year_to_check;

	// Сохраняем результаты
	saveExpiringProducts(output_file, products, year_to_check);

	return 0;
}