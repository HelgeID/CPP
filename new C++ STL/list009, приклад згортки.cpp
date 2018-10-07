//new C++, приклад згортки
#include <iostream>
#include <string>

//(ts + ... + 0) - права згортка
//(0 + ... + ts) - ліва згортка

template <typename ... Ts>
auto sum1(Ts ... ts)
{
    return (ts + ...);
}

template <typename ... Ts>
auto sum2(Ts ... ts)
{
    return (ts + ... + 0);
}

template <typename ... Ts>
auto mul(Ts ... ts)
{
    return (ts * ... * 1);
}

int main()
{
    //int res{sum1(1, 2, 3, 4, 5)};
    int res;
    res = sum1(1, 2, 3, 4, 5); //15
    //res = sum1(); //error
    res = sum2(1, 2, 3, 4, 5); //15
    res = sum2(0); //0
    res = mul(1, 10, 100); //1000
    
    std::string str1 {"Hello "};
    std::string str2 {"World"};
    std::cerr << sum1(str1 + str2) << '\n'; //Hello World
    
    return 0;
}
