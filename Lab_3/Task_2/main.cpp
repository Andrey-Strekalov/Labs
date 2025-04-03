#include <iostream>
#include <string>

#include <Windows.h> // ��� ������������� SetConsoleCP � SetConsoleOutputCP

using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	// ������ ��������� ������� ��� ����������� ������������� �����
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string text;
	cout << "������� �����: ";
	getline(cin, text); // ��������� ������ �������

	string result = ""; // �������������� ������

	// �������� �� ������ �����������
	for (int i = 0; i < text.length(); i++) {
		// ���������, �� �������� �� ������� ������ '$'
		if (text[i] != '$') {
			// ���������, ���� �� ������ ����� �������
			if (text[i] == ' ' && i + 1 < text.length() && text[i + 1] == ',') {
				continue; // ���������� ������ ����� �������
			}
			result += text[i]; // ��������� ������ � ���������
		}
	}

	cout << "������������ �����: " << result << endl;
	return 0;
}

