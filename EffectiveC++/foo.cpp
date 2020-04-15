#include "foo.h"

#include <iostream>
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

    return 0;
}
