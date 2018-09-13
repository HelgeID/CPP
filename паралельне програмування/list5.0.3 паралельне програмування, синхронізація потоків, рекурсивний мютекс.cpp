//паралельне програмування, синхронізація потоків, рекурсивний мютекс
#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>

std::recursive_mutex rmtx;

void MyTimer(int value)
{
	rmtx.lock();
	std::cout << value << " ";
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	if (value <= 1) {
		std::cout << std::endl;
		rmtx.unlock();
		return;
	}
	value--;
	MyTimer(value);
	rmtx.unlock();
	return;
}

int main()
{
	std::thread t1(MyTimer, 10);
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	std::thread t2(MyTimer, 10);

	t1.join();
	t2.join();

	//кількість блокувань == кількість розблокувань
		//rmtx.lock();
		//rmtx.lock();
		//rmtx.lock();

		//rmtx.unlock();
		//rmtx.unlock();
		//rmtx.unlock();

	system("pause");
	return 0;
}
