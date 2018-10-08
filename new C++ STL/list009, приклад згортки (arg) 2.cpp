//new C++, приклад згортки (arg) 2 (перевірка успішності вставки декількох елементів в більшість)
#include <iostream>
#include <algorithm>
#include <set>

template <typename T, typename ... Ts>
bool InsertAll(T &set, Ts ... ts)
{
    return (set.insert(ts).second && ...);
}

int TakeElem(std::set<int>& my_set, int elem)
{
    //v1
    std::set<int>::iterator it = my_set.begin();
    std::advance(it, elem);
    int value = *it;
    //v2
    //int value = *std::next(my_set.begin(), elem);
    
    if (my_set.size() <= elem)
        return 0;
    return value;
}

int main()
{
    //set{10, 20, 30}
    std::set<int> my_set {10, 20, 30};
    
    //set{10, 20, 30, 40, 50, 60}
    std::cerr << InsertAll(my_set, 40, 50, 60) << std::endl; //true
    
    //set{10, 20, 30, 40, 50, 60, 70}
    std::cerr << InsertAll(my_set, 70, 10, 80) << std::endl; //false
    
    std::cerr << "Value: " << TakeElem(my_set, 6) << std::endl; //Value: 70
    std::cerr << "Value: " << TakeElem(my_set, 7) << std::endl; //Value: 0
    return 0;
}
