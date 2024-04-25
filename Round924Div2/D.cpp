#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#define all(x) x.begin(), x.end()
typedef int64_t ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;
typedef double db;
typedef long double ldb;
const int maxn = 2e5 + 5;
int n, b, x;
int c[maxn];
ll sum[maxn], add[maxn];
ll calculate(int squad, int num) {
    ll average = num / squad;
    ll oneMore = num % squad;
    return b * (1ll * num * num - (squad - oneMore) * average * average -
                oneMore * (average + 1) * (average + 1)) / 2;
}
// 不能三分，不是凸函数
void solve() {
    int max = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= c[i]; ++j) {
            sum[j] += calculate(j, c[i]);
        }
        add[c[i] + 1] += calculate(c[i], c[i]);
        max = std::max(c[i], max);
    }
    ll res = 0;
    for (int i = 1; i <= max; ++i) {
        add[i] += add[i - 1];
        res = std::max(res, add[i] + sum[i] - 1ll * (i - 1) * x);
    }
    std::cout << res << '\n';
    for (int i = 1; i <= max + 1; ++i)  {
        add[i] = 0;
        sum[i] = 0;
    }
}
int main() {
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    std::cin >> T;
    while (T--) {
        std::cin >> n >> b >> x;
        for (int i = 1; i <= n; ++i) {
            std::cin >> c[i];
        }
        solve();
    }

    return 0;
}