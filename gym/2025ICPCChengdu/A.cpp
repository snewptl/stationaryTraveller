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
int n, d[maxn], final[maxn];
ll sum = 0;
bool solve() {
    if (sum <= 100) {
        ll tot = 200 * 2000;
        ll cur = tot;
        for (int i = 1; i <= n; ++i) {
            final[i] = tot / 100 * d[i];
            cur -= final[i];
        }
        for (int i = 1; i <= n; ++i) {
            ll max = tot / 200 - 1;
            ll temp = std::min(max, cur);
            final[i] += temp;
            cur -= temp;
        }
        if (cur) return false;
    } else {
        ll tot = 200;
        ll cur = tot;
        for (int i = 1; i <= n; ++i) {
            final[i] = tot / 100 * d[i];
            cur -= final[i];
        }
        for (int i = 1; i <= n; ++i) {
            if (!final[i]) continue;
            ll max = tot / 200;
            ll temp = std::min(max, -cur);
            final[i] -= temp;
            cur += temp;
        }
        if (cur) return false;
    }
    std::cout << "YES\n";
    for (int i = 1; i <= n; ++i) {
        std::cout << final[i] << ' ';
    }
    std::cout << '\n';
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
        sum = 0;
        for (int i = 1; i <= n; ++i) {
            std::cin >> d[i];
            sum += d[i];
        }
        if (!solve()) std::cout << "NO\n";
    }

    return 0;
}
