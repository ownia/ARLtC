#include <cstring>
#include <iostream>
#include <list>
#include <typeinfo>
using namespace std;

template <class T>
class Set {
   public:
    bool member(const T& item) const;
    void insert(const T& item);
    void remove(const T& item);
    size_t size() const;

   private:
    list<T> rep;
};
template <typename T>
bool Set<T>::member(const T& item) const {
    return find(rep.begin(), rep.end(), item) != rep.end();
}
template <typename T>
void Set<T>::insert(const T& item) {
    if (!member(item)) {
        rep.push_back(item);
    }
}
template <typename T>
void Set<T>::remove(const T& item) {
    typename list<T>::iterator it = find(rep.begin(), rep.end(), item);
    if (it != rep.end()) {
        rep.erase(it);
    }
}
template <typename T>
size_t Set<T>::size() const {
    return rep.size();
}

class Timer {
   public:
    explicit Timer(int tickFrequency);
    virtual void onTick() const;
};
class Widget : private Timer {
   private:
    virtual void onTick() const;
};

class BorrowableItem {
   public:
    void checkOut();
};
class ElectronicGadget {
   private:
    bool checkOut() const;
};
class MP3Player : public BorrowableItem, public ElectronicGadget {};

struct DatabaseID {
    int pid;
    string data;
};
class IPerson {
   public:
    virtual ~IPerson();
    virtual string name() const = 0;
    virtual string birthDate() const = 0;
};
// factory function
shared_ptr<IPerson> makePerson(DatabaseID personIdentifier);
DatabaseID askUserForDatabaseID();
DatabaseID id(askUserForDatabaseID());
shared_ptr<IPerson> pp(makePerson(id));
class PersonInfo {
   public:
    explicit PersonInfo(DatabaseID pid);
    virtual ~PersonInfo();
    virtual const char* theName() const;
    virtual const char* theBirthDate() const;

   private:
    virtual const char* valueDelimOpen() const;
    virtual const char* valueDelimClose() const;
};
const int Max_Formatted_Field_Value_Length = 10;
const char* PersonInfo::valueDelimOpen() const { return "["; }
const char* PersonInfo::valueDelimClose() const { return "]"; }
const char* PersonInfo::theName() const {
    static char value[Max_Formatted_Field_Value_Length];
    strcpy(value, valueDelimOpen());
    strcat(value, valueDelimClose());
    return value;
}
// private inheritance
class PersonInfo2 {
   public:
    explicit PersonInfo2(DatabaseID pid);
    virtual ~PersonInfo2();
    virtual const char* theName() const;
    virtual const char* theBirthDate() const;
    virtual const char* valueDelimOpen() const;
    virtual const char* valueDelimClose() const;
};
class CPerson : public IPerson, private PersonInfo2 {
   public:
    explicit CPerson(DatabaseID pid) : PersonInfo2(pid) {}
    virtual string name() const { return PersonInfo2::theName(); }
    virtual string birthdate() const { return PersonInfo2::theBirthDate(); }

   private:
    const char* valueDelimoOpen() const { return ""; }
    const char* valueDelimoClose() const { return ""; }
};

class CompanyA {
   public:
    void sendCleartext(const string& msg);
    void sendEncrypted(const string& msg);
};
class CompanyB {
   public:
    void sendCleartext(const string& msg);
    void sendEncrypted(const string& msg);
};
class MsgInfo {};
template <typename Company>
class MsgSender {
   public:
    void sendClear(const MsgInfo& info) {
        string msg;
        Company c;
        c.sendCleartext(msg);
    }
    void sendSecret(const MsgInfo& info) {}
};
class CompanyZ {
   public:
    void sendEncrypted(const string& msg);
};
// total template specialization
template <>
class MsgSender<CompanyZ> {
   public:
    void sendSecret(const MsgInfo& info) {}
};
template <typename Company>
class LoggingMsgSender : public MsgSender(Company) {
   public:
    // if Company = CompanyZ, function doesn't exist.
    using MsgSender<Company>::sendClear;
    void sendClearMsg(const MsgInfo& info) {
        // this->sendClear(info);
        // MsgSender<Company>::sendClear(info);
        sendClear(info);
    }
};

template <typename T>
class SquareMatrixBase {
   protected:
    SquareMatrixBase(size_t n, T* pMem) : size(n), pData(pMem) {}
    void setDataPtr(T* ptr) { pData = ptr; }
    void invert(size_t matrixSize);

   private:
    size_t size;
    T* pData;
};
template <typename T, size_t n>
class SquareMatrix : private SquareMatrixBase<T> {
   public:
    SquareMatrix() : SquareMatrixBase<T>(n, data) {}

   private:
    using SquareMatrixBase<T>::invert;
    T data[n * n];
};

template <typename T>
class SmartPtr {
   public:
    template <typename U>
    SmartPtr(const SmartPtr<U>& other) : heldPtr(other.get()) {}
    T* get() const { return heldPtr; }

   private:
    T* heldPtr;
};

template <typename T>
class Rational {
   public:
    Rational(const T& numerator = 0, const T& denominator = 1);
    const T numerator() const;
    const T denominator() const;
    friend const Rational operator*(const Rational& lhs, const Rational& rhs) {
        return Rational(lhs.numerator() * rhs.numerator(),
                        lhs.denominator() * rhs.denominator());
    }
};
template <typename T>
const Rational<T> operator*(const Rational<T>& lhs, const Rational<T>& rhs) {}

template <typename IterT, typename DistT>
void doAdvance(IterT& iter, DistT d, random_access_iterator_tag) {
    iter += d;
}
template <typename IterT, typename DistT>
void doAdvance(IterT& iter, DistT d, bidirectional_iterator_tag) {
    if (d >= 0) {
        while (d--) {
            ++iter;
        }

    } else {
        while (d++) {
            --iter;
        }
    }
}
template <typename IterT, typename DistT>
void doAdvance(IterT& iter, DistT d, input_iterator_tag) {
    if (d < 0) {
        throw out_of_range("Negative distance");
    }
    while (d--) {
        ++iter;
    }
}
template <typename IterT, typename DistT>
void advance(IterT& iter, DistT d) {
    // if (typeid(typename iterator_traits<IterT>::iterator_category) ==
    //     typeid(random_access_iterator_tag)) {
    // }
    doAdvance(iter, d, typname iterator_traits<IterT>::iterator_category());
}

// Calculate Factorial: Factorial<num>::value
template <unsigned n>
struct Factorial {
    enum { value = n * Factorial<n - 1>::value };
};
template <>
struct Factorial<0> {
    enum { value = 1 };
};

void outOfMem() {
    cerr << "Unable to satisfy request for memory\n";
    abort();
}
class Widget2 {
   public:
    static new_handler set_new_handler(new_handler p) throw();
    static void* operator new(size_t size) throw(bad_alloc);

   private:
    static new_handler currentHandler;
};
new_handler Widget2::currentHandler = 0;
new_handler Widget2::set_new_handler(new_handler p) throw() {
    new_handler oldHandler = currentHandler;
    currentHandler = p;
    return oldHandler;
}
class NewHandlerHolder {
   public:
    explicit NewHandlerHolder(new_handler nh) : handler(nh) {}
    ~NewHandlerHolder() { set_new_handler(handler); }

   private:
    new_handler handler;
    NewHandlerHolder(const NewHandlerHolder&);
    NewHandlerHolder& operator=(const NewHandlerHolder&);
};
void* Widget2::operator new(size_t size) throw(bad_alloc) {
    NewHandlerHolder h(set_new_handler(currentHandler));
    return ::operator new(size);
}
template <typename T>
class NewHandlerSupport {
   public:
    static new_handler set_new_handler(new_handler p) throw();
    static void* operator new(size_t size) throw(bad_alloc);

   private:
    static new_handler currentHandler;
};
template <typename T>
new_handler NewHandlerSupport<T>::set_new_handler(new_handler p) throw() {
    new_handler oldHandler = currentHandler;
    currentHandler = p;
    return oldHandler;
}
template <typename T>
void* NewHandlerSupport<T>::operator new(size_t size) throw(bad_alloc) {
    NewHandlerHolder h(set_new_handler(currentHandler));
    return ::operator new(size);
}
template <typename T>
new_handler NewHandlerSupport<T>::currentHandler = 0;

// placement new and placement delete.
class Widget3 {
   public:
    static void* operator new(size_t size, ostream& logStream) throw(bad_alloc);
    static void operator delete(void* pMemory) throw();
    static void operator delete(void* pMemory, ostream& logStream) throw();
};
class StandardNewDeleteForms {
   public:
    // normal new/delete
    static void* operator new(size_t size) throw(bad_alloc) {
        return ::operator new(size);
    }
    static void operator delete(void* pMemory) throw() {
        ::operator delete(pMemory);
    }
    // placement new/delete
    static void* operator new(size_t size, void* ptr) throw(bad_alloc) {
        return ::operator new(size, ptr);
    }
    static void operator delete(void* pMemory, void* ptr) throw() {
        return ::operator delete(pMemory, ptr);
    }
    // nothrow new/delete
    static void* operator new(size_t size, const nothrow_t& nt) throw() {
        return ::operator new(size, nt);
    }
    static void operator delete(void* pMemory, const nothrow_t& nt) throw() {
        ::operator delete(pMemory);
    }
};
class Widget4 : public StandardNewDeleteForms {
   public:
    using StandardNewDeleteForms::operator new;
    using StandardNewDeleteForms::operator delete;
    static void* operator new(size_t size, ostream& logStream) throw(bad_alloc);
    static void operator delete(void* pMemory, ostream& logStream) throw();
};

int main() {
    MP3Player mp;
    // mp.checkOut();
    // mp.ElectronicGadget::checkOut();
    mp.BorrowableItem::checkOut();

    DatabaseID id1;
    id1.pid = 1;
    id1.data = "Ring-tailed Lemur";
    PersonInfo pi1(id1);
    cout << pi1.theName << endl;

    Rational<int> oneHalf(1, 2);
    Rational<int> result = oneHalf * 2;

    set_new_handler(outOfMem);
    int* pBigDataArray = new int[100000000L];

    return 0;
}