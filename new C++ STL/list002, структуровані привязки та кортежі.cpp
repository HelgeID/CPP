//new C++, структуровані привязки та кортежі
#include <iostream>
#include <tuple>
#include <string>

auto MyFun() {
	return std::make_tuple("Hello!", 1000);
}

auto Data() {
	return std::make_tuple(10, 20, 30, 40, 50);
}

int main()
{
	auto data = Data();
	std::cerr << std::get<0>(data) << std::endl; //10
	std::cerr << std::get<1>(data) << std::endl; //20
	std::cerr << std::get<2>(data) << std::endl; //30
	std::cerr << std::get<3>(data) << std::endl; //40
	std::cerr << std::get<4>(data) << std::endl; //50

	std::string sStr;
	int nNum;
	std::tie(sStr, nNum) = MyFun();
	std::cerr << sStr << " " << nNum << std::endl; //"Hello!" 1000

	auto[str, num] = MyFun();
	std::cerr << str << " " << num << std::endl; //"Hello!" 1000

	auto val = std::make_tuple(100, 200);
	auto&[first, second] = val;
	first += 11;
	std::cerr << std::get<0>(val) << std::endl; //111

	return 0;
}
