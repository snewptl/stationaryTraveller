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
int n, q;
ll x[maxn];
ll pre[maxn];
ll sq[maxn];
int main() {
    #ifndef ONLINE_JUDGE
    freopen("0_input.txt", "r", stdin);
    // freopen("0_output.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T = 1;
    while (T--) {
        std::cin >> n >> q;
        for (int i = 1; i <= n; ++i) {
            std::cin >> x[i];
            pre[i] = pre[i - 1] + x[i];
            sq[i] = sq[i - 1] + x[i] * x[i];
        }
        while (q--) {
            int l, r;
            ll S;
            std::cin >> l >> r >> S;
            if (S >= (pre[r] - pre[l - 1])) {
                ll ans = ((pre[r] - pre[l - 1]) * (pre[r] - pre[l - 1]) - (sq[r] - sq[l - 1])) / 2 + (pre[r] - pre[l - 1]) * (S - (pre[r] - pre[l - 1]));
                std::cout << ans << '\n';
            } else {
                std::cout << "-1\n";
            }
        }
    }

    return 0;
}
