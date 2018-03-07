#include "../public/headfile.hpp"

bool int_ptr_less(int *px, int *py)
{
	return *px < *py;
}

int main(int argc, char *argv[])
{

	int x = 10;
	int y = 20;
	int *px = &x;
	int *py = &y;
	int *pResult = NULL;

	pResult = std::max(px, py, int_ptr_less);
	cout << "max:" << *pResult << endl;

	pResult = std::min(px, py, int_ptr_less);
	cout << "min:" << *pResult << endl;

	getchar();

	return 0;
}