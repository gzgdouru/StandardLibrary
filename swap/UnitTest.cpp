#include "../public/headfile.hpp"

class CMyDemo
{
public:
	CMyDemo(int a, int b):x(a), y(b) {}
	~CMyDemo() {}

	void swap(CMyDemo &demo1)
	{
		std::swap(x, demo1.x);
		std::swap(y, demo1.y);
		cout << "CMyDemo swap!" << endl;
	}

	int x;
	int y;
};

namespace std
{
	void swap(CMyDemo& demo1, CMyDemo& demo2)
	{
		demo1.swap(demo2);
	}
}

int main(int argc, char *argv[])
{
	CMyDemo demo1(10, 20);
	CMyDemo demo2(30, 40);

	cout << "befor swap:" << endl;
	cout << "demo1:x=" << demo1.x << ",y=" << demo1.y << endl;
	cout << "demo2:x=" << demo2.x << ",y=" << demo2.y << endl;

	std::swap(demo1, demo2);
	cout << "after swap:" << endl;
	cout << "demo1:x=" << demo1.x << ",y=" << demo1.y << endl;
	cout << "demo2:x=" << demo2.x << ",y=" << demo2.y << endl;

	getchar();

	return 0;
}