#include <iostream>   // ����������� ���������� ��� �����-������
#include <fstream>    // ����������� ���������� ��� ������ � �������

bool isProperty(int num) { // ������� �������� ����� �� �������� (��������� ����)

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
	setlocale(LC_ALL, "ru"); // ��������� ������� ������ ��� ����������� ������ ������

	// �������� ����� a.txt ��� ������
	std::fstream file_a("C:/Users/andre/source/repos/CODESRUN/text/a.txt");
	if (!file_a.is_open()) // ��������, ������� �� ������� ����
	{
		std::cout << "�� ������� ������� ���� a.txt";
	}

	int num;
	int summ = 0;

	while (file_a >> num) { // ��������� ���� �����������

		if (isProperty(num)) // ���� ����� �������� ���������
		{
			summ += num; // ��������� � �����
		}
	}

	std::cout << " ����� ����� ������� 3: " << summ;

	file_a.close();
	return 0; // ���������� ���������
}