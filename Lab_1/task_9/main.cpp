#include <iostream>
#include <fstream>
#include <iomanip> // ��� setw()

using namespace std;

const int SIZE = 5; // ��������� ��� ������� ������� 

// ������� ��� ������ �������
void printArray(int arr[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) { // ���������� ������ ����������� 
        for (int j = 0; j < SIZE; j++) {
            cout << setw(4) << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// ������ ������� �� �������� � �������� ����
void writeColumnsToFile(const char* filename, int arr[SIZE][SIZE]) { // �������� ��������� �� ��� ����� � ���������� ������� �������� SIZE
    ofstream file(filename, ios::binary); // ��������� ���� ��� ������
    for (int j = 0; j < SIZE; j++) {
        for (int i = 0; i < SIZE; i++) {
            file.write(reinterpret_cast<char*>(&arr[i][j]), sizeof(int)); // ���������� ������� � �������� ����
        }
    }
    file.close(); // ��������� ����
}

// ������� �������� �������� ���������
void doubleValuesInFile(const char* filename) {
    fstream file(filename, ios::in | ios::out | ios::binary); // ��������� ���� ��� ������ � ������ � �������� ������
    int value;
    while (file.read(reinterpret_cast<char*>(&value), sizeof(int))) {  // ���� 
        value *= 2; // ��������� �������� ���������� �������� 
        file.seekp(-static_cast<int>(sizeof(int)), ios::cur); // ������ �������� ������������ �� ������ ����� ��������
        file.write(reinterpret_cast<char*>(&value), sizeof(int)); // �������������� �������� �� ��������� 
        file.flush(); // ��� ������������ ������ � ����
    }
    file.close();
}

// ������ ������� �� �����
void readArrayFromFile(const char* filename, int arr[SIZE][SIZE]) {
    ifstream file(filename, ios::binary); // ��������� ���� ��� ������
    for (int j = 0; j < SIZE; j++) {
        for (int i = 0; i < SIZE; i++) {
            file.read(reinterpret_cast<char*>(&arr[i][j]), sizeof(int)); // ��������� ������� �������� � ���������� ��� ���� ������
        }
    }
    file.close();
}

int main() {
    setlocale(LC_ALL, "ru");

    int originalArray[SIZE][SIZE]; // ��������� ������ 
    int modifiedArray[SIZE][SIZE]; // �������� ������ (� ���������� ����������)
    const char* filename = "array.bin"; // ��� ����� ��� ������

    // ���� ������ (���������� ������� � ����������)
    cout << "������� �������� ������� 5x5:" << endl;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cin >> originalArray[i][j];
        }
    }

    // ����� ��������� �������
    cout << "\n�������� ������:" << endl;
    printArray(originalArray);

    // ������ � ����
    writeColumnsToFile(filename, originalArray);

    // ����������� �����
    doubleValuesInFile(filename);

    // ������ ���������������� ������
    readArrayFromFile(filename, modifiedArray);

    // ����� ����������� �������
    cout << "\n���������������� ������:" << endl;
    printArray(modifiedArray);

    return 0;
}
