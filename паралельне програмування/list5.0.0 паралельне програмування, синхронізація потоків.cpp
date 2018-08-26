//паралельне програмування, синхронізація потоків
#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>

std::mutex mtx;

//ф-я малювання прямокутника
void Print(const char ch)
{
	//lock - unlock
	//получає доступ тільки один потік
	mtx.lock();
	for (int i(0); i < 5; i++) {
		for (int i(0); i < 5; i++) {
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
			std::cerr << ch;
		}
		std::cerr << std::endl;
	}
	std::cerr << std::endl;
	mtx.unlock();
	return;
}

int main()
{
	std::thread t1(Print, '*');
	std::thread t2(Print, '#');

	t1.join();
	t2.join();
	system("pause");
	return 0;
}
