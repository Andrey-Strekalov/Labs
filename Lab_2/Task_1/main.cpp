#include <iostream>
#include "Header.h" 

int main() {
	setlocale(LC_ALL, "ru");

	realNum* realNumbers = new realNum;
	realNumbers->inputNumbers();
	realNumbers->procNum();

	delete realNumbers;
	return 0;
}
