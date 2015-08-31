#include "iostream"
#include "cstring"
using namespace std;

class Solution {
public:
	void replaceSpace(char *str, int length) {
		cout << "old str: " << str << "(" << length << ")" << endl;
		int count = 0;
		length = strlen(str);
		for (int i = 0; i < length; i++) {
			if (str[i] == ' ')	count++;
		}
		int l = length + count * 2 + 1;
		char tmp[l];
		tmp[l - 1] = '\0';
		int s_begin = 0, t_begin = 0;
		count = 0;
		int j, k;
		for (int i = 0; i < length; i++) {
			if (str[i] == ' ')
			{
				count++;
				for (j = s_begin, k = t_begin; j < i; j++, k++) {
					tmp[k] = str[j];
				}
				tmp[k] = '%';
				tmp[k + 1] = '2';
				tmp[k + 2] = '0';
				s_begin = i + 1;
				t_begin = s_begin + 2 * count;
			}
			if (s_begin < length) {
				for (j = s_begin, k = t_begin; j < length; j++, k++) {
					tmp[k] = str[j];
				}
			}
		}
		//str = tmp;
		for (int i = 0; i < l; i++)
			str[i] = tmp[i];
		cout << "new str: " << str << "(" << strlen(tmp) << ")" << endl;

	}
};

int main(int argc, char const *argv[])
{
	char s[] = {"hello world"};
	char *s_ptr = s;
	int len = strlen(s_ptr);
	Solution so;
	so.replaceSpace(s_ptr, len);
	return 0;
}
