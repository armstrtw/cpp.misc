#include <string>
#include <iostream>

void f() {
  //void f(std::string foo) {
  // example taken from c++ conf: https://www.youtube.com/watch?v=lkgszkPnV8g
  std::string(foo);
  //std::string{foo};
  // { std::string(foo); };
  std::string("wow");
  std::cout << "foo: " << foo << std::endl;
}

int main() {
  std::string hat("hat");
  f();
}
