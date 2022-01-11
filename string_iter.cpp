#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>
using std::string;
using std::cout;
using std::endl;

int main() {
  string hat("cat hat");
  for(auto it = hat.begin(); it != hat.end(); ++it) { std::cout << *it << " "; }; cout << endl;
  for(string::iterator it = hat.begin(); it != hat.end(); ++it) { std::cout << *it << " "; }; cout << endl;
  std::copy(hat.rbegin(), hat.rend(),std::ostream_iterator<char>(cout, " ")); cout << endl;
}
