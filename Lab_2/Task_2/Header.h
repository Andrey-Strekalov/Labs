#pragma once

#include <string>
#include <iostream>

class book
{
public:
    // ����������� ������ book, �������������� ���� ����� ������
    book() {
        setName();
        setPages();
        setPrice();

        std::cout << std::endl;
    };

    // ����� ��� ��������� �������� �����
    void setName() {
        std::cout << "������� �������� �����: ";
        std::getline(std::cin, name);
    };

    // ����� ��� ��������� ���������� �������
    void setPages() {
        std::cout << "������� ���������� ������� � �����: ";
        std::cin >> pages;
    };

    // ����� ��� ��������� ���� ����� � �������� ����, ���� �������� ���������� � "Programming"
    void setPrice() {
        std::cout << "������� ��������� �����: ";
        std::cin >> price;
        doublePrice();
    };

    // ����� ��� ���������� ������� ��������� ����� ��������
    void calcPriceOfpage() {
        std::cout << "������� ��������� ����� ��������: " << price / pages << "p.";
        std::cout << "\n";
    };

    // ����� ��� �������� ����, ���� �������� ����� ���������� � "Programming"
    float doublePrice() {
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
    void printInfo() {
        std::cout << "�������� �����: " << name << std::endl;
        std::cout << "���������� �������: " << pages << std::endl;
        std::cout << "���� �����: " << price << std::endl;
        std::cout << "\n";
    }

    // ���������� ������ book
    ~book() {
        std::cout << "\n" << "Succsess! * Memory has been cleaned" << "\n";
    };

private:
    std::string name;  // �������� �����
    float price;       // ���� �����
    int pages;         // ���������� �������
    int editValue;     // �������������� ����������
};
