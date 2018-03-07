#include "../public/headfile.hpp" 
using namespace std;

int main(int argc, char *argv[])
{
	for (int i : {1, 3, 5, 7, 9})
	{
		cout << i << " ";
	}
	cout << endl; 

	vector<int> vtInt{ 2, 4, 6, 8, 10 };
	printSTL(vtInt);

	set<string> stStr{ "hello", "word" };
	printSTL(stStr);

	getchar();
}