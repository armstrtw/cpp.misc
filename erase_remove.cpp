#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

int main() {
  std::vector<int> v {1,2,3,4,5,6};
  v.erase(std::remove_if(v.begin(), v.end(), [](int i) { return (i % 2) == 0; }),v.end());
  std::copy(v.begin(),v.end(),std::ostream_iterator<int>(std::cout, "\n"));
}
