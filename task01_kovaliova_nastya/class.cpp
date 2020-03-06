#include "class.h"
#include<iostream>
#include<fstream>
#include<sstream>
#include<cassert>
#include<cctype>


void As::SetText(std::vector<std::string>text)
{
	for (auto x : text) {
		this->text.push_back(x);
	}
}

std::vector<std::string> As::GetText()
{
	return this->text;
}

std::vector<std::string> As::ReadData(std::string filename)
{
	std::vector<std::string>from_file;
	std::fstream fin(filename);
	if (fin.is_open()) {
		std::string str;
		while (getline(fin, str)) {
			from_file.push_back(str);
		}
	}
	else {
		std::cout << "error";
	}
	return from_file;
}

void As::SetData()
{
	auto iter = text.begin();
	while (iter != text.end() && (*iter).find(".data") == std::string::npos) {
		++iter;
	}

	while (iter != text.end() && (*(++iter)).find(".code") == std::string::npos) {
		data.push_back(*iter);
	}

	while (iter != text.end() && (*(++iter)).find("end") == std::string::npos) {
		code.push_back(*iter);
	}
}

std::vector<std::string> As::GetData()
{
	return this->data;
}

void As::DataToMap()
{
	std::string name;
	std::string value;
	for (auto x : this->data) {
		std::stringstream str(x);
		str >> name;
		str >> value;
		if (value == "?") {
			value = "0";
			uninit_variable.push_back(name);
		}
		
		//проверяем, является ли значение числом
		if (value[0] == '-') {
			for (int i = 1; i < value.size(); i++) {
				int n = static_cast<int>(value[i]);
				assert(std::isdigit(n));
			}
		} else {
			for (int i = 0; i < value.size(); i++) {
				int n = static_cast<int>(value[i]);
				assert(std::isdigit(n));
			}
		}
		map_data.insert(std::make_pair(name, std::stoi(value)));
	}
}

std::map<std::string, int> As::GetMap_data()
{
	return this->map_data;
}

std::vector<std::string> As::GetCode()
{
	return code;
}

int As::TransformCode()
{
	std::string command;
	std::string keeper;
	std::string variable;
	int res = 0;
	for (auto x : code) {
		std::stringstream str(x);
		str >> command;
		std::cout << command << std::endl;
		str >> keeper;
		std::cout << keeper << std::endl;
		str >> variable;
		std::cout << variable << std::endl;

		if (command == "mov") {
			for (auto map_var : map_data) {
				if (variable == map_var.first) {
					std::cout << map_var.first << " = " << map_var.second << std::endl;
					Ak = map_var.second;
				}
				else {
					if (variable == "Ak") {
						map_data.at("x05") = Ak;
						res = map_data.at("x05");
					}
				}
			}
		}
		
		if (command == "mul") {
			for (auto map_var : map_data) {
				if (variable == map_var.first) {
					Ak *= map_var.second;
				}
			}
		}

		if (command == "add") {
			for (auto map_var : map_data) {
				if (variable == map_var.first) {
					Ak += map_var.second;
				}
			}
		}
	}
	return res;
}
