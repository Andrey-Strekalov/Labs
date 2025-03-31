#include <iostream>
#include <Windows.h> // ����������� ���������� ��� ������������� ������� SetConsoleCP � SetConsoleOutputCP
#include "Header.h" // ����������� ������������� ����� � ����������� ������ book

int main() {
	setlocale(LC_ALL, "ru");

	// ��������� ��������� ������� ��� ��������� �������������� ����� � ������
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// �������� ������� ������ book � ������� ������������� ��������� ������ (������������ ����������� �� ���������)
	book* myBook_1 = new book;

	myBook_1->calcPriceOfpage(); // ���������� ������� ��������� ����� ��������
	myBook_1->printInfo();       // ����� ���������� � �����

	// �������� ������� ������ book � ������� ������������� ��������� ������ (������������ ����������� � �����������)
	book* myBook_2 = new book("�����������", 300, 900);

	myBook_2->calcPriceOfpage(); // ���������� ������� ��������� ����� ��������
	myBook_2->printInfo();		 // ����� ���������� � �����

	delete myBook_1; // ������������ ������
	delete myBook_2; // ������������ ������
	return 0;
}
