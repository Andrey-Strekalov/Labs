#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // ��� max_element


int main() {
	setlocale(LC_ALL, "ru");

	std::string names[20] = { // ������� ������ �� 20 ����� 
	"��������",
	"��������",
	"������",
	"������",
	"�������",
	"��������",
	"�������",
	"�����",
	"�������",
	"������",
	"�������",
	"�������",
	"������",
	"������",
	"��������",
	"��������",
	"������",
	"�����",
	"�������",
	"�����"
	};

	std::vector<int> counts; // ������ ����� �����
	std::string s; // ��� �������� ��������� ������
	for (int i = 0; i < names->size(); i++) // ������� ������� ���������
	{
		int count = 0; // ���������� ���� � �����
		s = names[i];
		for (int j : s) // ������������ ������� ������
		{
			count++; // ����������� ������� 
		}
		counts.push_back(count); // ����� ����� ���������� ����� � ������
	}

	// ������� � ������� ���������� ����� 
	std::cout << "���������� ���� � ����� ������� �����: " << *std::max_element(begin(counts), end(counts));


	return 0;
}