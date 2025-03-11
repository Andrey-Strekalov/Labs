#pragma once

#include <string>
#include <iostream>

class book
{
public:
    // Конструктор класса book, инициализирует поля через методы
    book() {
        setName();
        setPages();
        setPrice();

        std::cout << std::endl;
    };

    // Метод для установки названия книги
    void setName() {
        std::cout << "Введите название книги: ";
        std::getline(std::cin, name);
    };

    // Метод для установки количества страниц
    void setPages() {
        std::cout << "Введите количество страниц в книге: ";
        std::cin >> pages;
    };

    // Метод для установки цены книги и удвоения цены, если название начинается с "Programming"
    void setPrice() {
        std::cout << "Введите стоимость книги: ";
        std::cin >> price;
        doublePrice();
    };

    // Метод для вычисления средней стоимости одной страницы
    void calcPriceOfpage() {
        std::cout << "Средняя стоимость одной страницы: " << price / pages << "p.";
        std::cout << "\n";
    };

    // Метод для удвоения цены, если название книги начинается с "Programming"
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
            firstWorld == "программирование" ||
            firstWorld == "Программирование")
        {
            price *= 2;
        }
        return price;
    };

    // Метод для вывода информации о книге
    void printInfo() {
        std::cout << "Название книги: " << name << std::endl;
        std::cout << "Количество страниц: " << pages << std::endl;
        std::cout << "Цена книги: " << price << std::endl;
        std::cout << "\n";
    }

    // Деструктор класса book
    ~book() {
        std::cout << "\n" << "Succsess! * Memory has been cleaned" << "\n";
    };

private:
    std::string name;  // Название книги
    float price;       // Цена книги
    int pages;         // Количество страниц
    int editValue;     // Неиспользуемая переменная
};
