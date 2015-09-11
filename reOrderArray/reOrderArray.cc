#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
	void reOrderArray(vector<int> &array) {
		if (array.empty()) return;
		vector<int> tmp(array.size());
		int odd_count = 0, even_count = 0;
		for (auto iter : array) {
			if (iter % 2 == 1)
				odd_count++;
			else
				even_count++;
		}
		cout << "odd_count= " << odd_count << " even_count= " << even_count << endl;
		int i = 0, j = odd_count;
		for (auto it : array) {
			if (it % 2 == 1) {
				tmp[i] = it;
				i++;
			}
			if (it % 2 == 0) {
				tmp[j] = it;
				j++;
			}
		}
		int k = 0;
		for (auto t : tmp) {
			array[k] = t;
			k++;
		}
		for (auto t : array) {
			cout << t;
		}
		cout << endl;
	}
};

int main(int argc, char const *argv[])
{
	Solution so;
	vector<int> array1 = {1, 2, 3, 4, 5, 6, 7};
	vector<int> array2;
	so.reOrderArray(array1);
	return 0;
}