#include <iostream>
#include <string>
#include <vector>
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
    // friend const Rational operator*(const Rational& lhs, const Rational&
    // rhs);
    // inline const Rational operator*(const Rational& lhs, const Rational& rhs)
    // {
    //     return Rational(lhs.n * rhs.n, lhs.d * rhs.d);
    // }
};

class SpeedDataCollection {
   public:
    void addValue(int speed);
    double averageSoFar() const;
};

class WebBrowser {
   public:
    void clearCache();
    void clearHistory();
    void removeCookies();
    void clearEverything();  // member
};
// non-member
void clearBrowser(WebBrowser& wb) {
    wb.clearCache();
    wb.clearHistory();
    wb.removeCookies();
}

class WidgetImpl {
   public:
   private:
    int a, b, c;
    vector<double> v;
};
class Widget {
   public:
    Widget(const Widget& rhs);
    Widget& operator=(const Widget& rhs) { *pImpl = *(rhs.pImpl); }

   private:
    WidgetImpl* pImpl;
};

void encrypt(string& s);
int MinimumPasswordLength = 10;
string encryptPassword(const string& password) {
    using namespace std;
    if (password.length() < MinimumPasswordLength) {
        throw logic_error("Password is too short");
    }
    string encrypted;
    return encrypted;
}
string encryptPassword2(const string& password) {
    string encrypted(password);  // default-construct
    encrypted = password;
    encrypt(encrypted);
    return encrypted;
}
// skip default-construct
string encryptPassword3(const string& password) {
    string encrypted(password);
    encrypt(encrypted);
    return encrypted;
}

class Window2 {};
class SpecialWindow2 : public Window2 {
   public:
    void blink();
};
typedef vector<shared_ptr<Window2>> VPW;
typedef vector<shared_ptr<SpecialWindow2>> VPSW;

class Point {
   public:
    Point(int x, int y);
    void setX(int newVal);
    void setY(int newVal);
};
struct RectData {
    Point ulhc;  // upper left-hand corner
    Point lrhc;  // lower right-hand corner
};
class Rectangle {
   public:
    const Point& upperLeft() const { return pData->ulhc; };
    const Point& lowerRight() const { return pData->lrhc; }

   private:
    shared_ptr<RectData> pData;
};

class Image {};
class PrettyMenu {
   public:
    void changeBackground(istream& imgSrc);

   private:
    Mutex mutex;
    // Image* bgImage;
    shared_ptr<Image> bgImage;
    int imageChanges;
};
// void PrettyMenu::changeBackground(istream& imgSrc) {
//     Lock ml(&mutex);
//     bgImage.reset(new Image(imgSrc));
//     ++imageChanges;
// }

struct PMImpl {
    shared_ptr<Image> bgImage;
    int imageChanges;
};
class PrettyMenu2 {
   public:
    void changeBackground(Image imgSrc);

   private:
    Mutex mutex;
    shared_ptr<PMImpl> pImpl;
};
void PrettyMenu2::changeBackground(Image imgSrc) {
    using std::swap;
    Lock ml(&mutex);
    shared_ptr<PMImpl> pNew(new PMImpl(*pImpl));
    pNew->bgImage.reset(new Image(imgSrc));
    ++pNew->imageChanges;
    swap(pImpl, pNew);
}

int x;
void someFunc() {
    double x;
    cin >> x;
}
class Base {
   private:
    int x;

   public:
    virtual void mf1() = 0;
    virtual void mf1(int);
    virtual void mf2();
    void mf3();
    void mf3(double);
};
class Derived : public Base {
   public:
    using Base::mf1;
    using Base::mf3;
    virtual void mf1();
    void mf3();
    void mf4();
};
void Derived::mf4() { mf2(); }
class Derived2 : private Base {
   public:
    // forwarding function
    virtual void mf1() { Base::mf1(); }
};

class Shape {
   public:
    virtual void draw() const = 0;          // pure virtual
    virtual void error(const string& msg);  // impure virtual
    int objectID() const;                   // non-virtual
};
class Rectangle : public Shape {};
class Ellipse : public Shape {};

// Non-Virtual Interface
class GameCharacter {
   public:
    // virtual int healthValue() const;
    int healthValue() const {
        int retVal = doHealthValue();
        return retVal;
    }

   private:
    virtual int doHealthValue() const {}
};
// Function Pointers
class GameCharacter2;
int defaultHealthCalc(const GameCharacter2& gc);
class GameCharacter2 {
   public:
    typedef int (&HealthCalcFunc)(const GameCharacter2&);
    explicit GameCharacter2(HealthCalcFunc hcf = defaultHealthCalc)
        : healthFunc(hcf) {}
    int healthValue() const { return healthFunc(*this); }

   private:
    HealthCalcFunc healthFunc;
};
class EvilBadGuy : public GameCharacter2 {
   public:
    explicit EvilBadGuy(HealthCalcFunc hcf = defaultHealthCalc)
        : GameCharacter2(hcf) {}
};
int loseHealthQuickly(const GameCharacter2&);
int loseHealthSlowly(const GameCharacter2&);
EvilBadGuy ebg1(loseHealthQuickly);
EvilBadGuy ebg2(loseHealthSlowly);

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

    string w;
    vector<string> nums;
    int n = nums.size();
    // method A
    // 1 constructor + 1 destructor + n assignments
    for (int i = 0; i < n; ++i) {
        w = nums[i];
    }
    // method B
    // n constructors + n destructors
    for (int i = 0; i < n; ++i) {
        string w(nums[i]);
    }

    // VPW winPtrs;
    // for (VPW::iterator iter = winPtrs.begin(); iter != winPtrs.end(); ++iter)
    // {
    //     if (SpecialWindow2* psw = dynamic_cast<SpecialWindow2*>(iter->get()))
    //     {
    //         psw->blink();
    //     }
    // }
    VPSW winPtrs2;
    for (VPSW::iterator iter = winPtrs2.begin(); iter != winPtrs2.end();
         ++iter) {
        (*iter)->blink();
    }

    Derived d1;
    int x;
    d1.mf1();
    d1.mf1(x);
    Derived2 d2;
    d2.mf1();
    // d2.mf1(x);

    return 0;
}