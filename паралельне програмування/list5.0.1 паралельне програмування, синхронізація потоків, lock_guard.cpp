//паралельне програмування, синхронізація потоків, lock_guard
#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>

std::mutex mtx;

//ф-я малювання прямокутника
void Print(const char ch)
{
//виконання кода - синхронне
	std::cerr << "start " << ch << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//виконання кода - асинхронне
	//получає доступ тільки один потік, область видимості lock_guard обмежена скобками {}
	{
		std::lock_guard<std::mutex> lg(mtx);
		for (int i(0); i < 5; i++) {
			for (int i(0); i < 5; i++) {
				std::this_thread::sleep_for(std::chrono::milliseconds(100));
				std::cerr << ch;
			}
			std::cerr << std::endl;
		}
		//std::cerr << std::endl;
	}
//виконання кода - синхронне
	std::cerr << "end " << ch << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));

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
