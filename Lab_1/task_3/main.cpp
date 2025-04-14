#include <iostream>   // ����������� ���������� ��� �����-������
#include <fstream>    // ����������� ���������� ��� ������ � �������
#include <cctype>     // ��� isupper() � isalpha()

int main()
{
	setlocale(LC_ALL, "ru"); // ��������� ������� ������ ��� ����������� ������ ������

	// �������� ����� a.txt ��� ������
	std::fstream file_a("C:/Users/andre/source/repos/CODESRUN/text/a.txt");
	if (!file_a.is_open()) // ��������, ������� �� ������� ����
	{
		std::cout << "�� ������� ������� ���� a.txt";
	}
	// .... b.txt ��� ������ 
	std::ofstream file_b("output.txt"); // ��������, ������� �� ������� ����
	if (!file_b.is_open()) {
		std::cout << "�� ������� ������� ���� a.txt";

	}

	char symbol; // ���������� ��� ������ ���������� �������

	while (file_a.get(symbol)) { // ������ ���� �����������

		if (isupper(symbol) && isalpha(symbol)) // ���� ������ � ������� �������� � �������� ��������� ������
		{
			file_b << symbol; // ���������� � ����� ����
		}
	}

	std::cout << "**������� ������� ������������**";

	file_a.close(); // ��������� �����
	file_b.close();
	return 0; // ���������� ���������
}