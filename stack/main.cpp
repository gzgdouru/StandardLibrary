#include "../public/headfile.hpp"

void test1()
{
	stack<int> stInt;
	stInt.push(1);
	stInt.push(2);
	stInt.push(3);
	cout << stInt.top() << endl;
	stInt.pop();

	cout << stInt.top() << endl;
	stInt.pop();

	stInt.top() = 77;

	stInt.push(4);
	stInt.push(5);

	stInt.pop();

	while (!stInt.empty())
	{
		cout << stInt.top() << " ";
		stInt.pop();
	}
	cout << endl;
}

int main(int argc, char* argv[])
{
	test1();

	cout << "hello stack...." << endl;
	getchar();
	return 0;
}