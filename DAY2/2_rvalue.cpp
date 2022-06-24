// 4_rvalue - 87 page
int x = 0;
int  foo() { return x;}
int& goo() { return x; }


// lvalue : ��ȣ�� ���ʿ� ��� �ü� �ִ�.
//          �̸��� �ְ�, ���Ͻ��� �Ѿ ��밡��
//			�ּҿ����ڷ� �ּҸ� ���Ҽ� �ִ�.
//		    ������ ��ȯ�ϴ� �Լ�

// rvalue : ��ȣ�� �����ʿ��� �ü� �ִ�.
//			�̸��� ����, ���ϽĿ����� ��밡��
//			�ּҿ����ڷ� �ּҸ� ���Ҽ� ����
//		    ���� ��ȯ�ϴ� �Լ�
//          literal(10, 3.4 ��), �ӽð�ü 
int main()
{
	int v1 = 10, v2 = 10;
	
	v1 = 20; // v1 : lvalue,  20 : rvalue
	10 = v1; // error. 10 �� rvalue�̴�.
	v2 = v1;

	int* p1 = &v1;
	int* p2 = &10; 

	foo() = 10;// error
	goo() = 10; // ok


	const int c = 10;
//	c = 20; // c �� rvalue ? lvalue ?
			// �̸��� �ְ�,�޸𸮸� �Ҵ��ϰ�, �ּҸ� ���Ҽ� �ִ�.
			// immutable �� lvalue �̴�.
			// C ������ rvalue�� �����մϴ�.(��, ���� �ٸ��ϴ�.)

	// ��� RVALUE �� ����̴�. ?
	// => YES ? NO?	=> ���� NO..
	// => ����� ���ʿ� �����°� �ƴ϶�, ���������� ���ʿ� �ü� ���°�!
	Point(1, 2).x = 10; // ��������
	Point(1, 2).set(1, 2);// ������ �ƴϴ�.
}
int x = 10;
int* f1() { return &x; } // "f()" ��ü�� rvalue
						// "int*" ��� ������ ��ȯ�ϹǷ�

int*& f2() { return &x; } // error. & �� ��ȯ�ϴµ�.. �ּҴ� rvalue �̹Ƿ�
							// rvalue �� ������ ������ ����.

int* p = &x;
int* f3() { return p; } // "int*" Ÿ���� �� ��ȯ 
						// "f3()" �� rvalue
int*& f4() { return p; } // ok..  p ��ü�� ��ȯ
							// "f4()" �� lvalue
			
int main()
{
	int k = 0;
	f3() = &k; // error
	f4() = &k; // ok

	// "int*" �� �����Ͷ�� �������� ������. "int*"��� Ÿ������ �����ϼ���
}






f(); // rvalue








