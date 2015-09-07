//Folder类
#include "iostream"
#include "string"
#include "set"
using namespace std;

class Message;	//前置声明（只能使用Message的指针）
class Folder {
	//friend class Message;
public:
	Folder(const Folder&);
	Folder& operator=(const Folder&);
	~Folder();
	void addMsg(Message*);
	void remMsg(Message*);

private:
	set<Message*> msg;
	//拷贝构造函数、拷贝赋值运算符和析构函数所使用的工具函数
	//将本Folder添加到指向参数的Message中
	void add_to_Message(const Folder &);
	//从msg中的每个Message中删除本Folder
	void remove_from_Message();
};

void Folder::addMsg(Message *m) {
	msg.insert(m);
}

void Folder::remMsg(Message *m) {
	msg.erase(m);
}

//拷贝构造函数
Folder::Folder(const Folder &f):
	msg(f.msg) {
	add_to_Message(f);
}

//拷贝赋值运算符
Folder& Folder::operator=(const Folder &rhs) {
	remove_from_Message();
	msg = rhs.msg;
	add_to_Message(rhs);
	return *this;
}

//析构函数
Folder::~Folder() {
	remove_from_Message();
}


void Folder::add_to_Message(const Folder &f) {
	for (auto m : f.msg) {
		m->addFldr(this);
	}
}

void Folder::remove_from_Message() {
	for (auto m : msg) {
		m->remFldr(this);
	}
	// while(!msg.empty())
	// 	(*msg.begin())->remove(*this);
}