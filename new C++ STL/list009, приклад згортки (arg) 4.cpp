//new C++, приклад згортки (arg) 4 (відправлення декількох елементів у вектор)
#include <iostream>
#include <vector>
#include <algorithm>

template <typename T, typename ... Ts>
void InsertAll(std::vector<T> &vec, Ts ... ts)
{
    (vec.push_back(ts), ...);
}

int main()
{
    std::vector<int> vec{10, 20, 30};
    InsertAll(vec, 40, 50, 60);
    for (int i(0); i<vec.size(); ++i)
        std::cerr << vec.at(i) << std::endl;
    return 0;
}
