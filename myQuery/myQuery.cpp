#include "iostream"
#include "fstream"
#include "sstream"
#include "string"
#include "vector"
#include "map"
#include "set"
using namespace std;
int main(int argc, char const *argv[])
{
	ifstream in(argv[1]);
	string line;
	vector<string> file;
	map<string, set<int>> word_line;
	while (getline(in, line)) {
		file.push_back(line);
		int n = file.size();
		istringstream istr(line);
		string word;
		while (istr >> word) {
			set<int> &s = word_line[word];
			s.insert(n);
		}
	}

	string input;
	while (1) {
		cout << "enter a word to find,or 'q' to quit!";
		if (!(cin >> input) || input == "q")
			break;
		auto loc = word_line.find(input) ;
		if (loc == word_line.end())
			cout << "No the word:  " << input << endl;
		else {

			set<int> &tmp_set = loc->second;
			cout << input << " " << tmp_set.size() << endl;
			for (auto &a : tmp_set) {
				cout << "(line " << a << " ) : " << file[a - 1] << endl;
			}
		}



	}
	return 0;
}