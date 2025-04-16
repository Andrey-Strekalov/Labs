#include <iostream>
#include <string>
#include <vector> 
#include <algorithm> // для sort

// функция переписывает из массива слова без буквы "р"
// принимает исходный массив и его длину
std::vector<std::string> filterNamesWithoutR(std::string arr[], int len) {
    std::vector<std::string> result; // вектор результат
    for (int i = 0; i < len; i++) {  // проходим по всем строкам 
        bool containsR = false; // есть ли "р" в текущем слове 
        for (char sym : arr[i]) {    // Посимвольно проходим по очередной строке
            if (sym == 'р' || sym == 'Р') {
                containsR = true; //  если есть, меняем флаг на true
                break;
            }
        }
        if (!containsR) {
            result.push_back(arr[i]); // пушим в вектор слово без "р"
        }
    }
    return result;
}

int main() {
    setlocale(LC_ALL, "ru");

    // массив имен
    std::string names[10] = {
        "Екатерина",
        "Елизавета",
        "София",
        "Серафима",
        "Ульяна",
        "Елена",
        "Валентина",
        "Анна",
        "Ольга",
        "Татьяна"
    };

    // Фильтруем имена
    std::vector<std::string> name_filtered = filterNamesWithoutR(names, 10);

    // Сортируем результат
    std::sort(name_filtered.begin(), name_filtered.end());

    // Выводим отсортированный список
    for (const auto& name : name_filtered) {  // Используем ссылку для эффективности
        std::cout << name << " ";
    }

    return 0;
}