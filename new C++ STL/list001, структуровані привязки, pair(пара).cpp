//new C++, структуровані привязки, pair(пара)
#include <iostream>
std::pair<int, int> Div(int dividend, int divisor);

int main()
{
	const auto res(Div(5, 3));
	std::cerr << res.first << " " << res.second << std::endl; //1 2

	system("pause");
	return 0;
}

std::pair<int, int> Div(int dividend, int divisor)
{
	return std::pair<int, int>(dividend / divisor, dividend % divisor);
}
