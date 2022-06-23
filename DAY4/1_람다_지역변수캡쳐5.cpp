// 149
int main()
{
	int v1 = 0, v2 = 0;

	auto f1 = [v1, &v2](int a) { ... }; // v1은 값,   v2는 참조로 캡쳐
	auto f2 = [&v1, v2](int a) { ... };	// v1은 참조, v2는 값으로 캡쳐

	auto f3 = [=](int a) { ... }; // 모든 지역변수를 값 캡쳐
	auto f4 = [&](int a) { ... }; // 모든 지역변수를 참조 캡쳐

	auto f5 = [=, &v2](int a) { ... }; // v2는 참조, v2를 제외한 모든 지역변수는 값 캡쳐
	auto f6 = [&,  v2](int a) { ... }; // v2는 값,   v2를 제외한 모든 지역변수는 참조 캡쳐
	auto f7 = [&, &v2](int a) { ... }; // error. 디폴트 모드와 다른 경우만 표기 가능

	auto f8 = [x = v1, &y = v2](int a) { x, y };	// int x = v1 으로 사용
													// int& y = v2 로 사용
													// 즉, 람다표현식안에서는 x, y 라는 이름 사용
	auto f9 = [x = std::move(v1)](int a) { x }; // int x= std::move(v1)
}




