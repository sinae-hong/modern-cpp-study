
class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) {}
};

/*
class Rect
{
	Point pt; // ?
public:
	// ����� �ڵ�	�����Ϸ��� ������ �ڵ�
//	Rect()			// Rect() : pt()  //<= �����Ϸ��� pt�� ����Ʈ ������ȣ���ϴ��ڵ��߰�

	// C++98 ���� �ذ�å
	// => ����Ʈ �����ڰ� ���� Ÿ���� ��� ����Ÿ�� �ִٸ� �Ʒ�ó�� ��������� ������ȣ��
	Rect() : pt(0, 0)  
	{
	}
};
*/

class Rect
{
	// C++11 ���ʹ� ����Ʈ �����ڰ� ���� Ÿ���� ���
	// �Ʒ� ó�� �ص� �˴ϴ�.
	Point pt{ 0, 0 };
//	Point pt(0, 0); //error. �߰�ȣ�� ����
public:
	Rect()
	{
	}
};

int main()
{
	Rect r1;
}

