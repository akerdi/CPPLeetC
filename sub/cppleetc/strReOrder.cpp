#include <iostream>
#include <vector>
#include <map>

using namespace std;
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <boost/foreach.hpp>

#include "strReOrder.h"

void split_func(string& str, vector<string>& strs) {
    boost::split(strs, str, boost::is_any_of(" "));
}

class AscdSort {
public:
    bool operator()(int a, int b) {
        return a < b;
    }
};

class StringCountSort {
public:
    bool operator()(pair<string, uint32_t> a, pair<string, uint32_t> b) {
        if (a.second > b.second) return true;
        else if (a.second == b.second) {
            return a.first.length() < b.first.length();
        } else return false;
    }
};

// 某个单词字符串排序
void strSort(string& str) {
    vector<char> littleVector;
    vector<char> upperVector;
    char c, a = 'a';
    uint32_t index = 0;
    for (uint32_t i = 0; i < str.length(); i++) {
        c = str.at(i);
        if (c >= a) {
            littleVector.push_back(c);
        } else {
            upperVector.push_back(c);
        }
    }
    sort(upperVector.begin(), upperVector.end(), AscdSort());
    sort(littleVector.begin(), littleVector.end(), AscdSort());

    BOOST_FOREACH(const char& s, upperVector) {
        str[index] = s;
        index++;
    }
    BOOST_FOREACH(const char& s, littleVector) {
        str[index] = s;
        index++;
    }
}

void strsSort(vector<string>& strs) {
    int index = 0;
    BOOST_FOREACH(string& s, strs) {
        strSort(s);
        strs[index] = s;
        index++;
    }
}
void strReOrder(string& str) {
    vector<string> strs;
    split_func(str, strs);
    strsSort(strs);

    map<string, uint32_t> amap;
    for (int i = 0; i < strs.size(); i++) {
        if (amap.count(strs[i])) {
            amap[strs[i]] += 1;
        } else amap[strs[i]] = 1;
    }
    vector<pair<string, uint32_t> > amapPair;
    for (auto x : amap) {
        amapPair.push_back(x);
    }
    sort(amapPair.begin(), amapPair.end(), StringCountSort());
    for (int i = 0; i < amapPair.size(); i++) {
        string& s = amapPair[i].first;
        for (int j = 0; j < amapPair[i].second; j++) {
            cout << amapPair[i].first << " ";
        }
    }
    cout << endl;
}

void test() {
    string str = "This is an apple";
    strReOrder(str);

    str = "My sister is in the house not in the yard";
    strReOrder(str);
}

void exec_strReOrder() {
    test();
}
