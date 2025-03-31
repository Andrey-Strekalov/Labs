#include "Header.h"
#include <string>
#include <iostream>


// ����������� �� ��������� ������ book, �������������� ���� ����� ������
book::book() {
    setName();
    setPages();
    setPrice();


    std::cout << std::endl;
};

// ����������� � ����������� ������ book
book::book(std::string b_name, float b_price, int b_pages) {
    name = b_name;  // �������� �����
    price = b_price;  // ���� �����
    pages = b_pages;
};

// ����� ��� ��������� �������� �����
void book::setName() {
    std::cout << "������� �������� �����: ";
    std::getline(std::cin, name);
};

// ����� ��� ��������� ���������� �������
void book::setPages() {
    std::cout << "������� ���������� ������� � �����: ";
    std::cin >> pages;
};

// ����� ��� ��������� ���� ����� � �������� ����, ���� �������� ���������� � "Programming"
void book::setPrice() {
    std::cout << "������� ��������� �����: ";
    std::cin >> price;
    doublePrice();
};

// ����� ��� ���������� ������� ��������� ����� ��������
void book::calcPriceOfpage() {
    std::cout << "������� ��������� ����� ��������: " << price / pages << "p.";
    std::cout << "\n";
};

// ����� ��� �������� ����, ���� �������� ����� ���������� � "Programming"
float book::doublePrice() {
    if (name.size() == 0)
    {
        return 0;
    }
    std::string firstWorld = "";
    for (char ch : name) {
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '.' || ch == ',' || ch == '-')
        {
            break;
        }
        else {
            firstWorld += ch;
        }
    }
    if (firstWorld == "Programming" ||
        firstWorld == "programming" ||
        firstWorld == "����������������" ||
        firstWorld == "����������������")
    {
        price *= 2;
    }
    return price;
};

// ����� ��� ������ ���������� � �����
void book::printInfo() {
    std::cout << "�������� �����: " << name << std::endl;
    std::cout << "���������� �������: " << pages << std::endl;
    std::cout << "���� �����: " << price << std::endl;
    std::cout << "\n";
}

// ���������� ������ book
book::~book() {
    std::cout << "\n" << "Succsess! * Memory has been cleaned" << "\n";
};
