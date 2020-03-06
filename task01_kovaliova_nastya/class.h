#pragma once

#include <vector>
#include<map>
#include <string>

class As {
private:
	std::vector<std::string>text;
	std::vector<std::string>data;
	std::vector<std::string>code;
	std::map<std::string, int>map_data;
	std::vector<std::string>uninit_variable;
	int Ak;
public:
	void SetText(std::vector<std::string>text);
	std::vector<std::string>GetText();
	std::vector<std::string> ReadData(std::string filename);
	void SetData();
	std::vector<std::string> GetData();
	void DataToMap();
	std::map<std::string, int> GetMap_data();
	std::vector<std::string> GetCode();
	int TransformCode();
};
