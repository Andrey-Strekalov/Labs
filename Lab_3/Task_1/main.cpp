#include <iostream>
#include <Windows.h> // ����������� ���������� ��� ������ � ���������� ������� � Windows
#include <string>    // ����������� ���������� ��� ������ �� ��������
#include <vector>    // ��� ���������� ������ �� �����
#include <sstream>   // ��� ������ � stringstream
#include <algorithm> // ��� ������� isspace

// ������� ��� ����� ������ � �������
std::string inputText() {
	std::string text;  // ������� ���������� ��� �������� ������
	std::cout << "������� �����: ";
	std::getline(std::cin, text);  // ��������� ��� ������ ����� (������� �������)
	return text;  // ���������� ��������� �����
}

// ������� ��� ������ ��������� � ������
std::size_t search(std::string text, std::string substr) {
	return text.find(substr);  // ���������� ����� find ��� ������ ���������
	// ���������� ������� ��������� ��� string::npos, ���� ��������� �� �������
}

// ������� ��� ��������� ������ (������ ���� ��������� ���������)
std::string procText(std::string text, std::string substr, std::string subSubstr) {
	bool temp = true;  // ���� ��� ����������� �����
	int len = substr.length();  // ����� ���������, ������� ����� ��������

	while (temp) {  // ���� �����������, ���� ��������� ��������� ���������
		std::size_t position = search(text, substr);  // ���� ��������� � ������

		if (position != std::string::npos) {  // ���� ��������� �������
			// �������� ��������� �� ����� ���������
			text.replace(position, len, subSubstr);
		}
		else {
			temp = false;  // ���� ��������� �� �������, ������� �� �����
		}
	}

	return text;  // ���������� ������������ �����
}

std::string cleanText(const std::string& text) {
	std::string result;
	for (char c : text) {
		// �������� ����� ���������� �� �������, ��������� ��������� ��� ����
		if (std::ispunct(static_cast<unsigned char>(c))) {
			result += ' ';
		}
		else {
			result += c;
		}
	}
	return result;
}


int countWords(const std::string& text) {
	std::string cleaned = cleanText(text);  // ������� ����� ����� ���������
	std::stringstream ss(cleaned); // ������� ������ stringstream ����� ������ ������ ��� ����� ������
	std::string word; // ���������� ��� ������ �������� �����
	int count = 0;

	while (ss >> word) {  // ���� ����� ������� ���������� (���� ��� ����) ���� �����������
		count++; // ����������� �������
	}

	return count;
}

// ������� ��� �������� ����������� � ������
int countSentences(const std::string& text) {
	int count = 0;
	for (char c : text) { // �������� �� ������� ������� � ������
		if (c == '.' || c == '!' || c == '?') { // ���� ����� ����������� �� ������ ����������
			count++;
		}
	}
	// ���� ����� �� ������������� �� ���� ����������, �� �� ������
	if (!text.empty() && count == 0 && !std::all_of(text.begin(), text.end(), isspace)) {
		count = 1;
	}
	return count;
}

int main() {
	// ������������� ������ ��� ���������� ������ � ������� ������
	setlocale(LC_ALL, "ru");

	// ������ ��������� ������� �� Windows-1251 ��� ����������� ����������� �������� ������
	SetConsoleCP(1251);         // ������������� ��������� �����
	SetConsoleOutputCP(1251);   // ������������� ��������� ������

	// �������� ����� �� ������������
	std::string p = inputText();

	// ������� ���������� �� ���������
	std::cout << "\n���������� ������:\n";
	std::cout << "���������� ����: " << countWords(p) << "\n";
	std::cout << "���������� �����������: " << countSentences(p) << "\n\n";

	// ������������ �����:
	// 1. �������� ��� ��������� "������" �� "������"
	// 2. �������� ��� ������ �� �������
	p = procText(p, "������", "������");
	p = procText(p, "������", "������");
	p = procText(p, ")", " ");
	p = procText(p, "(", " ");

	// ������� ��������� ���������
	std::cout << "����������������� �����: " << p << "\n";

	// ������� ���������� ����� ���������
	std::cout << "\n���������� ����� ���������:\n";
	std::cout << "���������� ����: " << countWords(p) << "\n";
	std::cout << "���������� �����������: " << countSentences(p) << "\n";

	return 0;
}