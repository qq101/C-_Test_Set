#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
	void reOrderArray(vector<int> &array) {
		//解法1：利用另一个数组，按奇偶个数顺序插入；空间换时间
		/*if (array.empty()) return;
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
		cout << endl;*/

		//解法2：利用指针操作，循环遍历array；类似冒泡法：将奇数一个个往前冒
		if (array.empty()) return;
		int *even = &array[0];//偶数
		int *odd = &array[0] ;//奇数
		int tmp, even_count = 0;
		int *ptr;
		for (int i = 0; i < array.size(); i++) {
			ptr = &array[i];
			if (array[i] % 2 == 0) {
				even_count++;
				even = ptr;
			}
			if (array[i] % 2 == 1) {
				int number = even_count;
				odd = ptr;
				if (number != 0) {
					tmp = *odd;
					*odd = *even;
					while (number > 1) {
						*even = *(even - 1);
						even--;
						number--;
					}
					*even = tmp;
					even = odd;
				}
			}
			if (i == array.size() - 1)
				break;
		}

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