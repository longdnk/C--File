#include "bits/stdc++.h"
using namespace std;
const int maxn = 1e6 + 9;
string n, r;

auto findSum = [](string str1, string str2) -> string {
    if (str1.length() > str2.length())
        swap(str1, str2);

    string str = "";

    int n1 = str1.length(), n2 = str2.length();

    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    int carry = 0;
    for (int i = 0; i < n1; ++i) {
        int sum = ((str1[i] - '0') + (str2[i] - '0') + carry);
        str.push_back(sum % 10 + '0');

        carry = sum / 10;
    }

    for (int i = n1; i < n2; ++i) {
        int sum = ((str2[i] - '0') + carry);
        str.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    if (carry)
        str.push_back(carry + '0');

    reverse(str.begin(), str.end());

    return str;
};

auto isValid = [](string s) -> bool {
    string r = s;
    reverse(r.begin(), r.end());
    return s == r;
};

string operator+(string s1, string s2) {
    return findSum(s1, s2);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    while (!isValid(n)) {
        r = n;
        reverse(r.begin(), r.end());
        n = n + r;
    }
    cout << n << '\n';
}