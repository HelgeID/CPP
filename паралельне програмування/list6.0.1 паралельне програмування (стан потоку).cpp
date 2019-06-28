//std::thread + std::promise
#include <iostream>
#include <vector>

#include <thread>
#include <chrono>
#include <future>

class MyClass
{
	std::vector<int> vec{ 10, 20, 30, 40, 50, 60, 70, 80, 90 };
	friend void TFUNC(MyClass*, int);
};

//тестова ф-я
void TFUNC(MyClass* obj, int num)
{
	while (num)
	{
		std::cerr << obj->vec[num - 1] << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
		num--;
	}
	std::cerr << "END FUNC" << std::endl;
}

int main()
{
	MyClass obj;

	//створюємо об'єкт promise і отримуємо з нього future
	std::promise<bool> p;
	auto future = p.get_future();

	//запускаємо завдання в окремому потоці
	std::thread t([&p, &obj] {
		TFUNC(&obj, 9);
		p.set_value(true);
	});
	t.detach();

	while (true) {
		//за допомогою очікування на future ми отримуємо статус потоку
		auto status = future.wait_for(std::chrono::milliseconds(0));
		
		//в головному потоці чекаємо завершення завдання
		if (status == std::future_status::ready) {
			std::cout << "Thread finished" << std::endl;
			break;
		}

		//sleep
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}

	system("pause");
	return 0;
}
