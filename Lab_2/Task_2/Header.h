#pragma once

#include <string>
#include <iostream>

class book
{
public:
	std::string name;  // �������� �����
	float price;       // ���� �����
	int pages;         // ���������� �������

	// ����������� �� ��������� ������ book
	book();

	// ����������� � ����������� ������ book
	book(std::string name, float price, int pages);

	// ����� ��� ��������� �������� �����
	void setName();

	// ����� ��� ��������� ���������� �������
	void setPages();

	// ����� ��� ��������� ���� ����� � �������� ����, ���� �������� ���������� � "Programming"
	void setPrice();

	// ����� ��� ���������� ������� ��������� ����� ��������
	void calcPriceOfpage();

	// ����� ��� �������� ����, ���� �������� ����� ���������� � "Programming"
	float doublePrice();

	// ����� ��� ������ ���������� � �����
	void printInfo();

	// ���������� ������ book
	~book();

private:
};
