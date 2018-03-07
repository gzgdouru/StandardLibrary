#include "../public/headfile.hpp"

void test1()
{
	enum Color
	{
		red,
		yellow,
		green,
		blue,
		white,
		black,
		numColors
	};

	bitset<numColors> usedColors;
	usedColors.set(red);
	usedColors.set(blue);

	cout << "bitfield of used colors: " << usedColors << endl;
	cout << "number of used colors: " << usedColors.count() << endl;
	cout << "bitfield of unused colors: " << ~usedColors << endl;
}

void test2()
{
	cout << "267 as binary short: " << bitset<numeric_limits<unsigned short>::digits>(267) << endl;
	cout << "267 ad binary long: " << bitset<numeric_limits<unsigned long>::digits>(267) << endl;
	cout << "10000000 with 24 bits: " << bitset<24>(1e7) << endl;
	cout << "\"1000101011\" as number: " << bitset<100>(string("1000101011")).to_ulong() << endl;
}

int main(int argc, char *argv[])
{
	//test1();
	test2();

	cout << "hello bitset..." << endl;
	getchar();
	return 0;
}