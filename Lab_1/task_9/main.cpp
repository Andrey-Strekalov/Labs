#include <iostream>
#include <fstream>
#include <iomanip> // для setw()

using namespace std;

const int SIZE = 5; // константа для размера массива 

// Функция для вывода массива
void printArray(int arr[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) { // перебираем массив поэлементно 
        for (int j = 0; j < SIZE; j++) {
            cout << setw(4) << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// Запись массива по столбцам в бинарный файл
void writeColumnsToFile(const char* filename, int arr[SIZE][SIZE]) { // передаем указатель на имя файла и квадратную матрицу размером SIZE
    ofstream file(filename, ios::binary); // открываем файл для записи
    for (int j = 0; j < SIZE; j++) {
        for (int i = 0; i < SIZE; i++) {
            file.write(reinterpret_cast<char*>(&arr[i][j]), sizeof(int)); // записываем побитно в бинарный файл
        }
    }
    file.close(); // закрываем файл
}

// функция удвоения значений элементов
void doubleValuesInFile(const char* filename) {
    fstream file(filename, ios::in | ios::out | ios::binary); // открываем файл для чтения и записи в бинарном режиме
    int value;
    while (file.read(reinterpret_cast<char*>(&value), sizeof(int))) {  // если 
        value *= 2; // удваиваем значение очередного элемента 
        file.seekp(-static_cast<int>(sizeof(int)), ios::cur); // считав значение перемещаемся на начало этого значения
        file.write(reinterpret_cast<char*>(&value), sizeof(int)); // перезаписываем значение на удвоенное 
        file.flush(); // для моментальной записи в файл
    }
    file.close();
}

// Чтение массива из файла
void readArrayFromFile(const char* filename, int arr[SIZE][SIZE]) {
    ifstream file(filename, ios::binary); // открываем файл для чтения
    for (int j = 0; j < SIZE; j++) {
        for (int i = 0; i < SIZE; i++) {
            file.read(reinterpret_cast<char*>(&arr[i][j]), sizeof(int)); // считываем матрицу напрямую в выделенную для него память
        }
    }
    file.close();
}

int main() {
    setlocale(LC_ALL, "ru");

    int originalArray[SIZE][SIZE]; // начальный массив 
    int modifiedArray[SIZE][SIZE]; // выходной массив (с удвоенными элементами)
    const char* filename = "array.bin"; // имя файла для записи

    // Ввод данных (заполнение матрицы с клавиатуры)
    cout << "Введите элементы массива 5x5:" << endl;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cin >> originalArray[i][j];
        }
    }

    // Вывод исходного массива
    cout << "\nИсходный массив:" << endl;
    printArray(originalArray);

    // Запись в файл
    writeColumnsToFile(filename, originalArray);

    // Модификация файла
    doubleValuesInFile(filename);

    // Чтение модифицированных данных
    readArrayFromFile(filename, modifiedArray);

    // Вывод измененного массива
    cout << "\nМодифицированный массив:" << endl;
    printArray(modifiedArray);

    return 0;
}
