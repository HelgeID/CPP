//паралельне програмування, очікування за допомогою умовних змінних (приклад)

#include <iostream>
#include <vector>
#include <mutex>
#include <thread>
#include <chrono>
#include <condition_variable>

bool is_ready(false);
std::mutex mtx;
std::condition_variable cv;

void DoWork()
{
	for (int index(8); index >=0; --index) {
		std::this_thread::sleep_for(std::chrono::milliseconds(400));
		std::cerr << index << " ";
	}
	std::cerr << std::endl;
	return;
}

void MyFun()
{
	DoWork();
	std::unique_lock<std::mutex> ul(mtx);
	is_ready = true;
	cv.notify_one();
	return;
}

int main()
{
	std::thread t(MyFun);
	std::unique_lock<std::mutex> ul(mtx);
	while (!is_ready)
	{
		cv.wait(ul);
		if (!is_ready)
			std::cerr << "Spurious wake up!\n";//Помилкове пробудження!
	}
	t.join();

	system("pause");
	return 0;
}
