//new C++, обмежуємо область видимості у if(...) і switch(...)
#include <iostream>

int main()
{
//old variant
	{
		bool condition = true;
		auto var(1000);
		if (condition) {
			std::cerr << var << std::endl;//1000
		}
		std::cerr << var << std::endl;//доступ до var присутній
	}
	//std::cerr<<var<<std::endl;//error: до var немає доступу

//if
	bool condition = true;
	if (auto var(1000); condition) {
		std::cerr << var << std::endl;//1000
	}
	else
		std::cerr << (var + var) << std::endl;//2000
	//std::cerr<<var<<std::endl;//error: до var у if немає доступу

//switch
	int init_value(1);
	switch (auto var(init_value); var) {
	case 1: break;
	case 2: break;
		//...
	}
	//std::cerr<<var<<std::endl;//error: до var у switch немає доступу

	return 0;
}
