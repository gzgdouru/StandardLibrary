#include "../public/headfile.hpp"

void testOne();

template<class T, size_t SIZE>
class CMyArray
{
public:
	CMyArray()
	{
		memset(m_Array, 0, SIZE);
	}

	~CMyArray()
	{

	}

	T* begin()
	{
		return m_Array;
	}

	const T* begin() const
	{
		return m_Array;
	}

	T* end()
	{
		return m_Array + SIZE;
	}

	const T* end() const
	{
		return m_Array + SIZE;
	}

	T& operator[] (size_t i)
	{
		return m_Array[i];
	}

	const T& operator[] (size_t i) const 
	{
		return m_Array[i];
	}

	size_t size() const
	{
		return SIZE;
	}

	T* as_array()
	{
		return m_Array;
	}

private:
	T m_Array[SIZE];
};

void testTwo();

int main(int argc, char *argv[])
{
	//testOne();

	testTwo();

	getchar();

	return 0;
}

void testOne()
{
	int Array[] = { 1, 3, 5, 7, 9, 11 };
	int Array2[6] = { 0 };

	transform(Array, Array + 6, Array, Array2, multiplies<int>());

	sort(Array2, Array2 + 6);

	cout << "Array2:";
	copy(Array2, Array2 + 6, ostream_iterator<int>(cout, " "));
	cout << endl;
}

void testTwo()
{
	CMyArray<int, 10>myArray;
	for (int i = 0; i < 10; ++i)
	{
		myArray[i] = i + 1;
	}
	printSTL(myArray, "MyArray init:");

	reverse(myArray.begin(), myArray.end());
	printSTL(myArray, "MyArray reverse:");

	/*transform(myArray.begin(), myArray.end(), myArray.begin(), negate<int>());
	printSTL(myArray, "MyArray negate:");*/
}