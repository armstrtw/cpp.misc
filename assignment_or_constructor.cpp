#include <iostream>

using std::cout;
using std::endl;

class A {
    int x;
    public:
    A(int _x): x(_x) { cout << "A:A(int); obj address: " << this << endl; }
    A(const A& a): x(a.x) { cout << "A:A(const& A); from: " << &a << ", to new obj:" << this << endl; }
    A& operator=(const A& a) { cout << "operator= from:" << &a << " to: " << this  << endl; x = a.x; return *this; }
};

int main() {

    A a(2);    // uses ctor
    A aa = a;  // this uses the copy ctor, b/c aa did not exist
    A aaa(19); // uses ctor
    a = aaa;   // uses operator= b/c 'a' already existed
}
