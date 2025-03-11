#pragma once
// Директива для предотвращения повторного включения заголовочного файла

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
        // Вводим значение для переменной a
        std::cout << "b = ";
        std::cin >> b;
        // Вводим значение для переменной b
    }

    void inputNumbers() {
        std::cout << " Объект вещественных чисел a = " << a << " " << "b = " << b << std::endl;
        // Выводим значения переменных a и b
    }

    void procNum() {
        float diff = (a - b) / 2.0;
        // Вычисляем полуразность чисел a и b
        std::cout << "Полуразность чисел: " << diff;
    };

private:
    // Закрытая секция класса (на данный момент пустая)
};
