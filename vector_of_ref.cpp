#include <vector>
#include <iostream>
#include <functional>
using std::cout;
using std::endl;

class Animal {
public:
  virtual void talk() { cout << "Base here" << endl; }
  virtual ~Animal() {}
};

class Dog: public Animal {
public:
  void talk() { cout << "Woof!" << endl; }
};

class Cat: public Animal {
public:
  void talk() { cout << "Meow, hiss!" << endl; }
};

int main() {
  Dog dog;
  Cat cat;
  Animal& dref = dog;
  Animal& cref = cat;
  Animal& dref2 = dynamic_cast<Animal&>(*new Dog());
  Animal& cref2 = dynamic_cast<Animal&>(*new Cat());
  std::vector<std::reference_wrapper<Animal>> animals;
  animals.push_back(dref);
  animals.push_back(cref);
  animals.push_back(dref2);
  animals.push_back(cref2);
  for(auto a : animals) { a.get().talk(); }
  return 0;
}
