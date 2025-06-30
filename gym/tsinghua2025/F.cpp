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
int n, a[maxn], b[maxn];
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    // std::cin >> T;
    while (T--) {
        std::cin >> n;
        for (int i = 1; i <= n; ++i) std::cin >> a[i];
        std::sort(a + 1, a + n + 1);
        for (int i = n; i >= 1; --i) a[i + 1] = a[i];
        a[1] = a[n + 1];
        std::set<int> s;
        for (int i = 0; i <= n; ++i) s.insert(i);
        for (int i = 1; i <= n; ++i) {
            s.erase(a[i]);
            b[i] = *s.begin();
        }
        s.clear();
        for (int i = 0; i <= n; ++i)s.insert(i);
        for (int i = 1; i <= n; ++i) {
            s.erase(b[i]);
        }      
        std::cout << *s.begin() << '\n';
    }

    return 0;
}
