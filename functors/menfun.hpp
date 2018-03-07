#pragma once
#ifndef _MEN_FUN_HPP
#define _MEN_FUN_HPP

#include "../public/headfile.hpp"

class CPerson
{
private:
	string m_szName;
public:
	void print() const
	{
		cout << m_szName << endl;
	}

	void printWithPrefix(const string& prefix) const
	{
		cout << prefix << ": " << m_szName << endl;
	}

	void foo(const vector<CPerson>& coll)
	{
		for_each(coll.begin(), coll.end(), mem_fun_ref(&CPerson::print));

		for_each(coll.begin(), coll.end(), bind2nd(mem_fun_ref(&CPerson::printWithPrefix), "person"));
	}
};

#endif // _MEN_FUN_HPP
