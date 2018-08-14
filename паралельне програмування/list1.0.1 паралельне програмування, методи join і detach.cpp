//паралельне програмування, методи join і detach
#include <iostream>
#include <thread>
#include <chrono>

///////////////////////////////////////////////////////////
//ф-я виводу в консоль
void Print(char* text)
{
	std::cerr << text << std::endl;
	return;
}

///////////////////////////////////////////////////////////
void MyFunc()
{
	for (size_t i(0); i < 10; i++) {
		Print("Second ");
		std::this_thread::sleep_for(std::chrono::milliseconds(250));
	}
	return;
}

int main()
{
	std::thread t(MyFunc); //виклик ф-ї MyFunc в другому потоці

	//v1 (detach)
	t.detach(); //розриваємо зв'язок з основним потоком

	for (size_t i(0); i < 10; i++) {
		Print("Main ");
		std::this_thread::sleep_for(std::chrono::milliseconds(250));
	}

	//якщо другий потік щось робив, то при завершенні головного потоку він переривається, бо
	//ми відпустили його (розірвали зв'язок)

	//v2 (join)
	//t.join(); //чекаємо завершення другого потоку (основний потік блокується)

	//якщо викликати метод join після створення потока, то головна програма буде виконуватися послідовно
	//спочатку один потік, а потім другий

	system("pause");
	return 0;
}
