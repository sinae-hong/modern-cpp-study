#include <iostream>
#include <chrono>
#include <thread>
using namespace std::literals;

class StopWatch
{
	unsigned long long start;
	unsigned long long end;
public:
	StopWatch()
	{
		std::cout << "����ð��� start�� ���" << std::endl; // �ݿ��� ����
	}
	~StopWatch()
	{
		std::cout << "start - ���� �ð� ���" << std::endl; // �ݿ��� ����
	}
};
int& f3(int a, int& r, double d) 
{
	std::this_thread::sleep_for(5s);
	r = 200;
	return r; 
}

template<typename F, typename ... T>
decltype(auto) chronometry(F f, T&& ... arg)
{
	StopWatch sw;
	return f(std::forward<T>(arg)...);
}

int main()
{
	int n = 10;
	
	int& r = chronometry(f3, 10, n, 3.4);

}
