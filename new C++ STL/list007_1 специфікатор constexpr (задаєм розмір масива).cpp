//new C++, специфікатор constexpr (задаєм розмір масива)
#include <iostream>

struct Size
{
	constexpr Size(bool flag) : size(!flag ? 4 : 8) {}
	size_t size;
};

int main()
{
	int i;
	int arr1[Size(false).size]; //size = 4
	int arr2[Size(true).size]; //size = 8

	i = 0;
	for (int &x : arr1) x = i++;

	i = 0;
	for (int &x : arr2) x = i++;

	for (int x : arr1) std::cout << x << ' '; //0 1 2 3 
	std::cout << std::endl;

	for (int x : arr2) std::cout << x << ' '; //0 1 2 3 4 5 6 7 
	std::cout << std::endl;

	system("pause");
	return 0;
}
