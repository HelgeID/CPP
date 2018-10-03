//new C++, приклад з constexpr-if
#include <iostream>
#include <vector>
#include <string>

template <typename T>
class MyClass
{
    T value;
public:
    MyClass(T val):
        value{val} {}

//v1 добавляємо до значення типу U элемент типу T (не працює, коли тип T — це std::vector<щось>, а тип U — просто int)
    //template <typename U>
    //T add(U val) const
    //{
    //    return val + value;
    //}
    
//v2 добавляємо до значення типу U элемент типу T (не працює, коли тип T, U н-д int)
    //template <typename U>
    //T add(U val)
    //{
    //    auto copy(value); //получаємо копію елемента вектора
    //    for (auto &elem : copy) {
    //        elem += val;
    //    }
    //    return  copy;
    //}
    
//v3 добавляємо до значення типу U элемент типу T (враховані два попередні варіанти)
    template <typename U>
    T add(U val) const {
        if constexpr (std::is_same_v<T, std::vector<U>>) {
            auto copy(value);
            for (auto &elem : copy) {
                elem += val;
            }
            return  copy;
        }
        else {
            return val + value;
        }
    }
};

int main()
{  
    std::vector<int> vec {1, 2, 3};
    int res(0);

    //to v1
    //res = MyClass<int>{1}.add(2); //3
    //vec = MyClass<std::vector<int>>{vec}.add(10); //error
    
    //to v2
    //res = MyClass<int>{1}.add(2); //error
    //vec = MyClass<std::vector<int>>{vec}.add(10); //11

    //to v3
    res = MyClass<int>{1}.add(2); //3
    vec = MyClass<std::vector<int>>{vec}.add(10); //11
    
////////////////////////////////////////////////////////////
    //int num(MyClass<int>{1}.add(2)); //3
    //float num(MyClass<float>{1.0}.add(2)); //3.0
    //std::string str = MyClass<std::string>{"aa"}.add("bb"); //{"aabb"}
    
//std::vector<std::string> svec {"a", "b", "c"};
//svec = MyClass<std::vector<std::string>>{svec}.add(std::string{"z"}); //{"az", "bz", "cz"}

////////////////////////////////////////////////////////////
    std::cerr<< res <<std::endl;
    std::cerr<< vec[0] <<std::endl;
    
    return 0;
}
