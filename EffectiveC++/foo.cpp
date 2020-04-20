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

class DBConnection {
   public:
    static DBConnection create();
    void close();
};
class DBConn {
   public:
    DBConn();
    void close() {
        db.close();
        closed = true;
    }
    ~DBConn() {
        try {
            db.close();
        } catch (char* error) {
            // do something
        }
    }

   private:
    DBConnection db;
    bool closed;
};
// DBConn::~DBConn() {
//     try {
//         db.close();
//     } catch (char* error) {
//         abort();
//     }
// }

class Transaction {
   public:
    Transaction() { init(); };  // non-virtual
    virtual void logTransaction() const = 0;

   private:
    void init() { logTransaction(); }  // virtual
};
// base class construction
// Transaction::Transaction() { logTransaction(); }
// derived class
class BuyTransaction : public Transaction {
   public:
    virtual void logTransaction() const;
};
class SellTransaction : public Transaction {
   public:
    virtual void logTransaction() const;
};
// non-virtual
class Transaction2 {
   public:
    explicit Transaction2(const string& logInfo);
    void logTransaction2(const string& logInfo) const;  // non-virtual
};
Transaction2::Transaction2(const string& logInfo) { logTransaction2(logInfo); }
class BuyTransaction2 : public Transaction2 {
   public:
    BuyTransaction2() : Transaction2(createLogString()) {}

   private:
    static string createLogString();
};

class Bitmap {};
class Widget {
   public:
    Widget& operator=(int rhs) { return *this; }
    Widget& operator+=(const Widget& rhs) { return *this; }
    Widget& operator-=(Widget rhs) { return *this; }
    void swap(Widget& rhs);

   private:
    Bitmap* pb;
};
Widget& Widget::operator=(const Widget& rhs) {
    // identity test
    if (this == &rhs) {
        return *this;
    }
    Bitmap* pOrig = pb;
    pb = new Bitmap(*rhs.pb);
    delete pOrig;
    return *this;
}
// copy and swap
Widget& Widget::operator=(const Widget& rhs) {
    Widget temp(rhs);
    swap(temp);
    return *this;
}
// by value
Widget& Widget::operator-=(Widget rhs) {
    swap(rhs);
    return *this;
}

void logCall(const string& funcName);
class Date {};
class Customer {
   public:
    // Customer();
    Customer(const Customer& rhs);
    Customer& operator=(const Customer& rhs);

   private:
    string name;
    Date lastTransaction;
};
Customer::Customer(const Customer& rhs) : name(rhs.name) {
    logCall("Customer copy constructor");
}
Customer& Customer::operator=(const Customer& rhs) {
    logCall("Customer copy assignment operator.");
    name = rhs.name;
    return *this;
}
class PriorityCustomer : public Customer {
   public:
    PriorityCustomer(const PriorityCustomer& rhs);
    PriorityCustomer& operator=(const PriorityCustomer& rhs);

   private:
    int priority;
};
PriorityCustomer::PriorityCustomer(const PriorityCustomer& rhs)
    : Customer(rhs), priority(rhs.priority) {
    logCall("PriorityCustomer copy constructor");
}
PriorityCustomer& PriorityCustomer::operator=(const PriorityCustomer& rhs) {
    logCall("'PriorityCustomer copy assignment operator");
    Customer::operator=(rhs);
    priority = rhs.priority;
    return *this;
}

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
