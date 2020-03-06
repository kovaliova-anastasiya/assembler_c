#include <iostream>
#include<string>
#include<vector>
#include "class.h"

int main() {
	//������� ������, ���������� ����� ��������� � ��������� ��� �� �������
	std::string filename = "Text.txt";
	As assemb;
	std::vector<std::string>from_file=assemb.ReadData(filename);
	assemb.SetText(from_file);
	for (auto x : assemb.GetText()) {
		std::cout << x << std::endl;
	}

	//��������� ������ ����� ������
	std::cout << std::endl << std::endl;
	std::cout << "vector Data"<<std::endl;
	assemb.SetData();
	for (auto x : assemb.GetData()) {
		std::cout << x << std::endl;
	}

	//��������������� ������ data(���� ������) � map � ������� �� �����
	assemb.DataToMap();
	std::cout << std::endl << std::endl;
	std::cout << "map data" << std::endl;
	for (auto x : assemb.GetMap_data()) {
		std::cout << x.first << " = " << x.second<<std::endl;
	}

	//������� �� ������� ������ ���� ���������
	std::cout << std::endl <<"Vector code"<< std::endl;
	for (auto x : assemb.GetCode()) {
		std::cout << x << std::endl;
	}

	//��������� vector code �� �������
	//assemb.TransformCode();
	int result = assemb.TransformCode();
	std::cout << std::endl << std::endl << "The result is " << result;
	return 0;
}