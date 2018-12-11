#include "Train.hpp"

Train::Train(const std::string station, const std::string time, int number):
station(station), time(time),number(number){ std::cout << "\n����������� Train\n";}
Train::Train(const Train& t):station(t.station), time(t.time),number(t.number){ std::cout << "\n����������� ����������� Train\n";}
Train::~Train(){}
	/*������� � ������� ��� station*/
std::string& Train::Station() { return this->station; }
	/*������� � ������� ��� time*/
std::string& Train::Time() { return this->time;}
	/*������� � ������� ��� number*/
int& Train::Number(){ return this->number;}

std::istream& operator >>(std::istream& in, Train& t){
	if(!(in >> t.number >> t.station >> t.time)){//���� ������������ ����, �������� ����������
		throw Exception("������������ ����");
	}
	return in;
}
std::ostream& operator <<(std::ostream& out, const Train& t){
	out << "\n�����: " << t.time
		 << "\n�������: " << t.station
		 << "\n�����: " <<t.number;
    return out;
}

Train& Train::operator =(const Train& t){
	station = t.station;
	number = t.number;
	time = t.time;
	return *this;
}