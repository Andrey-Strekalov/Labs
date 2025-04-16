#include <iostream>
#include <string>
#include <vector> 
#include <algorithm> // ��� sort

// ������� ������������ �� ������� ����� ��� ����� "�"
// ��������� �������� ������ � ��� �����
std::vector<std::string> filterNamesWithoutR(std::string arr[], int len) {
    std::vector<std::string> result; // ������ ���������
    for (int i = 0; i < len; i++) {  // �������� �� ���� ������� 
        bool containsR = false; // ���� �� "�" � ������� ����� 
        for (char sym : arr[i]) {    // ����������� �������� �� ��������� ������
            if (sym == '�' || sym == '�') {
                containsR = true; //  ���� ����, ������ ���� �� true
                break;
            }
        }
        if (!containsR) {
            result.push_back(arr[i]); // ����� � ������ ����� ��� "�"
        }
    }
    return result;
}

int main() {
    setlocale(LC_ALL, "ru");

    // ������ ����
    std::string names[10] = {
        "���������",
        "���������",
        "�����",
        "��������",
        "������",
        "�����",
        "���������",
        "����",
        "�����",
        "�������"
    };

    // ��������� �����
    std::vector<std::string> name_filtered = filterNamesWithoutR(names, 10);

    // ��������� ���������
    std::sort(name_filtered.begin(), name_filtered.end());

    // ������� ��������������� ������
    for (const auto& name : name_filtered) {  // ���������� ������ ��� �������������
        std::cout << name << " ";
    }

    return 0;
}