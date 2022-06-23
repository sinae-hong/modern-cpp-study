// 1. 일반 함수는 자신만의 타입이 없다.
//    signature 가 동일한 모든 함수는 같은 타입이다.

// 2. 함수객체는 자신만의 타입이 있다
//    signature 가 동일해도, 모든 함수 객체는 다른 타입이다.

struct Greater
{
	inline bool operator()(int a, int b) { return a > b; }
};

struct Less
{
	inline bool operator()(int a, int b) { return a < b; }
};

//-----------------------------------------------------

// 정책 변경이 가능한데, 정책 함수의 인라인 치환이 되는 sort
// STL 의 설계철학.. 함수 객체의 또다른 장점!!(인라인 치환성)
template<typename T> 
void sort(int* x, int sz, T cmp )
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = i + 1; j < sz; i++)
		{
			if (cmp(x[i], x[j])) // 2
				std::swap(x[i], x[j]);
		}
	}
}
int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

	Less    f1; f1(1, 2); sort(x, 10, f1);
	Greater f2; f2(1, 2); sort(x, 10, f2);
}