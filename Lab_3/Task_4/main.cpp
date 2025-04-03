#include <iostream>
#include <string>
#include <cctype>    // ��� ������������� isupper
#include <algorithm> // ��� ������� sort
#include <Windows.h> // ��� ��������� ��������� ������� (Windows)

// ������� ���������, ��� �� ������� str1 ���� � str2
bool allCharsExist(std::string str1, std::string str2) {
	for (char s : str1) {           // �������� �� ������� ������� ������ ������
		bool flag = false;          // ����: ������ �� ������
		for (char t : str2) {       // ��������� ������� ������ ������
			if (s == t) {           // ���� ������ ���������
				flag = true;        // ��������, ��� �����
				break;              // ������� �� ����������� �����
			}
		}
		if (!flag) {                // ���� ������ �� ������
			return false;           // ���������� false
		}
	}
	return true;                    // ��� ������� �������
}

// ������� ������� ��� ��������� ��������� ����� �� ������
std::string deleteWord(std::string text, std::string word) {
	bool flag = true;               // ���� ��� ����������� �����
	while (flag) {
		std::size_t pos = text.find(word); // ���� ������� �����
		int len = word.length();           // ����� ���������� �����
		if (pos != std::string::npos) {    // ���� ����� �������
			text.erase(pos, len);          // ������� ���
		}
		else {                           // ���� ����� ������ ���
			flag = false;                  // ��������� ����
		}
	}
	return text;                       // ���������� ������������ ������
}

int main() {
	setlocale(LC_ALL, "ru");           // ������������� ������ ��� �������� �����
	SetConsoleCP(1251);				   // ������ ��������� ������� ��� ����������� �������������� ����� � ������
	SetConsoleOutputCP(1251);

	std::string str1 = "", str2 = "";  // ��������� ������ ������

	std::cout << "������� ������ #1: ";
	std::getline(std::cin, str1);      // ��������� ������ ������
	std::cout << "������� ������ #2: ";
	std::getline(std::cin, str2);      // ��������� ������ ������

	// ��������� ������� �������� � ������� ���������
	if (allCharsExist(str1, str2)) {
		std::cout << "������ ������ ������ ������ ����������� �� ������ ������\n";
	}
	else {
		std::cout << "�� ������ ������ ������ ������ ����������� �� ������ ������\n";
	}

	str1 = deleteWord(str1, "����������"); // ������� ����� "����������" �� str1

	std::cout << "������ #1 ����� ���������: " << str1 << std::endl; // ������� ���������

	return 0;
}