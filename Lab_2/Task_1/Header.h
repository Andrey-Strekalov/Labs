#pragma once
// ��������� ��� �������������� ���������� ��������� ������������� �����

#include <iostream>

class realNum
{
public:
    int a;
    int b;

    realNum() {
        a = 0;
        b = 0;
        std::cout << "a = ";
        std::cin >> a;
        // ������ �������� ��� ���������� a
        std::cout << "b = ";
        std::cin >> b;
        // ������ �������� ��� ���������� b
    }

    void inputNumbers() {
        std::cout << " ������ ������������ ����� a = " << a << " " << "b = " << b << std::endl;
        // ������� �������� ���������� a � b
    }

    void procNum() {
        float diff = (a - b) / 2.0;
        // ��������� ������������ ����� a � b
        std::cout << "������������ �����: " << diff;
    };

private:
    // �������� ������ ������ (�� ������ ������ ������)
};
