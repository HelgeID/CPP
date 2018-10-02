//new C++, специфікатор constexpr (обчислення факторіала)
#include <iostream>

// c++11
constexpr int factorial1(const int value)
{
	return (value == 0 ? 1 : value * factorial1(value - 1));
}

// c++14
constexpr int factorial2(const int value)
{
	auto result = 1;
	for (int i = 1; i <= value; i++)
		result *= i;
	return result;
}

int main()
{
	//обчислення виконуються в compile-time, а не в run-time
	std::cerr << factorial1(5) << std::endl; //120
	std::cerr << factorial2(5) << std::endl; //120
	return 0;
}
