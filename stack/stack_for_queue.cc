#include "stack"
#include "iostream"
using namespace std;

class Solution
{
public:
	void push(int node) {
		while (stack2.empty() == false) {
			stack1.push(stack2.top());
			stack2.pop();
		}
		stack1.push(node);

	}

	int pop() {
		while (stack1.empty() == false) {
			stack2.push(stack1.top());
			stack1.pop();
		}
		int i = stack2.top();
		stack2.pop();
		return i;

	}

private:
	stack<int> stack1;
	stack<int> stack2;
};

int main(int argc, char const *argv[])
{
	Solution so;
	for (int i = 0; i < 10; i++) {
		so.push(i);
	}
	for (int i = 0; i < 10; i++) {
		cout << so.pop();
	}
	cout << endl;
	return 0;
}