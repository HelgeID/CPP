//паралельне програмування, виклик методів класу в другому потоці
#include <iostream>
#include <thread>
#include <chrono>

class MyClass
{
public:
	void MyMethod()
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		std::cerr << "start second" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		std::cerr << "stop second" << std::endl;
		return;
	}

	int MyFunc(int value)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		std::cerr << "start second" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
		std::cerr << "stop second" << std::endl;
		return value*value;
	}
};

int main()
{
	int res;
	MyClass obj;

	//п-д 1:
	std::thread t([&]()
	{
		res = obj.MyFunc(10);
	});

	//п-д 2:
	//std::thread t(obj.MyMethod); //error
	//std::thread t(&MyClass::MyMethod, obj); //ok
	//std::thread t(&MyClass::MyFunc, obj, 10); //ok

	for (size_t i(0); i < 10; i++) {
		std::cerr << "main" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(750));
	}
	t.join();

	system("pause");
	return 0;
}
