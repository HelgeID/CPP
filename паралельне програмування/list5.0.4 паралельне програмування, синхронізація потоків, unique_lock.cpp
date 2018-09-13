//паралельне програмування, синхронізація потоків, unique_lock
#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>

std::mutex mtx;

//ex1 - lock_guard
//void Print(const char ch)
//{
//	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//
//	{
//		//lock_guard lg обмежений областю видимості
//		std::lock_guard<std::mutex> lg(mtx);
//
//		for (int i(0); i < 5; i++) {
//			for (int i(0); i < 5; i++) {
//				std::this_thread::sleep_for(std::chrono::milliseconds(50));
//				std::cerr << ch;
//			}
//			std::cerr << std::endl;
//		}
//	}
//
//	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//
//	return;
//}

//ex2 - unique_lock
//void Print(const char ch)
//{
//	//паралельне виконання
//	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//
//	std::unique_lock<std::mutex> ul(mtx);
//	//синхронне виконання
//	for (int i(0); i < 5; i++) {
//		for (int i(0); i < 5; i++) {
//			std::this_thread::sleep_for(std::chrono::milliseconds(50));
//			std::cerr << ch;
//		}
//		std::cerr << std::endl;
//	}
//
//	ul.unlock();//викликаємо самі, якщо цього не зробити - виклик буде в деструкторі у кінці ф-ї Print
//	//паралельне виконання
//	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//
//	//!!!якщо після синхронного виконання не має далі кода - unlock() можна не викликати!!!
//	return;
//}

//ex3 - unique_lock, параметр defer_lock
void Print(const char ch)
{
	//паралельне виконання
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	std::unique_lock<std::mutex> ul(mtx, std::defer_lock); //lock() - не викликається
	ul.lock();

	//синхронне виконання
	for (int i(0); i < 5; i++) {
		for (int i(0); i < 5; i++) {
			std::this_thread::sleep_for(std::chrono::milliseconds(50));
			std::cerr << ch;
		}
		std::cerr << std::endl;
	}

	ul.unlock();//викликаємо самі, якщо цього не зробити - виклик буде в деструкторі у кінці ф-ї Print
	//паралельне виконання
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	//!!!якщо після синхронного виконання не має далі кода - unlock() можна не викликати!!!
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
