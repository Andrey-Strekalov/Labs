#pragma once

#include <string>
#include <iostream>

class book
{
public:
	std::string name;  // Название книги
	float price;       // Цена книги
	int pages;         // Количество страниц

	// Конструктор по умолчанию класса book
	book();

	// Конструктор с параметрами класса book
	book(std::string name, float price, int pages);

	// Метод для установки названия книги
	void setName();

	// Метод для установки количества страниц
	void setPages();

	// Метод для установки цены книги и удвоения цены, если название начинается с "Programming"
	void setPrice();

	// Метод для вычисления средней стоимости одной страницы
	void calcPriceOfpage();

	// Метод для удвоения цены, если название книги начинается с "Programming"
	float doublePrice();

	// Метод для вывода информации о книге
	void printInfo();

	// Деструктор класса book
	~book();

private:
};
