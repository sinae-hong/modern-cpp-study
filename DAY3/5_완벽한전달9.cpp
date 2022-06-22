#include <iostream>

class StopWatch
{
	unsigned long long start;
	unsigned long long end;
public:
	StopWatch()
	{
		std::cout << "현재시간을 start에 기록" << std::endl; // 금요일 수업
	}
	~StopWatch()
	{
		std::cout << "start - 현재 시간 출력" << std::endl; // 금요일 수업
	}
};
int& f3(int a, int& r, double d) { r = 200; return r; }

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
