#include <iostream>
#include <string>


int main() {
	setlocale(LC_ALL, "ru");

	std::string names[10] = { // ������� ������ �� 20 ����� 
	"����� - ���������",
	"�������",
	"������������",
	"������",
	"Orenburg",
	"����������",
	"������ - �� - ����",
	"���������",
	"������",
	"Magderburg"

	};

	std::cout << "���������� ������ ������� � *burg/����* ";
	for (int i = 0; i < names->size(); i++) // ���������� ������
	{
		std::string s = names[i]; // ��������� ������
		size_t pos_1 = s.find("burg");
		size_t pos_2 = s.find("����"); // ���� ���������
		if (pos_1 != std::string::npos || pos_2 != std::string::npos) // ���� �������
		{
			std::cout << i + 1 << " "; // ������� ���������� �����
		}
	}


	return 0;
}