#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        const int N = 10005; // max constraint

        bitset<N> x(a);
        bitset<N> y(b);

        while (y.any()) {
            bitset<N> carry = (x & y) << 1;
            x = x ^ y;
            y = carry;
        }

        string res = x.to_string();

        // remove leading zeros
        int i = 0;
        while (i < res.size() - 1 && res[i] == '0') i++;

        return res.substr(i);
    }
};