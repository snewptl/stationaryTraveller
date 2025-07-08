#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <assert.h>
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
ll a[maxn], b[maxn];
ll sum[2];
bool solve() {
    if (sum[0] == sum[1]) {
        ll last = a[1];
        for (int i = 2; i <= n; ++i) {
            if (a[i] < last) return false;
            last = a[i] - last;
        }
        return true;
    } else {
        for (int i = 1; i <= n; ++i) {
            b[i] = a[i] - b[i - 1];
        }
        for (int i = 1; i < n; ++i) {
            if (sum[i % 2] - sum[(i % 2) ^ 1] == 2 * (a[i] - a[i + 1])) {
                if (a[i + 1] - b[i - 1] < 0) continue;
                if (a[i] - b[i] < 0) continue;
                std::swap(a[i], a[i + 1]);
                ll last = a[1];
                for (int j = 2; j <= n; ++j) {
                    if (a[i] < last) return false;
                    last = a[i] - last;
                }
                return true;
            }
        }
        return false;
    }
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        for (int i = 0; i < 2; ++i) sum[i] = 0;
        for (int i = 1; i <= n; ++i) {
            std::cin >> a[i];
            sum[i % 2] += a[i];
        }
        std::cout << (solve() ? "YES\n" : "NO\n");
    }

    return 0;
}

// 16 : 34 - 17 : 11 - 37min 
// 18 : 17 - 18 : 26 - 19min