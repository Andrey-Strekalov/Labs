#include <iostream>
#include <Windows.h> // ����������� ���������� ��� ������ � ���������� ������� � Windows
#include <string>    // ����������� ���������� ��� ������ �� ��������

// ������� ��� ����� ������ � �������
std::string inputText() {
    std::string text;  // ������� ���������� ��� �������� ������
    std::cout << "������� �����: ";
    std::getline(std::cin, text);  // ��������� ��� ������ ����� (������� �������)
    return text;  // ���������� ��������� �����
}

// ������� ��� ������ ��������� � ������
std::size_t search(std::string text, std::string substr) {
    return text.find(substr);  // ���������� ����� find ��� ������ ���������
    // ���������� ������� ��������� ��� string::npos, ���� ��������� �� �������
}

// ������� ��� ��������� ������ (������ ���� ��������� ���������)
std::string procText(std::string text, std::string substr, std::string subSubstr) {
    bool temp = true;  // ���� ��� ����������� �����
    int len = substr.length();  // ����� ���������, ������� ����� ��������

    while (temp) {  // ���� �����������, ���� ��������� ��������� ���������
        std::size_t position = search(text, substr);  // ���� ��������� � ������

        if (position != std::string::npos) {  // ���� ��������� �������
            // �������� ��������� �� ����� ���������
            text.replace(position, len, subSubstr);
        }
        else {
            temp = false;  // ���� ��������� �� �������, ������� �� �����
        }
    }

    return text;  // ���������� ������������ �����
}

int main() {
    // ������������� ������ ��� ���������� ������ � ������� ������
    setlocale(LC_ALL, "ru");

    // ������ ��������� ������� �� Windows-1251 ��� ����������� ����������� �������� ������
    SetConsoleCP(1251);         // ������������� ��������� �����
    SetConsoleOutputCP(1251);   // ������������� ��������� ������

    // �������� ����� �� ������������
    std::string p = inputText();

    // ������������ �����:
    // 1. �������� ��� ��������� "������" �� "������"
    // 2. �������� ��� ������ �� �������
    p = procText(p, "������", "������");
    p = procText(p, ")", " ");
    p = procText(p, "(", " ");

    // ������� ��������� ���������
    std::cout << "���������������� �����: " << p;

    return 0;  
}