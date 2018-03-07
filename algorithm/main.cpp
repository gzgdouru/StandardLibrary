#include "foreach.hpp"
#include "NonmodifyAlgo.hpp"
#include "ModifyAlgo.hpp"
#include "RemoveAlgo.hpp"
#include "MutatingAlgo.hpp"
#include "SortAlgo.hpp"
#include "SortedRangeAlgo.hpp"
#include "NumericAlgo.hpp"

int main(int argc, char *argv[])
{
	cout << "--------------------ForeachTest---------------------------" << endl;
	CForeachTest foreachTest;
	//foreachTest.test1();
	//foreachTest.test2();
	//foreachTest.test3();
	cout << "----------------------------------------------------------\n" << endl;

	cout << "--------------------NonmodifyAlgoTest---------------------------" << endl;
	CNonmodifyAlgoTest nonModifyAlgo;
	//nonModifyAlgo.test1();
	//nonModifyAlgo.test2();
	//nonModifyAlgo.test3();
	//nonModifyAlgo.test4();
	//nonModifyAlgo.test5();
	//nonModifyAlgo.test6();
	//nonModifyAlgo.test7();
	//nonModifyAlgo.test8();
	//nonModifyAlgo.test9();
	//nonModifyAlgo.test10();
	//nonModifyAlgo.test11();
	//nonModifyAlgo.test12();
	//nonModifyAlgo.test13();
	cout << "----------------------------------------------------------\n" << endl;

	cout << "--------------------ModifyAlgoTest---------------------------" << endl;
	CModifyAlgoTest ModifyAlgoTest;
	ModifyAlgoTest.test7();
	cout << "----------------------------------------------------------\n" << endl;

	cout << "--------------------RemoveAlgoTest---------------------------" << endl;
	CRmoveAlgoTest RemoveAlgoTest;
	//RemoveAlgoTest.test1();
	//RemoveAlgoTest.test2();
	//RemoveAlgoTest.test3();
	//RemoveAlgoTest.test4();
	cout << "----------------------------------------------------------\n" << endl;

	cout << "--------------------MutatingAlgoTest---------------------------" << endl;
	CMutatingAlgoTest MutatingAlgoTest;
	MutatingAlgoTest.test6();
	cout << "----------------------------------------------------------\n" << endl;

	cout << "--------------------SortAlgoTest---------------------------" << endl;
	CSortAlgoTest SortAlgoTest;
	SortAlgoTest.test5();
	cout << "----------------------------------------------------------\n" << endl;

	cout << "--------------------SortedRangeAlgoTest---------------------------" << endl;
	CSortRangeAlgoTest SortRangeAlgoTest;
	SortRangeAlgoTest.test7();
	cout << "----------------------------------------------------------\n" << endl;

	cout << "--------------------NumericAlgoTest---------------------------" << endl;
	CNumericAlgoTest NumericAlgoTest;
	NumericAlgoTest.test5();
	cout << "----------------------------------------------------------\n" << endl;

	getchar();
	return 0;
}