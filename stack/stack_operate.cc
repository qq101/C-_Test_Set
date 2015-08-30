#include "stack"
#include "iostream"
using namespace std;
int main(int argc, char const *argv[])
{
	const stack<int>::size_type stk_size = 10;
	stack<int> intStack;
	int ix = 0;
	while (intStack.size() != stk_size)
		intStack.push(ix++);
	int error_cnt = 0;
	while (intStack.empty() == false) {
		int value = intStack.top();
		cout << "oops! expected " << --ix << " received " << value << endl;
		intStack.pop();
	}
	return 0;
}