// Отключаем предупреждения безопасности для функций CRT в Visual Studio
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>   // Для ввода/вывода
#include <fstream>    // Для работы с файлами
#include <vector>     // Для использования вектора
#include <string>     // Для работы со строками
#include <ctime>      // Для работы с датой и временем
#include <iomanip>    // Для форматированного вывода

using namespace std;  // Используем стандартное пространство имен

// Структура для хранения данных о сотруднике
struct Employee {
    char surname[50];   // Фамилия сотрудника
    char position[50];  // Должность
    double salary;      // Зарплата

    // Вложенная структура для даты рождения
    struct {
        int day;        // День рождения
        int month;      // Месяц рождения
        int year;      // Год рождения
    } birth_date;
};

// Функция для создания бинарного файла с данными о сотрудниках
void createBinaryFile(const string& filename) {
    // Открываем файл в бинарном режиме для записи
    ofstream file(filename, ios::binary);
    if (!file) {  // Если файл не открылся
        cerr << "Error creating file!" << endl;
        return;
    }

    // Массив с тестовыми данными сотрудников
    Employee employees[] = {
        {"Иванов", "Менеджер", 85000, {15, 5, 1990}},
        {"Петрова", "Разработчик", 120000, {22, 8, 1995}},
        {"Сидоров", "Аналитик", 95000, {10, 3, 1980}},
        {"Кузнецова", "Дизайнер", 75000, {3, 11, 1993}},
        {"Смирнов", "Тестировщик", 65000, {18, 7, 1985}}
    };

    // Записываем весь массив в файл как бинарные данные
    file.write(reinterpret_cast<char*>(employees), sizeof(employees));
    cout << "Бинарный файл создан успешно!" << endl;
}

// Функция для обработки данных о сотрудниках
void processEmployees(const string& filename) {
    // Открываем файл в бинарном режиме для чтения
    ifstream file(filename, ios::binary);
    if (!file) {
        cerr << "Error opening file!" << endl;
        return;
    }

    vector<Employee> employees;  // Вектор для хранения сотрудников
    Employee emp;                // Временная переменная для чтения

    // Читаем данные из файла пока это возможно
    while (file.read(reinterpret_cast<char*>(&emp), sizeof(Employee))) {
        employees.push_back(emp);  // Добавляем сотрудника в вектор
    }

    // Вычисляем среднюю зарплату
    double totalSalary = 0;
    for (const auto& e : employees) {
        totalSalary += e.salary;
    }
    double averageSalary = totalSalary / employees.size();

    // Получаем текущую дату
    time_t now = time(0);
    tm* ltm = localtime(&now);
    int currentYear = 1900 + ltm->tm_year;  // Год в формате YYYY

    // Выводим заголовок таблицы
    cout << "\nСотрудники с зарплатой выше средней (" << averageSalary << ") и возрастом < 30 лет:\n";
    cout << "------------------------------------------------------------------\n";
    cout << setw(15) << left << "Фамилия" << setw(15) << "Должность"
        << setw(10) << "Зарплата" << "Дата рождения\n";
    cout << "------------------------------------------------------------------\n";

    // Перебираем всех сотрудников
    for (const auto& e : employees) {
        // Вычисляем возраст
        int age = currentYear - e.birth_date.year;

        // Корректируем возраст, если день рождения еще не наступил
        if (ltm->tm_mon + 1 < e.birth_date.month ||
            (ltm->tm_mon + 1 == e.birth_date.month && ltm->tm_mday < e.birth_date.day)) {
            age--;
        }

        // Проверяем условия: зарплата выше средней и возраст меньше 30
        if (e.salary > averageSalary && age < 30) {
            // Форматированный вывод данных о сотруднике
            cout << setw(15) << left << e.surname << setw(15) << e.position
                << setw(10) << e.salary << e.birth_date.day << "."
                << e.birth_date.month << "." << e.birth_date.year << endl;
        }
    }
}

int main() {
    setlocale(LC_ALL, "ru");  // Устанавливаем русскую локаль
    const string filename = "employees.bin";  // Имя файла для работы

    // Создаем бинарный файл с данными
    createBinaryFile(filename);

    // Обрабатываем данные и выводим результаты
    processEmployees(filename);

    return 0;
}