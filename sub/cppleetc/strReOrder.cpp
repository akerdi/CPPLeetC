#include <iostream>

using namespace std;

#include "strReOrder.h"



void strReOrder(string& str) {
    str = "reordered";
}

void exec_strReOrder() {
    string str = "This is an apple";

    strReOrder(str);
    cout << __func__ << ": " << str << endl;
}