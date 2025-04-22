// ��������� �������������� ������������ ��� ������� CRT � Visual Studio
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>   // ��� �����/������
#include <fstream>    // ��� ������ � �������
#include <vector>     // ��� ������������� �������
#include <string>     // ��� ������ �� ��������
#include <ctime>      // ��� ������ � ����� � ��������
#include <iomanip>    // ��� ���������������� ������

using namespace std;  // ���������� ����������� ������������ ����

// ��������� ��� �������� ������ � ����������
struct Employee {
    char surname[50];   // ������� ����������
    char position[50];  // ���������
    double salary;      // ��������

    // ��������� ��������� ��� ���� ��������
    struct {
        int day;        // ���� ��������
        int month;      // ����� ��������
        int year;      // ��� ��������
    } birth_date;
};

// ������� ��� �������� ��������� ����� � ������� � �����������
void createBinaryFile(const string& filename) {
    // ��������� ���� � �������� ������ ��� ������
    ofstream file(filename, ios::binary);
    if (!file) {  // ���� ���� �� ��������
        cerr << "Error creating file!" << endl;
        return;
    }

    // ������ � ��������� ������� �����������
    Employee employees[] = {
        {"������", "��������", 85000, {15, 5, 1990}},
        {"�������", "�����������", 120000, {22, 8, 1995}},
        {"�������", "��������", 95000, {10, 3, 1980}},
        {"���������", "��������", 75000, {3, 11, 1993}},
        {"�������", "�����������", 65000, {18, 7, 1985}}
    };

    // ���������� ���� ������ � ���� ��� �������� ������
    file.write(reinterpret_cast<char*>(employees), sizeof(employees));
    cout << "�������� ���� ������ �������!" << endl;
}

// ������� ��� ��������� ������ � �����������
void processEmployees(const string& filename) {
    // ��������� ���� � �������� ������ ��� ������
    ifstream file(filename, ios::binary);
    if (!file) {
        cerr << "Error opening file!" << endl;
        return;
    }

    vector<Employee> employees;  // ������ ��� �������� �����������
    Employee emp;                // ��������� ���������� ��� ������

    // ������ ������ �� ����� ���� ��� ��������
    while (file.read(reinterpret_cast<char*>(&emp), sizeof(Employee))) {
        employees.push_back(emp);  // ��������� ���������� � ������
    }

    // ��������� ������� ��������
    double totalSalary = 0;
    for (const auto& e : employees) {
        totalSalary += e.salary;
    }
    double averageSalary = totalSalary / employees.size();

    // �������� ������� ����
    time_t now = time(0);
    tm* ltm = localtime(&now);
    int currentYear = 1900 + ltm->tm_year;  // ��� � ������� YYYY

    // ������� ��������� �������
    cout << "\n���������� � ��������� ���� ������� (" << averageSalary << ") � ��������� < 30 ���:\n";
    cout << "------------------------------------------------------------------\n";
    cout << setw(15) << left << "�������" << setw(15) << "���������"
        << setw(10) << "��������" << "���� ��������\n";
    cout << "------------------------------------------------------------------\n";

    // ���������� ���� �����������
    for (const auto& e : employees) {
        // ��������� �������
        int age = currentYear - e.birth_date.year;

        // ������������ �������, ���� ���� �������� ��� �� ��������
        if (ltm->tm_mon + 1 < e.birth_date.month ||
            (ltm->tm_mon + 1 == e.birth_date.month && ltm->tm_mday < e.birth_date.day)) {
            age--;
        }

        // ��������� �������: �������� ���� ������� � ������� ������ 30
        if (e.salary > averageSalary && age < 30) {
            // ��������������� ����� ������ � ����������
            cout << setw(15) << left << e.surname << setw(15) << e.position
                << setw(10) << e.salary << e.birth_date.day << "."
                << e.birth_date.month << "." << e.birth_date.year << endl;
        }
    }
}

int main() {
    setlocale(LC_ALL, "ru");  // ������������� ������� ������
    const string filename = "employees.bin";  // ��� ����� ��� ������

    // ������� �������� ���� � �������
    createBinaryFile(filename);

    // ������������ ������ � ������� ����������
    processEmployees(filename);

    return 0;
}