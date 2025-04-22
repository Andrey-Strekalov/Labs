
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// �������� ������������� ���������
const int m = 3;   // ����� � �������
const int n = 3;   // �������� � �������
const int k = 5;   // ������ � ������ �����
const int l = 3;   // ������ �� ������ �����

// ������� ��� ������ ������ �� �����
vector<vector<vector<int>>> read_matrices(const string& filename, int count) {
    ifstream file(filename); // ��������� ���� ��� ������
    vector<vector<vector<int>>> matrices; // ������� ������ ��������� �������� (������)

    // ���������� ��� ������� 
    for (int mat = 0; mat < count; mat++) {
        vector<vector<int>> matrix(m, vector<int>(n)); // ������� ������� matrix � ��������� ����� �� n ��������� �� m �������� 

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!(file >> matrix[i][j])) { // ���� ���� �� ������ ��������� ���������
                    cerr << "������ ������ ����� " << filename
                        << " ��� �������� ������ ������" << endl;
                    exit(1);
                }
            }
        }
        matrices.push_back(matrix); // ��� �������� ������ ����� ������� � ������ ������
    }
    return matrices; // ���������� ������ ������
}

// ������� ��� ������ ������ � ����
void write_matrices(const string& filename, const vector<vector<vector<int>>>& matrices) {
    ofstream file(filename); // ��������� ���� ��� ������ 

    for (const auto& matrix : matrices) { // ���������� ����������� ������ ��� ������� � ������������ � ����
        for (const auto& row : matrix) {
            for (int num : row) {
                file << num << " ";
            }
            file << "\n";
        }
        file << "\n";
    }
}

// ������� ��� ������ ����������� �����
void print_file(const string& filename) {
    ifstream file(filename); // ��������� ���� ��� ������ � ������
    cout << "\n���������� ����� '" << filename << "':\n";
    copy(istreambuf_iterator<char>(file), // �������� ��� ������ ����� �����������
        istreambuf_iterator<char>(), // �������� ����� �����
        ostreambuf_iterator<char>(cout)); // �������� ������ ������� � ������� 
    cout << "\n";
}

int main() {
    setlocale(LC_ALL, "ru");
    // ������ �������� ������
    auto file1 = read_matrices("C:/Users/andre/source/repos/CODESRUN/text/a.txt", k);
    auto file2 = read_matrices("C:/Users/andre/source/repos/CODESRUN/text/b.txt", l);

    // ���������� ������ �� ������� �����
    vector<vector<vector<int>>> new_file1; // ������� ������� ��� ������ ����������� ������
    vector<vector<vector<int>>> to_move; //  ��� �������� ������ (������ � ������ ��������� ��.����. ������ ����)

    for (const auto& matrix : file1) {
        int diag_sum = 0; // ����� ��������� ������� ���������
        int min_dim = min(m, n); // ��� ���������� ������������� ����������� ������ �������� ������� ��������� 

        // ����� ������� ���������
        for (int i = 0; i < min_dim; i++) {
            diag_sum += matrix[i][i];
        }

        // ��������� ������� � ������ 5
        (diag_sum == 5) ? to_move.push_back(matrix)
            : new_file1.push_back(matrix);
    }

    // ���������� ������
    file2.insert(file2.end(), to_move.begin(), to_move.end());

    write_matrices("C:/Users/andre/source/repos/CODESRUN/text/a.txt", new_file1);
    write_matrices("C:/Users/andre/source/repos/CODESRUN/text/b.txt", file2);

    // ����� �����������
    print_file("C:/Users/andre/source/repos/CODESRUN/text/a.txt");
    print_file("C:/Users/andre/source/repos/CODESRUN/text/b.txt");

    return 0;
}
