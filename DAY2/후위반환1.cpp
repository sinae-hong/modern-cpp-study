// ������ȯ1 - 73 page
// �������� �Լ� ǥ���
int square1(int a)
{
	return a * a;
}

// C++11 ���� ���� "suffix return type" �̶�� ����
auto square2(int a) -> int
{
	return a * a;
}

int main()
{
	square1(3);
	square2(3);
}