//new C++, приклад згортки (arg) 3 (перевірка попадання всіх параметрів в заданий діапазон)
#include <iostream>
#include <algorithm>
#include <string>

template <typename T, typename ... Ts>
bool IS(T min, T max, Ts ...ts)
{
    return ((min <= ts && ts <= max) && ...);
}

int main()
{
    //std::cerr << IS(10, 20, 1, 15, 30) << std::endl; //false
    //std::cerr << IS(10, 20, 11, 12, 13) << std::endl; //true
    //std::cerr << IS(5.0, 5.5, 5.1, 5.2, 5.3) << std::endl; //true
    
    //робота з стрінгом
    std::string aaa {"aaa"};
    std::string bcd {"bcd"};
    std::string def {"def"};
    std::string zzz {"zzz"};

    std::cerr << IS(aaa, zzz, bcd, def) << std::endl; //true
    std::cerr << IS(aaa, def, bcd, zzz) << std::endl; //false
    return 0;
}
