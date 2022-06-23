// 58 page
class Vector
{
	int sz;
public:
	// explicit 생성자 : 직접 초기화만 가능하고,
	//					복사 초기화는 사용할수 없다. - C++98 시절 문법
	explicit Vector(int s) : sz(s) {}
};
void foo(Vector v) {} 	// Vector v = 10 으로 받게 됩니다
						// 즉, 인자의 전달은 "복사 초기화" 입니다.
int main()
{
	// 인자가 한개인 생성자가 있으면 아래의 표기법이 가능합니다.
	Vector v1(10);	// C++98. 직접 초기화
	Vector v2 = 10; // C++98. 복사 초기화

	Vector v3{ 10 };	// C++11. 직접 초기화
	Vector v4 = { 10 };	// C++11. 복사 초기화

	//----------------
	foo(10); // ?
	foo(v3); // Vector v = v3; // 복사 생성자. 인데.. 디폴트 복사 생성자는
							//	explicit 가 아닙니다.
}







