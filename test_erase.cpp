#include <iostream>
#include <experimental/vector>

using std::cout;
using std::vector;

// compile w/ clang++ -std=c++20 test_erase.cpp
int main() {
  std::vector<int> v = {2, 5, 6, 4};
  std::experimental::erase_if(v, [](int i) { return i % 2 == 1; });
  for(auto i : v) { cout << i << std::endl; }
}
