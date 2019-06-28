//std::thread + std::atomic
#include <iostream>

#include <thread>
#include <atomic>
#include <chrono>

int main()
{
	std::atomic<bool> done(false); //атомарний флаг

	//запускаємо завдання в окремому потоці
	std::thread t([&done] {
		std::cout << "Thread still running" << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(5));
		done = true;
	});
	t.join();

	if (done)
		std::cout << "Thread finished" << std::endl;

	system("pause");
	return 0;
}
