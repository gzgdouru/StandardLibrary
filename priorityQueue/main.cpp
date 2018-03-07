#include "../public/headfile.hpp"

void test1()
{
	priority_queue<float> pqFloat;
	pqFloat.push(66.6);
	pqFloat.push(22.2);
	pqFloat.push(44.4);

	cout << pqFloat.top() << " ";
	pqFloat.pop();
	cout << pqFloat.top() << endl;
	pqFloat.pop();

	pqFloat.push(11.1);
	pqFloat.push(55.5);
	pqFloat.push(33.3);

	pqFloat.pop();

	while (!pqFloat.empty())
	{
		cout << pqFloat.top() << " ";
		pqFloat.pop();
	}
	cout << endl;
}

int main(int argc, char *argv[])
{
	test1();

	cout << "hello priority queue...." << endl;
	getchar();
	return 0;
}