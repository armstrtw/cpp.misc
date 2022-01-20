#include <iostream>
using std::cout;
using std::endl;

class Parent {
    public:
        int x;
        int y;
    Parent(int x_): x(x_),y(13) {}
};

class Child : public Parent {
    public:
        int x;
        Child(int x_): Parent(100),x(x_) {}
        int get_parent_x() { return Parent::x; }
};

int main() {
    Child c(3);
    cout << "Child's x: " << c.x << endl;
    cout << "Parent's y: " << c.y << endl;
    Child &cref{c}; // use ref to access parent
    cout << "Parent's x: " << dynamic_cast<Parent&>(cref).x << endl;
    cout << "Parent's x using member function (scope): " << c.get_parent_x() << endl;

    Child* cp = new Child(23);
    cout << "child* x: " << cp->x << endl;
    cout << "Parent's x via dynamic_cast of child*: " << dynamic_cast<Parent*>(cp)->x << endl;
}
