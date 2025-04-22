
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Заданные разработчиком константы
const int m = 3;   // строк в матрице
const int n = 3;   // столбцов в матрице
const int k = 5;   // матриц в первом файле
const int l = 3;   // матриц во втором файле

// Функция для чтения матриц из файла
vector<vector<vector<int>>> read_matrices(const string& filename, int count) {
    ifstream file(filename); // открываем файл для чтения
    vector<vector<vector<int>>> matrices; // создаем вектор двумерных векторов (матриц)

    // перебираем все матрицы 
    for (int mat = 0; mat < count; mat++) {
        vector<vector<int>> matrix(m, vector<int>(n)); // создаем матрицу matrix с шаблонным рядом из n элементов по m стлобцов 

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!(file >> matrix[i][j])) { // если файл не считан завершаем программу
                    cerr << "Ошибка чтения файла " << filename
                        << " или неверный формат данных" << endl;
                    exit(1);
                }
            }
        }
        matrices.push_back(matrix); // при успешном чтении пушим матрицу в вектор матриц
    }
    return matrices; // возвращаем вектор матриц
}

// Функция для записи матриц в файл
void write_matrices(const string& filename, const vector<vector<vector<int>>>& matrices) {
    ofstream file(filename); // открываем файл для чтения 

    for (const auto& matrix : matrices) { // перебираем посимвольно каждый ряд матрицы и переписываем в файл
        for (const auto& row : matrix) {
            for (int num : row) {
                file << num << " ";
            }
            file << "\n";
        }
        file << "\n";
    }
}

// Функция для вывода содержимого файла
void print_file(const string& filename) {
    ifstream file(filename); // открываем файл для чтения и записи
    cout << "\nСодержимое файла '" << filename << "':\n";
    copy(istreambuf_iterator<char>(file), // итератор для чтения файла посимвольно
        istreambuf_iterator<char>(), // итератор конца файла
        ostreambuf_iterator<char>(cout)); // итератор вывода символа в консоль 
    cout << "\n";
}

int main() {
    setlocale(LC_ALL, "ru");
    // Чтение исходных данных
    auto file1 = read_matrices("C:/Users/andre/source/repos/CODESRUN/text/a.txt", k);
    auto file2 = read_matrices("C:/Users/andre/source/repos/CODESRUN/text/b.txt", l);

    // Фильтрация матриц из первого файла
    vector<vector<vector<int>>> new_file1; // создаем матрицу для записи изначальных данных
    vector<vector<vector<int>>> to_move; //  для конечных данных (матриц с суммой элементов гл.диаг. равной пяти)

    for (const auto& matrix : file1) {
        int diag_sum = 0; // сумма элементов главной диагонали
        int min_dim = min(m, n); // для вычисления максимального порядкового номера элемента главной диагонали 

        // Сумма главной диагонали
        for (int i = 0; i < min_dim; i++) {
            diag_sum += matrix[i][i];
        }

        // Переносим матрицы с суммой 5
        (diag_sum == 5) ? to_move.push_back(matrix)
            : new_file1.push_back(matrix);
    }

    // Обновление файлов
    file2.insert(file2.end(), to_move.begin(), to_move.end());

    write_matrices("C:/Users/andre/source/repos/CODESRUN/text/a.txt", new_file1);
    write_matrices("C:/Users/andre/source/repos/CODESRUN/text/b.txt", file2);

    // Вывод результатов
    print_file("C:/Users/andre/source/repos/CODESRUN/text/a.txt");
    print_file("C:/Users/andre/source/repos/CODESRUN/text/b.txt");

    return 0;
}
