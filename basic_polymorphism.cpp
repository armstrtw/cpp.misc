#include <vector>
#include <memory>
#include <algorithm>
#include <iostream>
using std::vector;
using std::unique_ptr;
using std::make_unique;
using std::cout;
using std::endl;

// pure virtual
class Aircraft {
public:
    virtual void fly() = 0;
    virtual ~Aircraft() { cout << "~Aircraft()" << endl; }
};

class PiperArcher : public Aircraft {
    public:
    void fly() override { cout << "120 knots" << endl; }
    ~PiperArcher() { cout << "~PiperArcher()" << endl; }
};
class PiperArrow: public Aircraft {
    public:
    void fly() override { cout << "135 knots" << endl; }
    ~PiperArrow() { cout << "~PiperArrow()" << endl; }
};
class BeechBonanza : public Aircraft {
    public:
    void fly() override { cout << "178 knots" << endl; }
    // uncomment to demonstrate error
    //void flyy() override { cout << "178 knots" << endl; }
    ~BeechBonanza() { cout << "~BeechBonanza()" << endl; }
};

int main() {
    // traditional push to build vector
    cout << "unique_ptr vector:" << endl;
    vector<unique_ptr<Aircraft>> fleet_uptr;
    fleet_uptr.push_back(make_unique<PiperArcher>());
    fleet_uptr.push_back(make_unique<PiperArrow>());
    fleet_uptr.push_back(make_unique<BeechBonanza>());
    std::for_each(fleet_uptr.begin(),fleet_uptr.end(),[](auto& x) { x->fly(); });

    cout << "traditional vector<obj*>:" << endl;
    // no destuctors called, unless vector erased
    std::vector<Aircraft*> fleet{ new PiperArcher(), new PiperArrow(), new BeechBonanza() }; 
    std::for_each(fleet.begin(),fleet.end(),[](auto& x) { x->fly(); });
    // need to walk vector to call destructors
    std::for_each(fleet.begin(),fleet.end(),[](auto x) { delete x; });
    fleet.clear();
    return 0;
}
