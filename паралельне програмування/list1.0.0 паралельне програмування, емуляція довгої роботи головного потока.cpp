//паралельне програмування, емуляція довгої роботи головного потока
#include <iostream>
#include <thread> //для роботи з потоками
#include <chrono> //для роботи з часом

//ф-я виводу в консоль
void Print(char* text)
{
	std::cerr << text << std::endl;
	return;
}

int main()
{
	//start
	Print("START main thread");
	std::cerr << "ID thread: " << std::this_thread::get_id() << std::endl; //ідентифікатор потоку

	//pause
	Print("PAUSE main thread: 5s...");
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));

	//stop
	Print("STOP main thread");

	system("pause");
	return 0;
}
