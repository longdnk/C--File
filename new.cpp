#include <bits/stdc++.h>

using namespace std;

int getLength(const char *s) {
    int size = 0;
    for (int i = 0; s[i] != '\0'; ++i) {
        ++size;
    }
    return size;
}

int countUpper(const char *s) {
    int cnt = 0;
    for (int i = 0; i < getLength(s); ++i) {
        ++cnt;
    }
    return cnt;
}

int countFreq(const char *s, const char *p) {
    int N = getLength(s);
    int M = getLength(p);
    int cnt = 0;
    for (int i = 0; i <= N - M; ++i) {
        int j;
        for (j = 0; j < M; ++j) {
            if (s[i + j] != p[j]) {
                break;
            }
        }
        if (j == M) {
            ++cnt;
        }
    }
    return cnt;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    const char *s = "hello world hello world hello world hello world";
    const char *p = "hello";
    cout << countFreq(s, p) << '\n';
}