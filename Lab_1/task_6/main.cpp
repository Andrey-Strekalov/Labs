#include <iostream>
#include <fstream>

bool isProperty(int num) { // �������� �� �������� (��������) 

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

	std::fstream file_f("f.txt"); // �������� ������ ��� ������ � ������
	if (!file_f.is_open())
	{
		std::cout << "* �� ������� ������� ���� *" << std::endl;
	}
	std::fstream file_g("g.txt");
	if (!file_g.is_open())
	{
		std::cout << "* �� ������� ������� ���� *" << std::endl;
	}


	int num;

	while (file_f >> num) { // ������ �����������

		if (isProperty(num)) // ���� ����� �������� ���������
		{
			file_g << num << " "; // ���������� ��� � ���� g
		}

	}

	file_f.close(); // ��������� �����
	file_g.close();
	
	std::cout << "* ������� *";
	return 0;
}