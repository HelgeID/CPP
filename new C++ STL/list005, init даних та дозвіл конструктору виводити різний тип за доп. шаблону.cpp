//new C++, init даних та дозвіл конструктору виводити різний тип за доп. шаблону
#include <iostream>
#include <vector>

template <typename T1, typename T2, typename T3>
class MyClass
{
public:
	T1 t1;
	T2 t2;
	T3 t3;

	explicit MyClass(T1 t1_, T2 t2_, T3 t3_)
		: t1{ t1_ }, t2{ t2_ }, t3{ t3_ }
	{
	}
};

int main()
{
	//---------------------------------------------------------
	int x1 = 100;
	int x2(200);
	int x3{ 300 };
	int x4 = { 300 };

	std::vector<int> v1{ 1, 2, 3 };
	std::vector<int> v2 = { 1, 2, 3 };
	std::vector<int> v3(10, 20); //10 elements(int)

	//---------------------------------------------------------
	MyClass<int, double, std::string> obj1{ 123, 1.23, "abc" };
	MyClass obj2{ 1, 2, 3 };

	std::cerr << obj1.t1 << std::endl;//123
	std::cerr << obj1.t2 << std::endl;//1.23
	std::cerr << obj1.t3 << std::endl;//abc

	std::cerr << obj2.t1 << " " << obj2.t2 << " " << obj2.t3 << std::endl;//1 2 3

	return 0;
}
