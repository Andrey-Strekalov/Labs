#include <iostream>
#include <fstream>
#include <cstring> // ��� ������ � C-��������

using namespace std;

// ��������� ��� �������� ������
const int MIN_GROUPS = 5;      // ����������� ���������� ����� � ����
const int NAME_LENGTH = 50;    // ������������ ����� �������� ���� (� ��������)
// �������� ���� ������������ � ���� ������� ��� ���������� ������ � ������ � �������� ������ 

// ��������� ��� �������� ���������� � ����������
struct TourPackage {
    char tripName[NAME_LENGTH];  // �������� ���� (������������� ������ ��������)
    double ticketPrice;          // ��������� ����� �������
    int groupMembers[MIN_GROUPS]; // ���������� ����� � ������ ������
    double groupTotal[MIN_GROUPS]; // ����� ��������� ��� ������ ������
};

// ������� �������� ��������� ����� � ��������� �������
void createFile(const char* filename) {
    // ��������� ���� � �������� ������ ��� ������
    ofstream file(filename, ios::binary);
    if (!file.is_open()) {
        cerr << "������ �������� �����!" << endl;
        return;
    }

    // ������� ������ �������� ����������
    TourPackage packages[] = {
        {"����������� ���", 1000.0, {8, 10, 12, 15, 10}, {8000, 10000, 12000, 15000, 10000}},
        {"��������� �����������", 1500.0, {6, 8, 10, 12, 14}, {9000, 12000, 15000, 18000, 21000}},
        {"����������� ������", 2000.0, {10, 10, 8, 12, 15}, {20000, 20000, 16000, 24000, 30000}}
    };

    // ���������� ���� ������ �������� � ���� ����� ���������
    file.write(reinterpret_cast<char*>(packages), sizeof(packages));
    cout << "���� ������� ������\n";
}

// ������� ���������� ��� � ����� (������ 5% ��� ����� >10 �������)
void updatePrices(const char* filename) {
    // ��������� ���� ��� ������ � ������ � �������� ������
    fstream file(filename, ios::in | ios::out | ios::binary);
    if (!file.is_open()) {
        cerr << "������ �������� �����!" << endl;
        return;
    }

    TourPackage package;  // ����� ��� �������� ������� ����������

    // ������ ���� �� ����� ��������� �� ���
    while (file.read(reinterpret_cast<char*>(&package), sizeof(TourPackage))) {
        bool modified = false; // ���� ��������� ������

        // ��������� ��� ������ � ������� ����������
        for (int i = 0; i < MIN_GROUPS; i++) {
            // ���� � ������ ������ 10 �������, ��������� ������ 5%
            if (package.groupMembers[i] > 10) {
                package.groupTotal[i] *= 0.95;  // ��������� ����� ���������
                modified = true;
            }
        }

        // ���� ���� ���������, �������������� ������
        if (modified) {
            // ������������ � ������ ������� ������
            file.seekp(-static_cast<int>(sizeof(TourPackage)), ios::cur);
            // ���������� ����������� ������
            file.write(reinterpret_cast<char*>(&package), sizeof(TourPackage));
            // ���������� ����� ��� ���������� ������ �� ����
            file.flush();
        }
    }
    cout << "���������� ��� ���������\n";
}

// ������� ������ ����������� ����� �� �����
void printFile(const char* filename) {
    // ��������� ���� ��� ������ � �������� ������
    ifstream file(filename, ios::binary);
    if (!file.is_open()) {
        cerr << "������ �������� �����!" << endl;
        return;
    }

    TourPackage package;  // ����� ��� �������� ������� ����������

    cout << "\n���������� �����:\n";
    // ������ � ������� ������ �� ����� ��������� �� ���
    while (file.read(reinterpret_cast<char*>(&package), sizeof(TourPackage))) {
        // ������� ���������� � ����������
        cout << "���: " << package.tripName << endl
            << "����: " << package.ticketPrice << endl
            << "������� �����: ";

        // ������� ���������� ����� � ������ ������
        for (int i = 0; i < MIN_GROUPS; i++) {
            cout << package.groupMembers[i] << " ";
        }

        // ������� ����� ��������� ��� ������ ������
        cout << "\n����� ���������: ";
        for (int i = 0; i < MIN_GROUPS; i++) {
            cout << package.groupTotal[i] << " ";
        }
        cout << "\n\n";  // ����������� ����� ������� ������
    }
}

// ������� ������� ���������
int main() {
    setlocale(LC_ALL, "ru");  // ������������� ������� ������ ��� ������

    const char* filename = "tours.dat";  // ��� ��������� �����

    // ������� ���� � ��������� �������
    createFile(filename);

    // ������� �������� ���������� �����
    printFile(filename);

    // ��������� ���� (��������� ������)
    updatePrices(filename);

    // ������� ����������� ���������� �����
    printFile(filename);

    return 0;
}