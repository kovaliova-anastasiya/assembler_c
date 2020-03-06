#include<iostream>
#include "tasks.h"
#include <cassert>

void Tasks::Task1()
{
	int a; //a<=2^6, a^5=2^30, верхн€€ граница
	int a2;
	int a3;
	int x;
	std::cout << "Input a" << std::endl;
	std::cin >> a;
	int negative = -1; //чтобы -b перенести в другую сторону
	__asm {
		//если нужно сделать чередование знаков
		mov eax, a
		mov x, eax
		imul a
		mov a2, eax
		imul a
		mov a3, eax
		imul a2
		add x, eax
		mov eax, a3
		add x, eax
	}
	std::cout << x << std::endl;
}

void Tasks::Task2()
{
	//(a5 + 2 * (a2 Ц 4) + a) / a3
	int a;
	int a2;
	int a3;
	int x;
	std::cout << "Input a" << std::endl;
	std::cin >> a;
	__asm {
		mov eax, a
		imul a
		mov a2, eax
		sub eax, 4
		imul eax, 2
		mov x, eax //2 * (a2 Ц 4)
		mov eax, a2
		imul a
		mov a3, eax
		imul a2
		add eax, x //a5 + 2 * (a2 Ц 4)
		add eax, a //(a5 + 2 * (a2 Ц 4) + a)
		mov x, eax
	}
	if (a3 != 0) {
		__asm {
			div a3
			mov x, eax
		}
	}
	else {
		assert(a3 != 0);
	}
	std::cout << "The result x = " << x << std::endl;
}


//test-cases
//a=1, exception
//a=2, n=30
//a=3, n=19
//a=4, n=15
//a=5, n=13
void Tasks::Task3()
{
	std::cout << "Enter a" << std::endl;
	int a;
	std::cin >> a;
	if (a == 1) {
		throw(" a=1, no limit ");
	}
	int number = 1;
	int n = 0;
	__asm {
		mov eax, a
		mov ebx, number
		mov ecx, n
		begin_ :
		inc ecx
			imul ebx, eax
			jo end_
			jmp begin_
			end_ :
			dec ecx
			mov n, ecx;

	}
	std::cout << "Maximum n = " << n << std::endl;
}

void Tasks::Task4()
{
		__int16 A1 = 10;
		__int16 A2 = 5;
		__int16 A3 = 3;
		__int16 B1 = 1;
		__int16 B2 = 2;
		__int16 B3 = 3;
		__int16 C1 = 0;
		__int16 C2 = 0;
		__int16 C3 = 0;

		int overfl = 0;
		long long int result = 0;
		__asm {

			mov bx, A1;
			mov cx, A2;
			mov dx, A3;

			add bx, B1;   // A1 + B1
			jo _inc1;
			jno _op_one;
		_inc1:
			inc cx;

		_op_one:
			mov C1, bx;
			add cx, B2;  // A2 + B2
			jo _inc2;
			jno  _op_two;
		_inc2:
			inc dx;

		_op_two:
			mov C2, cx;
			add dx, B3;  // A3 + B3
			jo _overfl;
			jno _end;
		_overfl:
			mov eax, overfl;
			inc eax;
			mov overfl, eax;

		_end:
			mov C3, dx;
		}


		if (overfl == 1) {
			throw "Overflow";
		}
		std::cout.unsetf(std::ios::dec);
		std::cout.setf(std::ios::hex | std::ios::uppercase);
		std::cout << C3 << C2 << C1;
}

