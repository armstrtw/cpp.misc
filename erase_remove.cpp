#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

int main() {
  std::vector<int> v {1,2,3,4,5,6};
  std::cout << "original vector:" << std::endl;
  std::copy(v.begin(),v.end(),std::ostream_iterator<int>(std::cout, " ")); std::cout << std::endl;
  v.erase(std::remove_if(v.begin(), v.end(), [](int i) { return (i % 2) == 0; }),v.end());

  std::cout << "after remove / erase:" << std::endl;
  std::copy(v.begin(),v.end(),std::ostream_iterator<int>(std::cout, " "));std::cout << std::endl;
}
