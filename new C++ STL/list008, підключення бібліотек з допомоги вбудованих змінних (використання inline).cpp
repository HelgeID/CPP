//new C++, підключення бібліотек з допомоги вбудованих змінних (використання inline)
//---------------------------------------------------------
File: mylib.h
//---------------------------------------------------------
#include<string>
#pragma once
class MyClass
{
public:
    static inline std::string str{"HI!"};
    
    static std::string& str_fun()
    {
        return str;
    }
    
    static void set(const std::string);
};

MyClass obj; //об'єкт можемо використовувати скрізь

//---------------------------------------------------------
File: mylib.cpp
//---------------------------------------------------------
#include "mylib.h"

static void MyClass::set(std::string _str)
{
    str = _str;
}

//---------------------------------------------------------
File: mylib2.h
//---------------------------------------------------------
#include "mylib.h"

class SET { public: SET(const std::string str) { obj.str = str; } };

//---------------------------------------------------------
File: main.cpp
//---------------------------------------------------------
#include <iostream>
#include "mylib.h"
#include "mylib2.h"

int main()
{
    /////////////////////////////////////////
    std::cout << obj.str << std::endl;
    /////////////////////////////////////////
    const std::string str = "Hello, World!";
    obj.str_fun() = str;
    std::cout << obj.str << std::endl;
    /////////////////////////////////////////
    SET set("ABC");
    std::cout << obj.str << std::endl;
    return 0;
}
