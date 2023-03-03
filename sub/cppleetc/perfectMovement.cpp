#include <iostream>
#include <map>
#include <vector>
using namespace std;

#include "perfectMovement.h"

typedef pair<char, uint32_t> MyPair;
typedef map<char,uint32_t> MyMap;
typedef vector<char> MyVector;

uint32_t perfectMovement(string& str) {
    uint32_t length = str.length();
    uint32_t wanted_pair_length = length / 4;
    MyMap amap;
    uint32_t count = 0;
    char c;
    MyMap::iterator pos;
    vector<char> keys;
    for (uint32_t i = 0; i < length; i++) {
        c = str.at(i);
        pos = amap.find(c);
        if (pos != amap.end()) {
            pos->second++;
        } else {
            amap.insert(MyPair(c, 1));
            keys.push_back(c);
        }
    }
    uint32_t fix_count = 0;
    MyVector::iterator pBegin = keys.begin();
    MyVector::iterator pEnd = keys.end();
    while (pBegin != pEnd) {
        c = *pBegin;
        pos = amap.find(c);
        if (pos != amap.end()) {
            if (pos->second > wanted_pair_length) {
                fix_count += (pos->second - wanted_pair_length);
            }
        }
        pBegin++;
    }
    return fix_count;
}

void exec_perfectMovement() {
    cout << "perfectMovement" << endl;
    string a = string("WASDAASD");
    uint32_t res = perfectMovement(a);
    cout << __func__ << ": " << res << endl;
}
