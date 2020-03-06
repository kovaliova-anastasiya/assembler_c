#include<iostream>
#include"tasks.h"
using namespace std;

int main() {
	Tasks t;
	//t.Task1();
	//t.Task2();
	try {
		t.Task3();
	}
	catch (const char* ex) {
		std::cout << ex << std::endl;
	}
	std::cout << std::endl << std::endl;
	t.Task4();
	return 0;
}