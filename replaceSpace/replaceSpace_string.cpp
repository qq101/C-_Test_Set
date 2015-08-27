#include "iostream"
#include "cstring"
#include "string"
using namespace std;

class Solution {
public:
	void replaceSpace(char *str, int length) {
		cout << "old str: " << str << "(" << length << ")" << endl;
		string p = str;
		string tmp;
		string word;
		int begin = 0, end = 0;
		if (p[0] == ' ') {
			tmp = tmp + "%20";
			begin = 1;
		}
		for (int i = 1; i < p.size(); i++) {
			if (p[i] == ' ') {
				end = i - 1;
				word = p.substr(begin, (end - begin + 1));
				tmp += word + "%20";
				begin = i + 1;
			}
		}
		tmp += p.substr(begin, (p.size() - begin));
		int len = tmp.size() + 1;
		char *foo=(char *)[len];
		foo= (char *)tmp.c_str();
		foo[len] = '\0';
		for (int i = 0; i < len; i++)
			str[i] = foo[i];
		cout << "new str: " << str << "(" <<  strlen(str) << ")" << endl;
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