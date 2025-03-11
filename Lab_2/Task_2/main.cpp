#include <iostream>
#include <Windows.h> // ����������� ���������� ��� ������������� ������� SetConsoleCP � SetConsoleOutputCP
#include "Header.h" // ����������� ������������� ����� � ����������� ������ book

int main() {
    setlocale(LC_ALL, "ru");

    // ��������� ��������� ������� ��� ��������� �������������� ����� � ������
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    book* myBook = new book; // �������� ������� ������ book � ������� ������������� ��������� ������

    myBook->calcPriceOfpage(); // ���������� ������� ��������� ����� ��������
    myBook->printInfo();       // ����� ���������� � �����

    delete myBook; // ������������ ������
    return 0;
}
