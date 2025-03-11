#pragma once

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
        std::cout << "b = ";
        std::cin >> b;
    }

    void inputNumbers() {
        std::cout << " Объект вещественных чисел a = " << a << " " << "b = " << b << std::endl;
    }

    void procNum() {
        float diff = (a - b) / 2.0;
        std::cout << "Полуразность чисел: " << diff;
    };


private:

};
