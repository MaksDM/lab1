#pragma once
#include <string>
#include <iostream>
#include "Exception.hpp"

class Train{
	std::string station;//����� ����������
	int number;//����� ������
	std::string time;//����� �����������
public:
	Train(const std::string station = "", const std::string time = "", int number = 0);
	Train(const Train& t);
	~Train();
	/*������� � �������*/
	std::string& Station();
	std::string& Time();
	int& Number();
	/*��������� ����� � ������*/
	friend std::istream& operator >>(std::istream& in, Train& t);
	friend std::ostream& operator <<(std::ostream& out, const Train& t);
	Train& operator =(const Train& t);//�������� ������������
};													  