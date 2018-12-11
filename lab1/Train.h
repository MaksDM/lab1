#pragma once
#include <string>
#include <iostream>
#include "Exception.hpp"

class Train{
	std::string station;//пункт назначения
	int number;//номер поезда
	std::string time;//время отправления
public:
	Train(const std::string station = "", const std::string time = "", int number = 0);
	Train(const Train& t);
	~Train();
	/*геттеры и сеттеры*/
	std::string& Station();
	std::string& Time();
	int& Number();
	/*операторы ввода и вывода*/
	friend std::istream& operator >>(std::istream& in, Train& t);
	friend std::ostream& operator <<(std::ostream& out, const Train& t);
	Train& operator =(const Train& t);//оператор присваивания
};													  