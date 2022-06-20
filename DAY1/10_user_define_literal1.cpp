#include <iostream>

class Meter
{
	int value;
public:
	Meter(int n) : value(n) {}
};

//정수형 리터럴뒤에 붙이는 경우 반드시 인자타입은 아래처럼해야 합니다.
Meter operator""_m(unsigned long long value)
{
	Meter m(value);
	return m;
}
int main()
{
	Meter n1 = 3_m; // operator""_m(3)
}