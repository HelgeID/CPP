//паралельне програмування, виклик ф-ї з параметрами, виконання роботи 2-х потоків одночасно(паралельно)
#include <iostream>
#include <thread>
#include <chrono>

//емуляція довгої роботи програми
void MyFunc(int a, int b)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	std::cerr << "start second" << std::endl;

	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	int res = a + b;
	std::cerr << a << "+" << b << "=" << res << std::endl;

	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	std::cerr << "stop second" << std::endl;
	return;
}

int main()
{
	std::thread t(MyFunc, 3, 2); //виклик ф-ї MyFunc з параметрами в другому потоці
	t.detach();

	for (size_t i(0); i < 10; i++) {
		std::cerr << "..." << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(700));
	}

	system("pause");
	return 0;
}
