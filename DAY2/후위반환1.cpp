// 후위반환1 - 73 page
// 전통적인 함수 표기법
int square1(int a)
{
	return a * a;
}

// C++11 부터 나온 "suffix return type" 이라는 문법
auto square2(int a) -> int
{
	return a * a;
}

int main()
{
	square1(3);
	square2(3);
}