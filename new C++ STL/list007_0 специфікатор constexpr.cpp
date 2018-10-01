//new C++, специфікатор constexpr
#include <iostream>

//work
struct MyStruct
{
	//про змінну value відомо на етапі компіляції
	constexpr static double value = 10.0;
};

//not work
//struct MyStruct
//{
//	const static double value = 10.0; //не може бути проініціалізована (не компілюється)
//};

int main()
{
	MyStruct my;
	std::cerr << my.value << std::endl; //10
	system("pause");
	return 0;
}
