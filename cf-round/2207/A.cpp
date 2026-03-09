#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <assert.h>
#include <memory.h>
#include <cmath>
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 2e5 + 5;
const ll mod = 998244353;
int n;
std::string s, t1, t2;
int count(std::string &s) {
    int res = 0;
    for (int i = 0; i < n; ++i) {
        res += (s[i] == '1');
    }
    return res;
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n >> s;
        t2 = s;
        for (int i = 0; i <= n - 3; ++i) {
            if (t2[i] == '1' && t2[i + 2] == '1') t2[i + 1] = '1';
        }
        t1 = t2;
        for (int i = 0; i <= n - 3; ++i) {
            if (t1[i] == '1' && t1[i + 2] == '1') t1[i + 1] = '0';
        }
        std::cout << count(t1) << ' ' << count(t2) << '\n';
    }

    return 0;
}
