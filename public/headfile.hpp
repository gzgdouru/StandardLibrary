#ifndef _HEAD_FILE_HPP
#define _HEAD_FILE_HPP

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <list>
#include <deque>
#include <cstdlib>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <iterator>
#include <xfunctional>
#include <thread>
#include <numeric>
#include <vcruntime.h>
#include <stack>
#include <bitset>
#include <fstream>
#include <memory>
#include <cstdio>
#include <thread>
#include <mutex>
#include <chrono>
#include <ratio>
#include <sstream>
#include <iomanip>
#include <complex>
using namespace std;

template<typename T>
void printSTL(const T& coll, const string &szStr = "")
{
	if (!szStr.empty())
	{
		cout << szStr;
	}

	for (auto &it : coll)
	{
		cout << it << " ";
	}
	cout << endl;
}

template<class T>
void insert_elements(T &coll, int first, int last)
{
	for(int i = first; i <= last; ++i)
	{
		coll.insert(coll.end(), i);
	}
}

#endif