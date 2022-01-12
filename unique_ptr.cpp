#include <iostream>
#include <memory>
using namespace std;

class HasRaw {
  double* raw_dbl;
public:
  HasRaw(int n): raw_dbl(new double[n]) { cout << "HasRaw::HasRaw" << endl; }
  ~HasRaw() {
    // explicit release required
    delete[] raw_dbl;
    cout << "HasRaw::~HasRaw" << endl;
  }
};

class HasRaw_up {
  unique_ptr<double> raw_dbl;
public:
  HasRaw_up(int n): raw_dbl(make_unique<double>(n)) { cout << "HasRaw_up::HasRaw_up" << endl; }
  // explicit release required
  ~HasRaw_up() {
    cout << "HasRaw_up::~HasRaw_up" << endl;
  }
};

//HasRaw* getRaw() { HasRaw* hrp = new HasRaw(100); }
unique_ptr<HasRaw> getRaw() { return unique_ptr<HasRaw> (new HasRaw(100)); }

int main() {
  HasRaw hr(10);
  HasRaw_up hr_up(100);
}
