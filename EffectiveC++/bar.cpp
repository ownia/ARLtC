#include <iostream>

using namespace std;

class Investment {};
Investment* createInvestment();
void f() {
    Investment* pInv = createInvestment();
    delete pInv;
}
