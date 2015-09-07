//Message类
#include "iostream"
#include "string"
#include "set"
using namespace std;

class Message {
	//friend class Folder;
public:
	explicit Message(const string &str = ""):
		contents(str) {}
	Message(const Message&);	//拷贝构造函数
	Message& operator=(const Message&);	//拷贝赋值运算符
	~Message();	//析构函数
	void save(Folder&);
	void remove(Folder&);
	void swap(Message &, Message &);
	void addFldr(Folder* f) {folders.insert(f);}
	void remFldr(Folder* f) {folders.erase(f);}
private:
	string contents;
	set<Folder*> folders;
	//拷贝构造函数、拷贝赋值运算符和析构函数所使用的工具函数
	//将本Message添加到指向参数的Folder中
	void add_to_Folders(const Message&);
	//从folders中的每个Folder中删除本Message
	void remove_from_Folders();
};

void Message::save(Folder &f) {
	folders.insert(&f);
	f.addMsg(this);
}

void Message::remove(Folder &f) {
	folders.erase(&f);
	f.remMsg(this);
}

void Message::add_to_Folders(const Message &m) {
	for (auto f : m.folders) {
		f->addMsg(this);
	}
}

//Message的拷贝构造函数
Message::Message(const Message &m):
	contents(m.contents), folders(m.folders)
{
	add_to_Folders(m);
}

void Message::remove_from_Folders()
{
	for (auto f : folders) {
		f->remMsg(this);
	}
}

//Message的析构函数
Message::~Message()
{
	remove_from_Folders();
}

//Message的拷贝赋值运算符
Message& Message::operator=(const Message &rhs) {
	remove_from_Folders();
	contents = rhs.contents;
	folders = rhs.folders;
	add_to_Folders(rhs);
	return *this;
}

//Message的swap交换函数
void Message::swap(Message &lhs, Message &rhs) {
	using std::swap;
	for (auto f : lhs.folders) {
		f->remMsg(&lhs);
	}
	for (auto f : rhs.folders) {
		f->remMsg(&rhs);
	}
	swap(lhs.folders, rhs.folders);
	swap(lhs.contents, rhs.contents);
	for (auto f : lhs.folders)
		f->addMsg(&lhs);
	for (auto f : rhs.folders)
		f->addMsg(&rhs);
}