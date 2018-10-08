//new C++, приклад згортки (arg) 1 (співвіднесення діапазонів і окремих елементів)
#include <iostream>
#include <algorithm>
#include <vector>

template <typename R, typename ... Ts>
auto Count(const R& range, Ts ... ts)
{
    return (std::count(std::begin(range), std::end(range), ts) + ...);
}

int main()
{
    std::vector<int> vec {10, 20, 30, 40, 50}; //також працюватиме для std::list, std::array, std::set
    std::cerr << Count(vec, 0, 20) << std::endl; //1
    std::cerr << Count(vec, 10, 30) << std::endl; //2
    std::cerr << Count(vec, 0) << std::endl; //0
    std::cerr << Count("ABCD", 'A', 'b', 'c', 'D') << std::endl; //2
    std::cerr << Count("ABCD", 'a', 'B', 'C', 'd') << std::endl; //2
    return 0;
}
