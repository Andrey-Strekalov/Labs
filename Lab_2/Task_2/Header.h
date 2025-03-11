#pragma once

#include <string>
#include <iostream>

class book
{
public:

    book() {
        setName();
        setPages();
        setPrice();

        std::cout << std::endl;
    };

    void setName() {
        std::cout << "Введите название книги: ";
        std::getline(std::cin, name);
    };

    void setPages() {
        std::cout << "Введите количество страниц в книге: ";
        std::cin >> pages;
    };

    void setPrice() {
        std::cout << "Введите стоимость книги: ";
        std::cin >> price;
        doublePrice();
    };

    void calcPriceOfpage() {
        std::cout << "Средняя стоимость одной страницы: " << price / pages << "p.";
        std::cout << "\n";
    };

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

    void printInfo() {
        std::cout << "Название книги: " << name << std::endl;
        std::cout << "Количество страниц: " << pages << std::endl;
        std::cout << "Цена книги: " << price << std::endl;
        std::cout << "\n";
    }



    ~book() {
        std::cout << "\n" << "Succsess! * Memory has been cleaned" << "\n";
    };

private:
    std::string name;
    float price;
    int pages;
    int editValue;
};
