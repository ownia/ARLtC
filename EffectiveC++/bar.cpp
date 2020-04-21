#include <iostream>
#include <string>

using namespace std;

class Investment {};
Investment* createInvestment();
void f() {
    // Investment* pInv = createInvestment();
    // delete pInv;
    // auto_ptr<Investment> pInv(createInvestment());
    unique_ptr<Investment> pInv(createInvestment());
    shared_ptr<Investment> pInv1(createInvestment());
    shared_ptr<Investment> pInv2(pInv1);
    pInv1 = pInv2;
}

class Mutex {};
void lock(Mutex* pm);
void unlock(Mutex* pm);
class Lock {
   public:
    explicit Lock(Mutex* pm) : mutexPtr(pm) { lock(mutexPtr.get()); }
    ~Lock() { unlock(mutexPtr.get()); }

   private:
    // Mutex* mutexPtr;
    shared_ptr<Mutex> mutexPtr;
};

shared_ptr<Investment> pInv(createInvestment());
int daysHeld(const Investment* pi);
int days = daysHeld(pInv.get());
class Investment {
   public:
    bool isTaxFree() const;
};
Investment* createInvestment();
shared_ptr<Investment> pi1(createInvestment());
bool taxablel = !(pi1->isTaxFree());
unique_ptr<Investment> pi2(createInvestment());
bool taxablel = !((*pi2).isTaxFree());

class FontHandle {};
FontHandle getFont();
void releaseFont(FontHandle fh);
class Font {
   public:
    explicit Font(FontHandle fh) : f(fh) {}
    ~Font() { releaseFont(f); }
    FontHandle get() const { return f; }
    operator FontHandle() const { return f; }

   private:
    FontHandle f;
};
Font f1(getFont());
int newFontSize;
// changeFontSize(f1.get(),newFontSize);
// changeFontSize(f1, newFontSize);

struct Day {
    explicit Day(int d) : val(d) {}
    int val;
};
struct Month {
    explicit Month(int m) : val(m) {}
    int val;
};
struct Year {
    explicit Year(int y) : val(y) {}
    int val;
};
class Date {
   public:
    Date(const Month& m, const Day& d, const Year& y);
};

class Person {
   public:
    Person();
    virtual ~Person();

   private:
    string name;
    string address;
};
class Student : public Person {
   public:
    Student();
    ~Student();

   private:
    string schoolName;
    string schoolAddress;
};

class Window {
   public:
    string name() const;
    virtual void display() const;
};
class WindowWithScrollBars : public Window {
   public:
    virtual void display() const;
};
void printNameAndDisplay(const Window& w) {
    cout << w.name() << endl;
    w.display();
}

class Rational {
   public:
    Rational(int numerator = 0, int denominator = 1);

   private:
    int n, d;
    friend const Rational operator*(const Rational& lhs, const Rational& rhs);
};

int main() {
    Mutex m;
    Lock ml1(&m);
    Lock ml2(ml1);

    typedef string AddressLines[4];
    string* pal = new AddressLines;
    delete[] pal;

    // bool validateStudent(Student s);
    // Student plato;
    // bool platoIsOK = validateStudent(plato);
    bool validateStudent(const Student& s);

    return 0;
}