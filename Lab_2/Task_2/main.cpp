#include <iostream>
#include <Windows.h> // Подключение библиотеки для использования функций SetConsoleCP и SetConsoleOutputCP
#include "Header.h" // Подключение заголовочного файла с объявлением класса book

int main() {
    setlocale(LC_ALL, "ru");

    // Изменение кодировки консоли для поддержки русскоязычного ввода и вывода
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    book* myBook = new book; // Создание объекта класса book с помощью динамического выделения памяти

    myBook->calcPriceOfpage(); // Вычисление средней стоимости одной страницы
    myBook->printInfo();       // Вывод информации о книге

    delete myBook; // Освобождение памяти
    return 0;
}
