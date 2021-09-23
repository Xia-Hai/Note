#include <string>
#include <iostream>
using namespace std;

template <typename T>
class Shared_ptr {
public:
	// 空参构造 空指针
	Shared_ptr():count(0), _ptr((T*)0) {}
	// 构造函数 count必须new出来
	Shared_ptr(T* p) : count(new int(1)), _ptr(p) {}
	// 拷贝构造函数 使其引用次数加一
	Shared_ptr(Shared_ptr<T>& other) : count(&(++ *other.count)), _ptr(other._ptr){}
	// 重载 operator*和operator-> 实现指针功能
	T* operator->() { return _ptr; }
	T& operator*() { return *_ptr; }
	// 重载operator=
	// 如果原来的Shared_ptr已经有对象，则让其引用次数减一并判断引用是否为零(是否调用delete)。
	// 然后将新的对象引用次数加一。
	Shared_ptr<T>& operator=(Shared_ptr<T>& other)
	{
		if (this == &other)
			return *this;

		++*other.count;
		if (this->_ptr && 0 == --*this->count)
		{
			delete count;
			delete _ptr;
			cout << "delete ptr =" << endl;
		}

		this->_ptr = other._ptr;
		this->count = other.count;
		return *this;
	}
	// 析构函数 使引用次数减一并判断引用是否为零(是否调用delete)。
	~Shared_ptr()
	{
		if (_ptr && --*count == 0)
		{
			delete count;
			delete _ptr;
			cout << "delete ptr ~" << endl;
		}
	}
	int getRef() { return *count; }
private:
	int* count; // should be int*, rather than int
	T* _ptr;
};

int main()
{
	Shared_ptr<string> pstr(new string("abc"));
	cout << "pstr:"  << pstr.getRef()  << " " << *pstr  << endl;

	Shared_ptr<string> pstr2(pstr);
	cout << "pstr:"  << pstr.getRef()  << " " << *pstr  << endl;
	cout << "pstr2:" << pstr2.getRef() << " " << *pstr2 << endl;

	Shared_ptr<string> pstr3(new string("hao"));
	cout << "pstr3:" << pstr3.getRef() << " " << *pstr3 << endl;

	pstr3 = pstr2;
	cout << "pstr:"  << pstr.getRef()  << " " << *pstr  << endl;
	cout << "pstr2:" << pstr2.getRef() << " " << *pstr2 <<  endl;
	cout << "pstr3:" << pstr3.getRef() << " " << *pstr3 << endl;


	return 0;
}
