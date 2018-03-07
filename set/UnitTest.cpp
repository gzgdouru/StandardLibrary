#include "../public/headfile.hpp"

void test1()
{
	set<int> stInt{1, 2, 4, 5, 6};
	cout << "lower_bound:" << *stInt.lower_bound(3) << endl;
	cout << "upper_bound:" << *stInt.upper_bound(3) << endl;
	cout << "equal_range:" << *stInt.equal_range(3).first << " " << *stInt.equal_range(3).second << endl;

	cout << "lower_bound:" << *stInt.lower_bound(5) << endl;
	cout << "upper_bound:" << *stInt.upper_bound(5) << endl;
	cout << "equal_range:" << *stInt.equal_range(5).first << " " << *stInt.equal_range(5).second << endl;
}

void test2()
{
	set<int, greater<int> > stInt{4, 3, 5, 1, 6, 2, 5};
	printSTL(stInt, "set init:");

	auto status = stInt.insert(4);
	if (status.second)
	{
		cout << "4 insert as element " << distance(stInt.begin(), status.first) + 1 << endl;
	}
	else
	{
		cout << "4 already exists!" << endl;
	}

	set<int> stInt2(stInt.begin(), stInt.end());
	cout << "stInt2:";
	copy(stInt2.begin(), stInt2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	stInt2.erase(stInt2.begin(), stInt2.find(3));
	printSTL(stInt2, "stInt2:");

	int iNum = stInt2.erase(5);
	cout << iNum << " element(5) remove" << endl;
	printSTL(stInt2, "stInt2:");
}

template<class T>
class CRunTimeCmp
{
public:
	enum cmp_mode 
	{
		e_normal = 1,
		e_reserse = 2
	};

public:
	CRunTimeCmp(cmp_mode m = e_normal) :m_mode(m) {}
	~CRunTimeCmp() {}

	bool operator() (const T& t1, const T& t2)
	{
		return m_mode == e_normal ? t1 < t2 : t2 < t1;
	}

	bool operator== (const CRunTimeCmp &cmp)
	{
		return m_mode == cmp.m_mode;
	}

private:
	cmp_mode m_mode;
};

void test3()
{
	set<int, CRunTimeCmp<int> > stInt1{1, 2, 3, 4, 5, 6, 7, 8, 9};
	printSTL(stInt1, "stInt1:");

	CRunTimeCmp<int> cmp(CRunTimeCmp<int>::e_reserse);
	set<int, CRunTimeCmp<int> > stInt2(cmp);
	for (int i = 1; i < 10; ++i)
	{
		stInt2.insert(i);
	}
	printSTL(stInt2, "stInt2:");

	stInt1 = stInt2;
	stInt1.insert(11);
	printSTL(stInt1, "stInt1:");

	if (stInt1.value_comp() == stInt2.value_comp())
	{
		cout << "same!" << endl;
	}
	else
	{
		cout << "diff!" << endl;
	}
}

int main(int argc, char *argv[])
{
	test3();
	
	getchar();
	return 0;
}