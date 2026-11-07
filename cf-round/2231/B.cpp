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
int a[maxn], b[maxn];
int l = n, r = 0;
bool solve() {
    int fin = 1e9;
    int cur = -1e9;
    for (int i = l + 1; i <= r; ++i) {
        if (b[i] < 0) {
            fin = std::min(cur, fin);
            cur = -1e9;
        } else {
            cur = std::max(cur, b[i]);
        }
    }
    for (int i = l; i <= r; ++i) {
        if (b[i] < 0) {
            if (fin + b[i] < 0) return false;
        }
    }
    return true;
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
        std::cin >> n;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
        }
        l = n, r = 0;
        for (int i = 1; i < n; ++i) {
            b[i] = a[i + 1] - a[i];
            if (b[i] < 0) l = std::min(l, i), r = std::max(r, i);
        }
        if (solve()) std::cout << "YES\n";
        else std::cout << "NO\n";

    }

    return 0;
}
