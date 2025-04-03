#include <iostream>
#include <string>
#include <cctype>    // ��� ������������� isupper
#include <algorithm> // ��� ������� sort
#include <Windows.h> // ��� ��������� ��������� ������� (Windows)

// ������� ��������� ������ �� ��������� � �������� �������
void filtSymbols(std::string* text, std::string* A_line, std::string* a_line) {
	for (char s : *text) {           // �������� �� ������� ������� ������
		if (isupper(s)) {            // ���� ������ ���������
			*A_line += s;            // ��������� � ������ ��������� ����
		}
		else {                     // ���� ������ ��������
			*a_line += s;            // ��������� � ������ �������� ����
		}
	}
}

int main() {
	setlocale(LC_ALL, "ru");


	std::string text = "";           // �������� ������
	std::string* txt_ptr = &text;    // ��������� �� �������� ������

	std::cout << "������� �����: ";
	std::getline(std::cin, text);    // ��������� ������ �� ������������

	std::string string_cptl = "", string_lwc = ""; // ������ ��� ��������� � �������� ��������
	std::string* cptl_ptr = &string_cptl;          // ��������� �� ������ ���������
	std::string* lwc_ptr = &string_lwc;            // ��������� �� ������ ��������

	filtSymbols(txt_ptr, cptl_ptr, lwc_ptr);      // �������� ������� ��� ���������� ��������

	sort(string_cptl.begin(), string_cptl.end()); // ��������� ��������� ������� �� ��������
	std::cout << string_cptl << std::endl;        // ������� ��������������� ��������� �������

	return 0;
}