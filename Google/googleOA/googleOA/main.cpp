//
//  main.cpp
//  googleOA
//
//  Created by Don‘t open when alone on 11/16/16.
//  Copyright © 2016 Chen LI. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

string deletedash(string s) {
    string res = "";
    for (auto c : s) {
        if (c != '-') {
            if (c>='a' && c<='z')
                res += toupper(c);
            else
                res += c;
        }
    }
    return res;
}

string input(string s, int k) {
    if (s == "" || k == 0) return "";
    string temp = deletedash(s);
    string ans = "";
    int size = (int)temp.size();
    int firstPart = size % k;
    ans += temp.substr(0, firstPart);
    for (int i=firstPart; i<=size-k; i+=k) {
        if (i == firstPart && ans!= "") ans += '-';
        if (i != size-k) ans += temp.substr(i, k) + '-';
        else ans += temp.substr(i, k);
    }
    return ans;
}


int main() {
    cout << input("aa-a-aAAA--123--Aaaabbb--aefaewffeBBB", 100) << endl;
    
    return 0;
}
