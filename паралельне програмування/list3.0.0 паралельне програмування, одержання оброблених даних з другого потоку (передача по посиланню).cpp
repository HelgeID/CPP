//паралельне програмування, одержання оброблених даних з другого потоку (передача по посиланню)
#include <iostream>
#include <thread>

void MyFunc(int &number)
{
	number *= 10;
	return;
}

int main()
{
	int number = 5;
	std::thread t(MyFunc, std::ref(number));
	t.join();

	std::cerr << number << std::endl; //50

	system("pause");
	return 0;
}
