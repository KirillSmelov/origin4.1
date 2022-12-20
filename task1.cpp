#include<iostream>
#include<string>
#include<fstream>
#include<locale>
#include<windows.h>

class Address
{
	std::string City;
	std::string Street;
	int House_num;
	int flat_num;
public:
	Address(std::string City, std::string Street, int house_num, int flat_num)
	{
		this->City = City;
		this->Street = Street;
		this->House_num = House_num;
		this->flat_num = flat_num;
	}
	std::string output(std::string City, std::string Street,int house_num,int flat_num)
	{
		std::string str;
		str = str + City;
		str = str + ", " + Street;
		std::string stdNum1 = std::to_string(house_num);
		std::string stdNum2 = std::to_string(flat_num);
		str = str + ", " + stdNum1;
		str = str + ", " + stdNum2;
		return str;
	}
};
int main(int argc, char** argv)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int number;
	std::ifstream Fin("in.txt");
	std::ofstream Fout("out.txt.");
	if (Fin.is_open() != 0)
	{
		Fin >> number;
		Fout << number;
		Fout << "\n";
		std::string* address = new std::string[number];
		std::string City;
		std::string Street;
		int house_num = 0;
		int flat_num = 0;
		for (int i = 0; i < number; ++i)
		{
			Fin >> City;
			Fin >> Street;
			Fin >> house_num;
			Fin >> flat_num;
			Address add(City, Street, house_num, flat_num);
			address[number-1-i] = add.output(City, Street, house_num, flat_num);
		}
		for (int i = 0; i < number; ++i)
		{
			Fout << address[i];
			Fout << "\n";
		}
		delete[] address;
	}	
	Fin.close();
	Fout.close();
	return 0;
}