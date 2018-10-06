//new C++, приклад з constexpr-if
#include <iostream>
#include <string>

/////////////////////////////////////////////////////////////////////////
template <typename T>
void example1(T value)
{
	//ps: constexpr - не обовязково тут і простий if спрацює
	if constexpr(std::is_integral<T>::value)
		std::cerr << "integral value: " << value << std::endl;
	else
		std::cerr << "not integral value: " << value << std::endl;
}

/////////////////////////////////////////////////////////////////////////
template <typename T>
void example2(T value)
{
	if constexpr(std::is_integral<T>::value)
		std::cerr << "integral value" << std::endl;
	else if constexpr(std::is_same_v<T, std::string>)
	{
		if (value == std::string{ "Hello!" })
			std::cerr << value << std::endl;
		else
			std::cerr << "general string" << std::endl;
	}
	else
		std::cerr << "unknown type" << std::endl;
}

int main()
{
	std::string strA("Hello!");
	std::string strB("HI");
	unsigned int num(100);

	example1(strA); //not integral value: Hello!
	example1(num); //integral value: 100

	example2(strB);//general string
	example2(std::string("Hello!"));//Hello!
	example2(1); //integral value
	example2(1.f); //unknown type
	example2(-1); //integral value

	return 0;
}
//PS: під час виконання if constexpr інші розгалуження не компілюються!
