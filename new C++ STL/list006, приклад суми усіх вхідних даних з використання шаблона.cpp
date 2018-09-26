//new C++, приклад суми усіх вхідних даних з використання шаблона
#include <iostream>

//ex1
template <typename T>
struct Sum
{
	T value;
	template <typename ... Ts>
	Sum(Ts&& ... values) : value{ (values + ...) } {}
};

//ex2
template <typename T>
double sum(T t) {
	return t;
}

template <typename T, typename... Rest>
double sum(T t, Rest... rest) {
	return t + sum(rest...);
}

int main()
{
	//1
	Sum<float> sObj{ 1.f, 2.f, 3.f, 10 };
	std::cerr << sObj.value << std::endl; //16

	//2
	double sSum = sum(1.0, 2.0, 3.0);
		//sum(1.0, 2.0, 3.0);
		//1.0 + sum(2.0, 3.0);
		//1.0 + (2.0 + sum(3.0));
		//1.0 + (2.0 + (3.0));
	std::cerr << sSum << std::endl; //6
	return 0;
}

////////////////////////////////////////
/*
template <typename T>
T square(T t) { return t * t; }

template <typename T>
double power_sum(T t) { return t; }

template <typename T, typename... Rest>
double power_sum(T t, Rest... rest) {
return t + power_sum(square(rest)...);
}

power_sum(2.0, 4.0, 6.0);
2.0 + power_sum(square(rest)...);
2.0 + power_sum(square(4.0), square(6.0));
2.0 + (square(4.0) + power_sum(square(rest)...))
2.0 + (square(4.0) + power_sum(square(square(6.0)));
2.0 + (square(4.0) + (square(square(6.0))))
*/
