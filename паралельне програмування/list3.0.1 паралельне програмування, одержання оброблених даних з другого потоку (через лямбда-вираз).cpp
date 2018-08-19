//паралельне програмування, одержання оброблених даних з другого потоку (через лямбда-вираз)
#include <iostream>
#include <thread>

int MySum(int a, int b)
{
	return a + b;
}

int main()
{
	int res(0);

	/////////////////////////////////////////////////////////////////
	//v1
	std::thread t1([&res]()
	{
		res = MySum(10, 20);
	});
	t1.join();
	std::cerr << res << std::endl; //30

	/////////////////////////////////////////////////////////////////
	//v2
	auto func = [&res]() {res = MySum(1, 2);}; // func - проміжна змінна
	std::thread t2(func);
	t2.join();
	std::cerr << res << std::endl; //3

	/////////////////////////////////////////////////////////////////
	system("pause");
	return 0;
}
