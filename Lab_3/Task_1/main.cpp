#include <iostream>
#include <Windows.h> // Подключение библиотеки для работы с кодировкой консоли в Windows
#include <string>    // Подключение библиотеки для работы со строками

// Функция для ввода текста с консоли
std::string inputText() {
    std::string text;  // Создаем переменную для хранения текста
    std::cout << "Введите текст: ";
    std::getline(std::cin, text);  // Считываем всю строку ввода (включая пробелы)
    return text;  // Возвращаем введенный текст
}

// Функция для поиска подстроки в тексте
std::size_t search(std::string text, std::string substr) {
    return text.find(substr);  // Используем метод find для поиска подстроки
    // Возвращает позицию подстроки или string::npos, если подстрока не найдена
}

// Функция для обработки текста (замена всех вхождений подстроки)
std::string procText(std::string text, std::string substr, std::string subSubstr) {
    bool temp = true;  // Флаг для продолжения цикла
    int len = substr.length();  // Длина подстроки, которую нужно заменить

    while (temp) {  // Цикл выполняется, пока находятся вхождения подстроки
        std::size_t position = search(text, substr);  // Ищем подстроку в тексте

        if (position != std::string::npos) {  // Если подстрока найдена
            // Заменяем подстроку на новую подстроку
            text.replace(position, len, subSubstr);
        }
        else {
            temp = false;  // Если подстрока не найдена, выходим из цикла
        }
    }

    return text;  // Возвращаем обработанный текст
}

int main() {
    // Устанавливаем локаль для корректной работы с русским языком
    setlocale(LC_ALL, "ru");

    // Меняем кодировку консоли на Windows-1251 для правильного отображения русского текста
    SetConsoleCP(1251);         // Устанавливаем кодировку ввода
    SetConsoleOutputCP(1251);   // Устанавливаем кодировку вывода

    // Получаем текст от пользователя
    std::string p = inputText();

    // Обрабатываем текст:
    // 1. Заменяем все вхождения "четыре" на "хорошо"
    // 2. Заменяем все скобки на пробелы
    p = procText(p, "четыре", "хорошо");
    p = procText(p, ")", " ");
    p = procText(p, "(", " ");

    // Выводим результат обработки
    std::cout << "Отформатированый текст: " << p;

    return 0;  
}