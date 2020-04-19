#include "foo.h"

#include <cstring>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

const void f(int n) { cout << n << endl; }

template <typename T>
inline void callWithMax(const T& a, const T& b) {
    f(a > b ? a : b);
}

class CTextBlock {
   public:
    size_t length() const;

   private:
    char* pText;
    mutable size_t textLength;
    mutable bool lengthIsValid;
};

size_t CTextBlock::length() const {
    if (!lengthIsValid) {
        textLength = strlen(pText);
        lengthIsValid = true;
    }
    return textLength;
}

// Use member initialization list instead of assignments
class PhoneNumber {};
class ABEntry {
   public:
    ABEntry(const string& name, const string& address,
            const list<PhoneNumber> phones);

   private:
    string theName;
    string theAddress;
    list<PhoneNumber> thePhones;
    int numTimesConsulted;
};
ABEntry::ABEntry(const string& name, const string& address,
                 const list<PhoneNumber> phones)
    : theName(name),
      theAddress(address),
      thePhones(phones),
      numTimesConsulted(0) {}

template <typename T>
class NamedObject {
   public:
    NamedObject(const char* name, const T& value);
    NamedObject(const string& name, const T& value);

   private:
    T objectValue;
    string nameValue;
};
template <typename T>
class NamedObject2 {
   public:
    NamedObject2(string& name, const T& value);

   private:
    string nameValue;
    const T objectValue;
};

// class HomeForSale {
//    public:
//    private:
//     HomeForSale(const HomeForSale&);
//     HomeForSale& operator=(const HomeForSale&);
// }
class Uncopyable {
   protected:
    Uncopyable() {}
    ~Uncopyable() {}

   private:
    Uncopyable(const Uncopyable&);
    Uncopyable& operator=(const Uncopyable&);
};
class HomeForSale : private Uncopyable {};

class TimeKeeper {
   public:
    TimeKeeper();
    // ~TimeKeeper();  // non-virtual
    virtual ~TimeKeeper();
};
class AtomicClock : public TimeKeeper {};
class WaterClock : public TimeKeeper {};
class WristWatch : public TimeKeeper {};

int main() {
    int a = 0, b = 1;
    callWithMax(a, b);

    char greeting[] = "Hello";
    char* p1 = greeting;              // non-const pointer, non-const data.
    const char* p2 = greeting;        // non-const pointer, const data.
    char* const p3 = greeting;        // const pointer, non-const data.
    const char* const p4 = greeting;  // const pointer, const data.

    vector<int> vec;
    const vector<int>::iterator iter = vec.begin();
    *iter = 10;
    // ++iter;
    vector<int>::const_iterator cIter = vec.begin();
    // *cIter = 10;
    ++cIter;

    NamedObject<int> no1("Smallest Prime Number", 2);
    NamedObject<int> no2(no1);
    string newDog("Persephone");
    string oldDog("Satch");
    NamedObject2<int> p(newDog, 2);
    NamedObject2<int> s(oldDog, 36);
    // p = s;

    TimeKeeper* getTimeKeeper();
    TimeKeeper* ptk = getTimeKeeper();
    delete ptk;

    return 0;
}
