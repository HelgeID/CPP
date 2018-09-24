//new C++, структуровані привязки з масивами і структурами
#include <iostream>
#include <string>
#include <array>

struct MyStruct
{
	std::string str;
	int num1;
	int num2;
};

int main()
{
	//використання структри
	MyStruct my{ "Hello, World!", 100, 200 };
	auto[str, num1, num2] = my;
	std::cerr << str << " " << num1 << " " << num2 << std::endl;

	//використання масива
	std::array<int32_t, 6> arr{ 100, 200, 300, 400, 11, 22 };
	auto[a, b, c, d, _temp1, _temp2] = arr;
	std::cerr << a << std::endl;
	std::cerr << b << std::endl;
	std::cerr << c << std::endl;
	std::cerr << d << std::endl;

	return 0;
}
