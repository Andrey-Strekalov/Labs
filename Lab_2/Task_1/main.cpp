#include <iostream>
#include "Header.h"
// ���������� ���������������� ������������ ����

int main() {
	setlocale(LC_ALL, "ru");

	realNum* realNumbers = new realNum;
	// �������� ������� ������ realNumbers � ������� ������������� ��������� ������

	realNumbers->inputNumbers();
	// �������� ����� ��� ����� �����

	realNumbers->printNumbers();
	// �������� ����� ��� ������ �����

	realNumbers->procNum();
	// �������� ����� ��� ��������� �����

	delete realNumbers;

	return 0;
	// ���������� 0, �������� �� �������� ���������� ��������
}
