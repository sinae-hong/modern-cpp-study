int main()
{
	// ������ ������ ��� ������..

	int n = 10;

	auto a1 = n;	// ok
	auto a2 = 10;	// ok

	auto& a3 = n;	// ok
//	auto& a4 = 10;	// error
	const auto& a4 = 10;	// ok

	// auto&& �� �ᱹ T&& �Դϴ�. - 69 page �ڽ� 3��°..
	//								�ҽ� ���� �Ʒ� 2��.
	auto&& a5 = n;	// auto=int&   auto&& = int& &&     int& a5 = n;
	auto&& a6 = 10; // auto=int    auto&& = int&&       int&& a6 = 10
}