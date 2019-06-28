//std::thread и std::packaged_task
#include <iostream>

#include <future>
#include <thread>
#include <chrono>

int main()
{
	//створюємо packaged_task, передавши в неї завдання і отримуємо об'єкт future.
	std::packaged_task<void()> task([] {
		std::cout << "Thread started" << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(5));
	});
	auto future = task.get_future();

	//запускаємо завдання в виділеному потоці
	std::thread t(std::ref(task));
	t.detach();
	
	//перевірка на завершення в головному потоці
	while (true)
	{
		auto status = future.wait_for(std::chrono::milliseconds(0));
		if (status == std::future_status::ready) {
			std::cout << "Thread finished" << std::endl;
			break;
		}
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}

	system("pause");
	return 0;
}
