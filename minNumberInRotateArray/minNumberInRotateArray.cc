#include "iostream"
#include "vector"
#include "set"
using namespace std;

int minNumberInRotateArray(vector<int> rotateArray) {
	//方法1：vector中存在两个有序子序列，第一个有序子序列的最小值一定是第一个元素min，只要找到比min小的元素即可
	if (rotateArray.size() == 0) {
		return 0;
	}
	int min = rotateArray[0];
	for (int i = 1; i < rotateArray.size(); i++) {
		if (rotateArray[i] < min) {
			min = rotateArray[i];
			break;
		}
	}
	return min;

	/*方法2：利用set的特性（元素内部有序）
	set<int> s;
	s.insert(rotateArray.begin(), rotateArray.end());	//可以利用迭代器将其他容器的元素插入到set中
	return *s.begin();*/

}

int main(int argc, char const *argv[])
{
	vector<int> rotate = {1, 2, 3, 4, 5};
	cout << minNumberInRotateArray(rotate) << endl;
	return 0;
}


/* 复习std:set容器的相关操作
#include <iostream>
#include <set>

using namespace std;

int main()
{
	set<int> s;
	s.insert(3);
	s.insert(1);
	s.insert(2);
	s.insert(1);
	cout << "set 的 size 值为 ：" << s.size() << endl;
	cout << "set 的 maxsize的值为 ：" << s.max_size() << endl;
	cout << "set 中的第一个元素是 ：" << *s.begin() << endl;
	cout << "set 中的最后一个元素是:" << *s.end() << endl;
	s.clear();
	if (s.empty())
	{
		cout << "set 为空 ！！！" << endl;
	}
	cout << "set 的 size 值为 ：" << s.size() << endl;
	cout << "set 的 maxsize的值为 ：" << s.max_size() << endl;
	return 0;
}*/