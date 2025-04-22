#include <iostream>
#include <fstream>
#include <cstring> // Для работы с C-строками

using namespace std;

// Константы для размеров данных
const int MIN_GROUPS = 5;      // Минимальное количество групп в туре
const int NAME_LENGTH = 50;    // Максимальная длина названия тура (в символах)
// Название тура представляем в виде массива для корректной записи и работы с бинарным файлом 

// Структура для хранения информации о турпоездке
struct TourPackage {
    char tripName[NAME_LENGTH];  // Название тура (фиксированный массив символов)
    double ticketPrice;          // Стоимость одной путевки
    int groupMembers[MIN_GROUPS]; // Количество людей в каждой группе
    double groupTotal[MIN_GROUPS]; // Общая стоимость для каждой группы
};

// Функция создания бинарного файла с тестовыми данными
void createFile(const char* filename) {
    // Открываем файл в бинарном режиме для записи
    ofstream file(filename, ios::binary);
    if (!file.is_open()) {
        cerr << "Ошибка создания файла!" << endl;
        return;
    }

    // Создаем массив тестовых турпоездок
    TourPackage packages[] = {
        {"Европейский тур", 1000.0, {8, 10, 12, 15, 10}, {8000, 10000, 12000, 15000, 10000}},
        {"Азиатское приключение", 1500.0, {6, 8, 10, 12, 14}, {9000, 12000, 15000, 18000, 21000}},
        {"Африканское сафари", 2000.0, {10, 10, 8, 12, 15}, {20000, 20000, 16000, 24000, 30000}}
    };

    // Записываем весь массив структур в файл одной операцией
    file.write(reinterpret_cast<char*>(packages), sizeof(packages));
    cout << "Файл успешно создан\n";
}

// Функция обновления цен в файле (скидка 5% для групп >10 человек)
void updatePrices(const char* filename) {
    // Открываем файл для чтения и записи в бинарном режиме
    fstream file(filename, ios::in | ios::out | ios::binary);
    if (!file.is_open()) {
        cerr << "Ошибка открытия файла!" << endl;
        return;
    }

    TourPackage package;  // Буфер для хранения текущей турпоездки

    // Читаем файл по одной структуре за раз
    while (file.read(reinterpret_cast<char*>(&package), sizeof(TourPackage))) {
        bool modified = false; // Флаг изменения данных

        // Проверяем все группы в текущей турпоездке
        for (int i = 0; i < MIN_GROUPS; i++) {
            // Если в группе больше 10 человек, применяем скидку 5%
            if (package.groupMembers[i] > 10) {
                package.groupTotal[i] *= 0.95;  // Уменьшаем общую стоимость
                modified = true;
            }
        }

        // Если были изменения, перезаписываем данные
        if (modified) {
            // Возвращаемся к началу текущей записи
            file.seekp(-static_cast<int>(sizeof(TourPackage)), ios::cur);
            // Записываем обновленные данные
            file.write(reinterpret_cast<char*>(&package), sizeof(TourPackage));
            // Сбрасываем буфер для мгновенной записи на диск
            file.flush();
        }
    }
    cout << "Обновление цен завершено\n";
}

// Функция вывода содержимого файла на экран
void printFile(const char* filename) {
    // Открываем файл для чтения в бинарном режиме
    ifstream file(filename, ios::binary);
    if (!file.is_open()) {
        cerr << "Ошибка открытия файла!" << endl;
        return;
    }

    TourPackage package;  // Буфер для хранения текущей турпоездки

    cout << "\nСодержимое файла:\n";
    // Читаем и выводим данные по одной структуре за раз
    while (file.read(reinterpret_cast<char*>(&package), sizeof(TourPackage))) {
        // Выводим информацию о турпоездке
        cout << "Тур: " << package.tripName << endl
            << "Цена: " << package.ticketPrice << endl
            << "Составы групп: ";

        // Выводим количество людей в каждой группе
        for (int i = 0; i < MIN_GROUPS; i++) {
            cout << package.groupMembers[i] << " ";
        }

        // Выводим общую стоимость для каждой группы
        cout << "\nОбщая стоимость: ";
        for (int i = 0; i < MIN_GROUPS; i++) {
            cout << package.groupTotal[i] << " ";
        }
        cout << "\n\n";  // Разделитель между разными турами
    }
}

// Главная функция программы
int main() {
    setlocale(LC_ALL, "ru");  // Устанавливаем русскую локаль для вывода

    const char* filename = "tours.dat";  // Имя бинарного файла

    // Создаем файл с тестовыми данными
    createFile(filename);

    // Выводим исходное содержимое файла
    printFile(filename);

    // Обновляем цены (применяем скидки)
    updatePrices(filename);

    // Выводим обновленное содержимое файла
    printFile(filename);

    return 0;
}