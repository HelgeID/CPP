//паралельне програмування, синхронізація потоків (баг взаїмного блокування)
#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>

std::mutex mtx1;
std::mutex mtx2;

//ф-я малювання прямокутника
void Print1()
{
	mtx2.lock(); //todo: mtx1.lock();
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
	mtx1.lock(); //todo: mtx2.lock();

	for (int i(0); i < 5; i++) {
		for (int i(0); i < 5; i++) {
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
			std::cerr << '*';
		}
		std::cerr << std::endl;
	}
	std::cerr << std::endl;

	mtx1.unlock();//1
	mtx2.unlock();//2
	return;
}

void Print2()
{
	mtx1.lock();
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
	mtx2.lock();

	for (int i(0); i < 5; i++) {
		for (int i(0); i < 5; i++) {
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
			std::cerr << '#';
		}
		std::cerr << std::endl;
	}
	std::cerr << std::endl;

	mtx1.unlock();//1
	mtx2.unlock();//2
	return;
}

int main()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	std::thread t1(Print1);
	std::thread t2(Print2);

	t1.join();
	t2.join();
	system("pause");
	return 0;
}
