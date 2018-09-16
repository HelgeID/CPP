//паралельне програмування, очікування за допомогою умовних змінних

#include <iostream>
#include <vector>
#include <mutex>
#include <thread>
#include <chrono>
#include <condition_variable>

std::vector<int> data;
int arr[]{ 10, 20, 30, 40, 50 };

std::mutex mtx;
std::condition_variable cv;

void DataWrite()
{
	for (int i(0); i < sizeof(arr) / sizeof(*arr); ++i)
	{
		std::lock_guard<std::mutex> lg(mtx); //захоплюємо потік
		data.push_back(arr[i]);
		std::cerr << "Write: " << *(data.begin() + i) << std::endl;
		cv.notify_one(); //повідомляємо ожидаючий потік
		std::this_thread::sleep_for(std::chrono::milliseconds(300)); //todo work
	}
}

void DataRead()
{
	while (true) {
		std::unique_lock<std::mutex> ul(mtx); //захоплюємо потік

		//wait перевіряє присутність даних в data
			//коли лямбда-фун. вертає false - звільняємо mutex, потік - переходить в режим очікування
		cv.wait(ul, [] {return !data.empty();});

		int element = data.front(); //получаємо перший елемент
		data.erase(data.begin()); //видаляємо перший елемент
		ul.unlock();
		std::cerr << "Read: " << element << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(300)); //todo work
		if (data.empty())
			break;
	}
}

int main()
{
	std::thread tRead(DataRead);
	std::thread tWrite(DataWrite);
	tRead.join();
	tWrite.join();

	system("pause");
	return 0;
}
