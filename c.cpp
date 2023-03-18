#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // int n;
    // cin >> n;
    // int64_t l = 1, r = 1e9, mid, res = -1;
    // while (l <= r) {
    //     mid = (r + l) >> 1;
    //     if (mid * (mid + 1) / 2 <= n) {
    //         res = mid;
    //         l = mid + 1;
    //     }
    //     else {
    //         r = mid - 1;
    //     }
    // }
    // cout << res << '\n';
    // int n;
    // cin >> n;
    // int64_t l = 1, r = 1e9, mid, res = -1;
    // while (l <= r) {
    //     mid = (r + l) >> 1;
    //     if (mid * (2 * mid + 1) * (mid + 1) / 6 <= n) {
    //         res = mid;
    //         l = mid + 1;
    //     }
    //     else {
    //         r = mid - 1;
    //     }
    // }
    // cout << res << '\n';
    // string s;
    // cin >> s;
    // auto checkPalin = [&](string s) {
    //     int n = s.size();
    //     for (int i = 0; i < n / 2; ++i) {
    //         if (s[i] != s[n - i - 1]) {
    //             return "NO\n";
    //         }
    //     }
    //     return "YES\n";
    // };
    // cout << checkPalin(s);
    // int n;
    // cin >> n;
    // int a[n + 1];
    // for (int i = 1; i <= n; ++i) {
    //     cin >> a[i];
    // }

    // for (int i = 1; i <= n; ++i) {
    //     cout << a[i] << ' ';
    // }

    // cout << '\n';

    // for (int i = 1; i <= n / 2; ++i) {
    //     swap(a[i], a[n - i + 1]);
    // }

    // for (int i = 1; i <= n; ++i) {
    //     cout << a[i] << ' ';
    // }
    // cout << '\n';
    int n, q, l, r;
    cin >> n >> q;
    int dp[n + 1][5];
    memset(dp, 0x0, sizeof(dp));
    for (int i = 1, x; i <= n; ++i) {
        cin >> x;
        dp[i][x] = 1;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 3; ++j) {
            dp[i][j] += dp[i - 1][j];
        }
    }

    for (int i = 1; i <= q; ++i) {
        cin >> l >> r;
        for (int j = 1; j <= 3; ++j) {
            cout << dp[r][j] - dp[l - 1][j] << (j == 3 ? '\n' : ' ');
        }
    }
}