#include "../public/headfile.hpp"
using namespace std;

int main(int argc, char *argv[])
{
	string szStr = R"nc(heek\n\hds,\n\\he\\\0)")nc";
	cout << szStr << endl;

	getchar();

	return 0;
}