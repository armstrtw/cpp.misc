#include <iostream>
#include <memory>
using namespace std;

class HasRaw {
  double* raw_dbl;
public:
  HasRaw(int n): raw_dbl(new double[n]) { cout << "HasRaw::HasRaw" << endl; }
  ~HasRaw() { cout << "HasRaw::~HasRaw" << endl; }
};

//HasRaw* getRaw() { HasRaw* hrp = new HasRaw(100); }
unique_ptr<HasRaw> getRaw() { return unique_ptr<HasRaw> (new HasRaw(100)); }

int main() {
  HasRaw hr(10);
  unique_ptr<HasRaw> hrp = getRaw();
}
