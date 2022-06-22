int main()
{
	// 다음중 에러를 모두 고르세요..

	int n = 10;

	auto a1 = n;	// ok
	auto a2 = 10;	// ok

	auto& a3 = n;	// ok
//	auto& a4 = 10;	// error
	const auto& a4 = 10;	// ok

	// auto&& 는 결국 T&& 입니다. - 69 page 박스 3번째..
	//								소스 제일 아래 2줄.
	auto&& a5 = n;	// auto=int&   auto&& = int& &&     int& a5 = n;
	auto&& a6 = 10; // auto=int    auto&& = int&&       int&& a6 = 10
}