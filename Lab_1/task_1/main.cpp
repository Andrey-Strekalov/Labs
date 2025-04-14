#include <iostream>
#include <fstream>



int main()
{
	setlocale(LC_ALL, "ru");

	std::ifstream file("a.txt"); // ��������� ���� a.txt ��� ������
	if (!file.is_open())
	{
		std::cout << "�� ������� ������� ���� a.txt";
	}

	double num; // ���������� ��� �������� �����
	int posCount = 0; // ������� ������������� �����
	double product = 1.0; // ������������ ������������� �����
	bool hasProduct = false; // ���� ��� �������� �� ������������� �� ������� ����� ������������� �����

	while (file >> num) { // ������ ���� ����������� 
		if (num > 0)
		{
			posCount++; // ���� ����� �������������, ����������� �������
		}
		if (num > 0 && num < 1)
		{
			product *= num; // ���� ����� �� 0 �� 1, ��������� � ������������ 
			hasProduct = true;
		}
	};

	// ����� �����������
	std::cout << "���������� ������������� ���������: " << posCount << std::endl;

	if (hasProduct)
	{
		std::cout << "������������ ����� � ��������� �� 0 �� 1: " << product << std::endl;
	}
	else {
		std::cout << " " << "����� � ��������� �� 0 �� 1 �� �������" << std::endl;
	}

	file.close(); // ��������� ����
	return 0;
}