//std::async + std::future
#include <iostream>

#include <future>
#include <chrono>

int main()
{
	using namespace std::chrono_literals;

	//запуск завдання в новому потоці. 
	//std::launch::async гарантує, що завдання виконується асинхронно в новому потоці.
	auto future = std::async(std::launch::async, [] {
		std::this_thread::sleep_for(3s);
		return 8;
	});
	
	//перевірка на завершення в головному потоці
	while (true) {
		auto status = future.wait_for(0ms);
		if (status == std::future_status::ready) {
			std::cout << "Task finished" << std::endl;
			break;
		}
		std::this_thread::sleep_for(1s);
	}

	//повертання результату
	auto result = future.get();
	std::cout << result << std::endl; //8

	system("pause");
	return 0;
}
