#include "../public/headfile.hpp"
#include "AddValue.hpp"
#include "genera.hpp"
#include "foreachThree.hpp"
#include "Removeif.hpp"
#include "menfun.hpp"
#include "fopow.hpp"

int main(int argc, char *argv[])
{
	cout << "--------------------AddValueTest---------------------------" << endl;
	CAddValueTest AddValueTest;
	//AddValueTest.test1();
	//AddValueTest.test2();
	AddValueTest.test3();
	cout << "----------------------------------------------------------\n" << endl;

	cout << "--------------------GeneraTest---------------------------" << endl;
	CGeneraTest GeneraTest;
	//GeneraTest.test1();
	//GeneraTest.test2();
	GeneraTest.test3();
	cout << "----------------------------------------------------------\n" << endl;

	cout << "--------------------ForeachThree---------------------------" << endl;
	CForeachThreeTest foreachTest;
	foreachTest.test1();
	cout << "----------------------------------------------------------\n" << endl;

	cout << "--------------------RemoveifTest---------------------------" << endl;
	CRemoveifTest removeifTest;
	removeifTest.test1();
	cout << "----------------------------------------------------------\n" << endl;

	cout << "--------------------FopowTest---------------------------" << endl;
	CFopowTest fopowTest;
	fopowTest.test1();
	cout << "----------------------------------------------------------\n" << endl;

	getchar();
	return 0;
}