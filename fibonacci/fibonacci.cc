/*    1.
#include "iostream"
using namespace std;
int Fibonacci(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	else
		return (Fibonacci(n - 1) + Fibonacci(n - 2));
}

int main(int argc, char const *argv[])
{
	int i;
	cout << "input a number:" << endl;
	cin >> i;
	cout << Fibonacci(i) << endl;
	return 0;
}*/

#include <math.h>
#include "iostream"
using namespace std;

int main()
{
	int n;
	cout << "input a number:" << endl;
	cin >> n;
	if (n == 0)
		cout << "0" << endl;
	if (n == 1)
		cout << "1" << endl;
	else {
		int a = 0, b = 1;
		int c = 0;
		for (int i = 0; i < n - 1; i++) {
			c = a + b;
			a = b;
			b = c;
		}
		cout << c << endl;
	}
	return 0;
}

/*    3.
#include <math.h>
class Solution {
public:
	int Fibonacci(int n) {
		if (n == 0)
			return 0;
		if (n == 1 || n == 2)
			return 1;
		double constant_a = (1 + sqrt(5)) / 2;
		double constant_b = (1 - sqrt(5)) / 2;
		double constant_c = sqrt(5) / 5;
		double value_1 = 0;
		int value_2 = 0;
		value_1 = constant_c * (pow(constant_a , n) - pow(constant_b , n));
		value_2 = (int)value_1;
		return value_2;
	}

};*/