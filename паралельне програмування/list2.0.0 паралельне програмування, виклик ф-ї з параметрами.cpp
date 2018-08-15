//паралельне програмування, виклик ф-ї з параметрами
#include <iostream>
#include <thread>
#include <chrono>

void MyFunc(int a, int b)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(250));
	int res = a + b;
	std::cerr << a << "+" << b << "=" << res << std::endl;
	return;
}

int main()
{
	std::thread t(MyFunc, 3, 2); //виклик ф-ї MyFunc з параметрами в другому потоці
	t.join();
	system("pause");
	return 0;
}
