#include "Header.h"
// ����������� ������������� ����� � ����������� ������ realNum

#include <iostream>

// ���������� ������������ ������ realNum 
realNum::realNum() {

	a = 0;
	b = 0;
}

// ���������� ������ inputNumbers
void realNum::inputNumbers() {
	std::cout << "a = ";
	std::cin >> a;
	// ������ �������� ��� ���������� a
	std::cout << "b = ";
	std::cin >> b;
	// ������ �������� ��� ���������� b
}

// ���������� ������ printNumbers
void realNum::printNumbers() {
	std::cout << " ������ ������������ ����� a = " << a << " " << "b = " << b << std::endl;
	// ������� �������� ���������� a � b
}

// ���������� ������ procNum
void realNum::procNum() {
	float diff = (a - b) / 2.0;
	// ��������� ������������ ����� a � b
	std::cout << "������������ �����: " << diff;
}
