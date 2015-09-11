/*设计一个动态内存管理类：简化版vector(StrVec:只适用于String，不适用模板) */
#include "iostream"
#include "string"
#include "memtoy"	//用于allocator类

using namespace std;
class StrVec {
public:
	StrVec():
		elements(nullptr), first_free(nullptr), cap(nullptr) {}	//allocator成员默认初始化
	StrVec(const StrVec &);
	StrVec & operator=(const StrVec&);
	~StrVec();
	void push_back(const string&);
	size_t size() const {return first_free - elements;}
	size_t capacity() const {return cap - elements;}
	string *begin() const {return elements;}
	string *end()  const {return first_free;}
private:
	Static allocator<string> alloc;
	//分配元素，被添加元素的函数所使用
	void chk_n_alloc() {
		if (size() == capacity()) reallocate();
	}
	//工具函数，被拷贝构造函数、拷贝赋值运算符和析构函数所使用
	pair<string*, string*> alloc_n_copy( const string* , const string*);	//会分配内存，并拷贝一个给定范围中的元素
	void free();	//销毁元素并释放内存
	void reallcate();		//获取更多内存并拷贝已有元素的
	string *elements;
	string *first_free;
	string *cap;
};

void StrVec::push_back(const string & s)
{
	chk_n_alloc();
	alloc.construct(first_free++, s);	//标准库allocator类的成员函数construct（p，arg）
}

pair<string*, string* >
StrVec::alloc_n_copy(const string *b, const string *e) {
	auto data = alloc.allocate(e - b);
	return {data, uninitialized_copy(b, e, data)}; //返回一个pair对（uninitialized_copy时allocator类的成员函数）
}

void StrVec::free() {
	if (elements) {
		for (auto p = first_free; p != elemnts;)
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);
	}
}

StrVec::StrVec(const StrVec& s) {
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second();
}

StrVec::~StrVec() { free();}

StrVec& StrVec::operator=(const StrVec &rhs) {
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

//reallocate成员函数为了避免分配和释放string的额外开销，使用了移动构造函数(类似指针的拷贝)和std::move
void StrVec::reallcate() {
	auto newcapacity = size() ? 2 * size() : 1;
	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata;
	auto elem = elements;
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	/*constructor会根据第二个参数std::move的返回值而使用移动构造函数*/
	free();
	elements = newdata;
	first_free = dest;
	cap = elemnts + newcapacity;
}