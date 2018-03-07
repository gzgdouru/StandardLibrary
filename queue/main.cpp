#include "../public/headfile.hpp"

void test1()
{
	queue<string> qeStr;
	qeStr.push("these ");
	qeStr.push("are ");
	qeStr.push("more than ");

	cout << qeStr.front() << endl;
	qeStr.pop();
	cout << qeStr.front() << endl;
	qeStr.pop();

	qeStr.push("four ");
	qeStr.push("words!");

	qeStr.pop();

	cout << qeStr.front() << endl;
	qeStr.pop();
	cout << qeStr.front() << endl;
	qeStr.pop();

	cout << "number of elements in the queue: " << qeStr.size() << endl;
}

int main(int argc, char *argv[])
{
	test1();

	cout << "hello queue..." << endl;
	getchar();
	return 0;
}