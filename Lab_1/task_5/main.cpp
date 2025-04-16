#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip> // ��� left � setw()


struct Product { // �������� ���������� ����������� � ������
	std::string name;
	double price;
	std::string storage_conditions;
	std::string grade;
	std::string production_date;
	std::string expiration_date;
};

// �������� ����� � �����������
void createSampleFile(const std::string& filename) {
	std::ofstream out(filename); // ��������� ���� (��� ���������� � ���������) ��� ������
	if (out.is_open()) { // ��������� ������� � �������
		out << "������;89.90;�����������;������;15.02.2025;15.03.2025\n"
			<< "����;45.50;����� �����;������;20.02.2024;28.02.2024\n"
			<< "���;320.00;�����������;������;10.03.2025;10.04.2025\n"
			<< "������;120.00;���������� �����;������;05.04.2023;05.07.2023\n"
			<< "�������;280.00;�����������;������;01.03.2025;01.05.2025\n";
		out.close();
		std::cout << "�������� ���� ������: " << filename << std::endl;
	}
	else {
		//std::cerr << "������ �������� �����!" << std::endl; 
	}
}

// ������ ������� �� �����. ������� ���������� ������ ��������, ��������� ������ �� �������� �������� ����� 
std::vector<Product> readProducts(const std::string& filename) {
	std::vector<Product> products; // ������ ��� ������ ��������
	std::ifstream read_in(filename); // ��������� ���� ��� ������
	if (!read_in.is_open()) {
		std::cout << "������ �������� �����!" << std::endl;
		return products;
	}

	std::string line;
	while (getline(read_in, line)) { // ������ ����� ���������
		Product p;
		size_t pos = 0; // ��������� ������� ��� ������ ������� ����������
		std::string border = ";";


		pos = line.find(border); // ���� �������
		p.name = line.substr(0, pos); // ����������� ��� 
		line.erase(0, pos + border.length()); // ������� ��� ���������� ����������
		// ��������� ������ ���������� ����� �� �������
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

		products.push_back(p); // ����� ������������ ��������� ������ � ������ �������
	}

	read_in.close();
	return products;
}

// �������� ��������� ����� � ��������� ����. ������� ��������� ������ �� ���� �������� � ��� ��� �������� (������� ���) 
bool expiresInYear(const std::string& expiration_date, int year_to_check) {
	// ��������� ��� �� ���� (������ ��.��.����)
	int year = std::stoi(expiration_date.substr(6, 4));
	return year == year_to_check; // ������������ ��������� ���������, true/false
}

// ���������� �����������. ������� ��������� ������ �� �������� ��������� �����, ������ �� ������ ������� � ��� �������� 
void saveExpiringProducts(const std::string& filename,
	const std::vector<Product>& products,
	int year_to_check) {
	std::ofstream out(filename); // ��������� ���� ��� ������
	if (!out.is_open()) {
		std::cout << "������ �������� ����� �����������!" << std::endl;
		return;
	}
	// ���������� ������� ������ � ������� setw()
	out << "������ � ���������� ������ �������� � " << year_to_check << " ����:\n";
	out << "========================================\n";
	out << std::left << std::setw(20) << "������������"
		<< std::setw(15) << "����"
		<< std::setw(15) << "���� ��������" << std::endl;

	for (const auto& p : products) { // ������� ������� ������� � ����� ����������
		if (expiresInYear(p.expiration_date, year_to_check)) {
			out << std::left << std::setw(20) << p.name
				<< std::setw(15) << p.price
				<< std::setw(15) << p.expiration_date << std::endl;
		}
	}

	out.close();
	std::cout << "���������� ��������� � ����: " << filename << std::endl;
}

int main() {
	setlocale(LC_ALL, "ru");

	const std::string input_file = "products.txt"; // ����� �������� � ��������� ������
	const std::string output_file = "expiring_products.txt";

	// ������� �������� ���� 
	createSampleFile(input_file);

	// ������ ������ � �������
	std::vector<Product> products = readProducts(input_file);
	if (products.empty()) {
		std::cout << "��� ������ ��� ���������!" << std::endl;
		return 1;
	}

	// ����������� ��� ��� ��������
	int year_to_check;
	std::cout << "������� ��� ��� �������� ����� ��������: ";
	std::cin >> year_to_check;

	// ��������� ����������
	saveExpiringProducts(output_file, products, year_to_check);

	return 0;
}