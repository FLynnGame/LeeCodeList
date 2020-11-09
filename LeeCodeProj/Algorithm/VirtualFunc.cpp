
#include <iostream>

using namespace std;

class Base
{
public:
	Base() {};
	~Base() {};

	virtual void print(int m = 100) { 
		std::cout << a + 1 << std::endl; 
	}
public:
	int a = 0;
};

class Derived : public Base
{
public:
	Derived() {};
	~Derived() {};

	virtual	void print(int n = 101) {
		std::cout << b + 2 << std::endl;
	}

public:
	int b = 1;
};




int main()
{
	Base* base = new Derived[10];
	base[7].print();
	/*Base* base = new Derived();
	base->print();*/
	return 0;
}